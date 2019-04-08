#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ObstacleGenerator.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "SFML Dino");
    window.setVerticalSyncEnabled(true);

    sf::Event event{};
    sf::Clock dtClock;
    sf::Clock clock;

    Player player;
    ObstacleGenerator obstacleGenerator(player);

    sf::Image bg;
    bg.loadFromFile("assets/bg.png");
    sf::Texture bgTexture;
    bgTexture.loadFromImage(bg, sf::IntRect(0, 0, 800, 600));
    sf::Sprite bgSprite;
    bgSprite.setTexture(bgTexture);

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
        window.draw(bgSprite);

        obstacleGenerator.draw(window);
        player.draw(window);

        window.display();
    }

    return 0;
}