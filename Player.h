//
// Created by fhaze on 19/04/08.
//

#ifndef SFML_TUTORIAL_PLAYER_H
#define SFML_TUTORIAL_PLAYER_H

#define HEIGHT_STAND 80
#define HEIGHT_CROUCHING 50

#define JUMP_POWER 2000
#define FALL_SPEED 10000
#define START_POSITION_X 100
#define START_POSITION_Y 340

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class Player {
private:
    sf::RectangleShape self;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    bool isJumping;
    bool isCrouching;
    bool isAlive;
    float ySpeed;
    int score;
    void jump(float dt);
    void crouch(float dt);
    void normalise();
public:
    Player();
    sf::FloatRect getGlobalBounds();
    void kill();
    bool isGameOver();
    void update(sf::RenderTarget &render, float dt);
    void draw(sf::RenderWindow &window);
    void restart();
};


#endif //SFML_TUTORIAL_PLAYER_H
