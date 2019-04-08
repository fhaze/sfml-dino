//
// Created by fhaze on 19/04/08.
//

#ifndef SFML_TUTORIAL_PLAYER_H
#define SFML_TUTORIAL_PLAYER_H

#define JUMP_POWER 2000
#define FALL_SPEED 70
#define MAX_FALL_SPEED 15
#define START_POSITION_X 100
#define START_POSITION_Y 260

#include <SFML/Graphics/RectangleShape.hpp>

class Player {
private:
    sf::RectangleShape self;
    bool isJumping;
    float ySpeed;
    void jump(float dt);
public:
    Player();
    void update(sf::RenderTarget &render, float dt);
    void draw(sf::RenderWindow &window);
};


#endif //SFML_TUTORIAL_PLAYER_H
