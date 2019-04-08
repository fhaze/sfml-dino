//
// Created by fhaze on 19/04/08.
//

#include "obstacle-generator.h"
#include <math.h>

ObstacleGenerator::ObstacleGenerator(Player &ref_player) : player(ref_player) {
}

void ObstacleGenerator::add(sf::Vector2f vec2f) {
    float multiplier = clock.getElapsedTime().asSeconds();
    Obstacle obstacle(500 + multiplier * 10);
    obstacle.setPosition(vec2f);
    self.push_back(obstacle);
}

void ObstacleGenerator::spawn() {
    float time = spawnClock.getElapsedTime().asSeconds();
    if (time > 1) {
        spawnClock.restart();
        add(sf::Vector2f(800, 200 + rand() % 150));
    }
}

void ObstacleGenerator::update(float dt) {
    if (player.isGameOver()) {
        return;
    }

    spawn();

    for (auto it = self.begin(); it != self.end();) {
        it->update(dt);
        if (it->getGlobalBounds().intersects(player.getGlobalBounds())) {
            player.kill();
        }
        if (it->getPosition().x < -50) {
            it = self.erase(it);
        } else {
            ++it;
        }
    }
}

void ObstacleGenerator::draw(sf::RenderWindow &render) {
    for (auto & it : self) {
        it.draw(render);
    }
}