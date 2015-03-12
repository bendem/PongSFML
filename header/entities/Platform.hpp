#ifndef PLATEFORM_HPP
#define PLATEFORM_HPP

#include "entities/Entity.hpp"

class Platform : public Entity {

public:
    enum Position {
        Top,
        Bottom,
        Left,
        Right
    };

    Platform(const sf::Vector2u&, Position);

    void draw(sf::RenderWindow&) override;

    virtual void update(const sf::Event& event) override = 0;

protected:
    sf::RectangleShape platform;
    sf::FloatRect bounds;
    Position position;

    static const int JUMP_SIZE;
    static const sf::Vector2f DEFAULT_SIZE;

};

#endif
