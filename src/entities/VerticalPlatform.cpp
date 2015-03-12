#include "entities/VerticalPlatform.hpp"

VerticalPlatform::VerticalPlatform(const sf::Vector2u& bounds, Position position,
        sf::Keyboard::Key up, sf::Keyboard::Key down)
        : Platform(bounds, position), up(up), down(down),
          isKeyUpDown(false), isKeyDownDown(false) {
}

void VerticalPlatform::tick(unsigned long frameLived) {
    if(frameLived % 2 != 0) { // Check if there is something less costly than modulo
        return;
    }

    // None are down or both are down
    if(!(isKeyUpDown ^ isKeyDownDown)) {
        return;
    }

    sf::Vector2f pos(platform.getPosition());
    if(isKeyUpDown) {
        if(!bounds.contains(pos.x, pos.y - JUMP_SIZE)) {
            platform.setPosition(pos.x, bounds.top);
        } else {
            platform.move(0, -JUMP_SIZE);
        }
    } else if(isKeyDownDown) {
        if(!bounds.contains(pos.x, pos.y + JUMP_SIZE + platform.getSize().y)) {
            platform.setPosition(pos.x, bounds.height - platform.getSize().y);
        } else {
            platform.move(0, JUMP_SIZE);
        }
    }
}

void VerticalPlatform::update(const sf::Event& event) {
    if(event.type != sf::Event::KeyPressed && event.type != sf::Event::KeyReleased) {
        return;
    }
    if(event.key.code == up) {
        isKeyUpDown = event.type == sf::Event::KeyPressed;
    } else if(event.key.code == down) {
        isKeyDownDown = event.type == sf::Event::KeyPressed;
    }
}
