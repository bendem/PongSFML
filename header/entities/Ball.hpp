#ifndef BALL_HPP
#define BALL_HPP

#include "entities/Entity.hpp"

class Ball : public Entity {

public:
    Ball(const sf::Vector2u&, const sf::Vector2f&, const sf::Vector2f&);
    Ball(const Ball&);

    void tick(unsigned long) override;
    void draw(sf::RenderWindow&) override;

    Entity* clone() const override { return new Ball(*this); }

private:
    sf::FloatRect bounds;
    sf::CircleShape ball;
    sf::Vector2f velocity;

};

#endif
