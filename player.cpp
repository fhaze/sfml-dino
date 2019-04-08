//
// Created by fhaze on 19/04/08.
//

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "player.h"

Player::Player() {
    me = sf::RectangleShape(sf::Vector2f(50, 80));
    me.setFillColor(sf::Color::Green);
    me.setPosition(START_POSITION_X, START_POSITION_Y);
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
            ySpeed += 80 * dt;
        } else {
            ySpeed = MAX_FALL_SPEED;
        }

        if (me.getPosition().y + ySpeed > START_POSITION_Y) {
            isJumping = false;
            ySpeed = 0;
            me.setPosition(me.getPosition().x, START_POSITION_Y);
        }
    }
}

void Player::update(sf::RenderTarget &render, float dt) {
    jump(dt);
    me.move(0, ySpeed);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(me);
}