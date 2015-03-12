#ifndef BALL_HPP
#define BALL_HPP

#include "entities/Entity.hpp"

class Ball : public Entity {

public:
    Ball(const sf::Vector2u&, const sf::Vector2f&, const sf::Vector2f&);

    void tick(unsigned long) override;
    void draw(sf::RenderWindow&) override;

private:
    sf::FloatRect bounds;
    sf::CircleShape ball;
    sf::Vector2f velocity;

};

#endif
