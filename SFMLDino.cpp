#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ObstacleGenerator.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "SFML Dino");
    window.setVerticalSyncEnabled(true);

    sf::Event event;
    sf::Clock dtClock;
    sf::Clock clock;

    Player player;
    ObstacleGenerator obstacleGenerator(player);

    while (window.isOpen()) {
        sf::Time dtTime = dtClock.restart();

        float dt = dtTime.asSeconds();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        if (player.isGameOver() && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            player.restart();
            obstacleGenerator.restart();
        }

        obstacleGenerator.update(dt);
        player.update(window, dt);

        window.clear();

        obstacleGenerator.draw(window);
        player.draw(window);

        window.display();
    }

    return 0;
}