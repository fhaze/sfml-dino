//
// Created by fhaze on 19/04/08.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include "obstacle.h"

Obstacle::Obstacle(float speed) {
    this->speed = speed;
    self = sf::RectangleShape(sf::Vector2f(50, 50));
    self.setOrigin(25, 50);
    self.setFillColor(sf::Color::Red);
}

void Obstacle::setPosition(sf::Vector2f vec2f) {
    self.setPosition(vec2f);
}

sf::Vector2f Obstacle::getPosition() {
    return self.getPosition();
}

sf::FloatRect Obstacle::getGlobalBounds() {
    return self.getGlobalBounds();
}

void Obstacle::draw(sf::RenderWindow &render) {
    render.draw(self);
}

void Obstacle::update(float dt) {
    self.move(-this->speed * dt, 0);
}