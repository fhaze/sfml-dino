#include <SFML/Graphics.hpp>
#include "player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600), "SFML Dino");
    window.setVerticalSyncEnabled(true);

    sf::Event event;
    sf::Clock clock;

    Player player;

    while (window.isOpen()) {
        sf::Time time = clock.restart();
        float dt = time.asSeconds();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                window.close();
        }

        player.update(window, dt);

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}