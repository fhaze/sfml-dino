//
// Created by fhaze on 19/04/08.
//

#include "obstacle-generator.h"
#include <math.h>

void ObstacleGenerator::add(sf::Vector2f vec2f) {
    float multiplier = clock.getElapsedTime().asSeconds();
    Obstacle obstacle(500 + multiplier * 10);
    obstacle.setPosition(vec2f);
    self.push_front(obstacle);
}

void ObstacleGenerator::spawn() {
    float time = spawnClock.getElapsedTime().asSeconds();
    if (time > 1) {
        spawnClock.restart();
        add(sf::Vector2f(800, 300));
    }
}

void ObstacleGenerator::update(float dt) {
    spawn();

    list<Obstacle> :: iterator it;
    for (it = self.begin(); it != self.end();) {
        it->update(dt);
        if (it->getPosition().x < -50) {
            it = self.erase(it);
        }
        ++it;
    }
}

void ObstacleGenerator::draw(sf::RenderWindow &render) {
    list<Obstacle> :: iterator it;
    for (it = self.begin(); it != self.end(); it++) {
        it->draw(render);
    }
}
