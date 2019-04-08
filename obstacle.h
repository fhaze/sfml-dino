//
// Created by fhaze on 19/04/08.
//

#ifndef SFML_DINO_OBSTACLE_H
#define SFML_DINO_OBSTACLE_H


#include <SFML/Graphics/RectangleShape.hpp>

class Obstacle {
private:
    sf::RectangleShape me;
public:
    Obstacle();
    void update(sf::RenderTarget &render, float dt);
    void draw(sf::RenderTarget &render);
};


#endif //SFML_DINO_OBSTACLE_H
