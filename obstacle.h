//
// Created by fhaze on 19/04/08.
//

#ifndef SFML_DINO_OBSTACLE_H
#define SFML_DINO_OBSTACLE_H

#include <SFML/Graphics/RectangleShape.hpp>

class Obstacle {
private:
    sf::RectangleShape self;
    float speed;
public:
    explicit Obstacle(float speed);
    void setPosition(sf::Vector2f vec2f);
    sf::Vector2f getPosition();
    void update(float dt);
    void draw(sf::RenderWindow &render);
};


#endif //SFML_DINO_OBSTACLE_H
