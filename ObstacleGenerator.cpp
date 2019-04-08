//
// Created by fhaze on 19/04/08.
//

#include "ObstacleGenerator.h"
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
    float multiplier = clock.getElapsedTime().asSeconds();
    if (time > 1 - (multiplier * 0.01)) {
        spawnClock.restart();
        add(sf::Vector2f(SPAWN_X, SPAWN_Y + rand() % SPAWN_RANDOM_Y));
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
    for (auto &it : self) {
        it.draw(render);
    }
}

void ObstacleGenerator::restart() {
    clock.restart();
    spawnClock.restart();
    self = std::vector<Obstacle>();
}