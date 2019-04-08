//
// Created by fhaze on 19/04/08.
//

#include "obstacle.h"

Obstacle::Obstacle() {
    me = sf::RectangleShape(sf::Vector2f(50, 50));
    me.setFillColor(sf::Color::Red);
}

void Obstacle::draw(sf::RenderTarget &render) {

}

void Obstacle::update(sf::RenderTarget &render, float dt) {

}