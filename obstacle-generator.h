//
// Created by fhaze on 19/04/08.
//

#ifndef SFML_DINO_OBSTACLE_GENERATOR_H
#define SFML_DINO_OBSTACLE_GENERATOR_H

#include <list>
#include <SFML/Graphics/RenderWindow.hpp>
#include "obstacle.h"

using namespace std;

class ObstacleGenerator {
private:
    list <Obstacle> self;
    sf::Clock clock;
    void add(sf::Vector2f vec2f);
public:
    void spawn();
    void update(float dt);
    void draw(sf::RenderWindow &render);
};


#endif //SFML_DINO_OBSTACLE_GENERATOR_H
