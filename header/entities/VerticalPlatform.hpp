#ifndef VERTICAL_PLATEFORM
#define VERTICAL_PLATEFORM

#include "entities/Platform.hpp"

class VerticalPlatform : public Platform {

public:
    VerticalPlatform(const sf::Vector2u&, Position, sf::Keyboard::Key, sf::Keyboard::Key);

    void tick(unsigned long) override;
    void update(const sf::Event&) override;

private:
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    bool isKeyUpDown;
    bool isKeyDownDown;

};

#endif
