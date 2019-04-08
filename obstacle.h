//
// Created by fhaze on 19/04/08.
//

#ifndef SFML_DINO_OBSTACLE_H
#define SFML_DINO_OBSTACLE_H

#define SPEED 500

#include <SFML/Graphics/RectangleShape.hpp>

class Obstacle {
private:
    sf::RectangleShape self;
public:
    Obstacle();
    void setPosition(sf::Vector2f vec2f);
    sf::Vector2f getPosition();
    void update(float dt);
    void draw(sf::RenderWindow &render);
};


#endif //SFML_DINO_OBSTACLE_H
