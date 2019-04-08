//
// Created by fhaze on 19/04/08.
//

#ifndef SFML_DINO_OBSTACLE_H
#define SFML_DINO_OBSTACLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Obstacle {
private:
    sf::RectangleShape self;
    sf::Image spritesheet;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock animClock;
    float speed;
    void animation();
public:
    explicit Obstacle(float speed);
    void setPosition(sf::Vector2f vec2f);
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    void update(float dt);
    void draw(sf::RenderWindow &render);
};


#endif //SFML_DINO_OBSTACLE_H
