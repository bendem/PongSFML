#ifndef VERTICAL_PLATEFORM
#define VERTICAL_PLATEFORM

#include "entities/Platform.hpp"

class VerticalPlatform : public Platform {

public:
    VerticalPlatform(const sf::Vector2u&, Position, sf::Keyboard::Key, sf::Keyboard::Key);
    VerticalPlatform(const VerticalPlatform&);

    void tick(unsigned long) override;
    void update(const sf::Event&) override;

    Entity* clone() const override { return new VerticalPlatform(*this); }

private:
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    bool isKeyUpDown;
    bool isKeyDownDown;

};

#endif
