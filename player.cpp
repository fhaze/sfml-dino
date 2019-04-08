//
// Created by fhaze on 19/04/08.
//

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "player.h"

Player::Player() {
    self = sf::RectangleShape(sf::Vector2f(50, 80));
    self.setFillColor(sf::Color::Green);
    self.setPosition(START_POSITION_X, START_POSITION_Y);
    ySpeed = 0;
    isJumping = false;
}

void Player::jump(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
        isJumping = true;
        ySpeed = JUMP_POWER * -dt;
    }
    if (isJumping) {
        if (ySpeed < MAX_FALL_SPEED) {
            ySpeed += FALL_SPEED * dt;
        } else {
            ySpeed = MAX_FALL_SPEED;
        }

        if (self.getPosition().y + ySpeed > START_POSITION_Y) {
            isJumping = false;
            ySpeed = 0;
            self.setPosition(self.getPosition().x, START_POSITION_Y);
        }
    }
}

void Player::update(sf::RenderTarget &render, float dt) {
    jump(dt);
    self.move(0, ySpeed);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(self);
}