//
// Created by fhaze on 19/04/08.
//

#ifndef SFML_DINO_OBSTACLEGENERATOR_H
#define SFML_DINO_OBSTACLEGENERATOR_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Obstacle.h"
#include "Player.h"

using namespace std;

class ObstacleGenerator {
private:
    std::vector <Obstacle> self;
    Player &player;
    sf::Clock clock;
    sf::Clock spawnClock;
    void add(sf::Vector2f vec2f);
public:
    explicit ObstacleGenerator(Player &ref_player);
    void spawn();
    void update(float dt);
    void draw(sf::RenderWindow &render);
    void restart();
};


#endif //SFML_DINO_OBSTACLEGENERATOR_H