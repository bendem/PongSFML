#include "entities/HorizontalPlatform.hpp"

HorizontalPlatform::HorizontalPlatform(const sf::Vector2u& bounds, Position position,
        sf::Keyboard::Key left, sf::Keyboard::Key right)
        : Platform(bounds, position), left(left), right(right),
          isKeyLeftDown(false), isKeyRightDown(false) {
}

HorizontalPlatform::HorizontalPlatform(const HorizontalPlatform& p)
    : Platform(p), left(p.left), right(p.right), isKeyLeftDown(p.isKeyLeftDown), isKeyRightDown(p.isKeyRightDown) {
}

void HorizontalPlatform::tick(unsigned long frameLived) {
    if(frameLived & 1) { // Every two frames
        return;
    }

    // None are down or both are down
    if(!(isKeyLeftDown ^ isKeyRightDown)) {
        return;
    }

    sf::Vector2f pos(this->platform.getPosition());
    if(isKeyLeftDown) {
        if(!bounds.contains(pos.x - JUMP_SIZE, pos.y)) {
            platform.setPosition(bounds.left, pos.y);
        } else {
            platform.move(-JUMP_SIZE, 0);
        }
    } else if(isKeyRightDown) {
        if(!bounds.contains(pos.x + JUMP_SIZE + platform.getSize().x, pos.y)) {
            platform.setPosition(bounds.width - platform.getSize().x, pos.y);
        } else {
            platform.move(JUMP_SIZE, 0);
        }
    }
}

void HorizontalPlatform::update(const sf::Event& event) {
    if(event.type != sf::Event::KeyPressed && event.type != sf::Event::KeyReleased) {
        return;
    }

    if(event.key.code == left) {
        isKeyLeftDown = event.type == sf::Event::KeyPressed;
    } else if(event.key.code == right) {
        isKeyRightDown = event.type == sf::Event::KeyPressed;
    }
}
