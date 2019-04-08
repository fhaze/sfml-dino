//
// Created by fhaze on 19/04/08.
//

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Player.h"

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

    spritesheet.loadFromFile("assets/dino.png");
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

void Player::animation() {
    if (isGameOver()) {
        texture.loadFromImage(spritesheet, sf::IntRect(SPRITE_DEAD * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
    }
    else if (isJumping) {
    }
    else {
        if (isCrouching) {
            texture.loadFromImage(spritesheet, sf::IntRect(SPRITE_CROUNCH * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
        } else {
            int frame = animClock.getElapsedTime().asMilliseconds() / 100;
            int spriteFrame = SPRITE_WALK_START + frame;

            if (spriteFrame > SPRITE_WALK_END) {
                animClock.restart();
                spriteFrame = SPRITE_WALK_START;
            }
            texture.loadFromImage(spritesheet, sf::IntRect(spriteFrame * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
            sprite.setTexture(texture);
            sprite.setScale(sf::Vector2f(4, 4));
            sprite.setOrigin(12.5f, 21);
        }
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
        animation();
        return;
    }

    if (clock.getElapsedTime().asSeconds() > 1 && isAlive) {
        clock.restart();
        score += (int)(1000 * dt);
        printf("Score: %d\n", score);
    }

    crouch(dt);
    jump(dt);
    animation();

    self.move(0, ySpeed * dt);

    normalise();
}

void Player::draw(sf::RenderWindow &window) {
    sprite.setPosition(self.getPosition().x, self.getPosition().y);
    window.draw(sprite);
}

void Player::restart() {
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
