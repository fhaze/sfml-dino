//
// Created by fhaze on 19/04/08.
//

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "player.h"

Player::Player() {
    self = sf::RectangleShape(sf::Vector2f(50, HEIGHT_STAND));
    self.setOrigin(25, HEIGHT_STAND);
    self.setFillColor(sf::Color::Green);
    self.setPosition(START_POSITION_X, START_POSITION_Y);
    ySpeed = 0;
    isJumping = false;
    isCrouching = false;
    isAlive = true;
    score = 0;
}

void Player::jump(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
        isJumping = true;
        ySpeed = -JUMP_POWER;
    }
    if (isJumping && !isCrouching) {
        ySpeed += FALL_SPEED * dt;
    }
}

void Player::crouch(float dt) {
    isCrouching = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    if (isCrouching) {
        if (isJumping) {
            ySpeed += (FALL_SPEED * 2) * dt;
        } else {
            self.setSize(sf::Vector2f(50, HEIGHT_CROUCHING));
            self.setOrigin(25, HEIGHT_CROUCHING);
        }
    } else {
        self.setSize(sf::Vector2f(50, HEIGHT_STAND));
        self.setOrigin(25, HEIGHT_STAND);
    }
}

void Player::normalise() {
    if (self.getPosition().y > START_POSITION_Y) {
        isJumping = false;
        ySpeed = 0;
        self.setPosition(self.getPosition().x, START_POSITION_Y);
    }
}

sf::FloatRect Player::getGlobalBounds() {
    return self.getGlobalBounds();
}

void Player::kill() {
    this->isAlive = false;
}

bool Player::isGameOver() {
    return !this->isAlive;
}

void Player::update(sf::RenderTarget &render, float dt) {
    if (isGameOver()) {
        return;
    }

    if (clock.getElapsedTime().asSeconds() > 1 && isAlive) {
        clock.restart();
        score += (int)(1000 * dt);
        printf("Score: %d\n", score);
    }

    crouch(dt);
    jump(dt);

    self.move(0, ySpeed * dt);

    normalise();
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(self);
}
