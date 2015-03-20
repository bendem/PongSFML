#ifndef HORIZONTAL_PLATEFORM
#define HORIZONTAL_PLATEFORM

#include "entities/Platform.hpp"

class HorizontalPlatform : public Platform {

public:
    HorizontalPlatform(const sf::Vector2u&, Position, sf::Keyboard::Key, sf::Keyboard::Key);
    HorizontalPlatform(const HorizontalPlatform&);

    void tick(unsigned long) override;
    void update(const sf::Event&) override;

    Entity* clone() const override { return new HorizontalPlatform(*this); }

private:
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    bool isKeyLeftDown;
    bool isKeyRightDown;

};

#endif
