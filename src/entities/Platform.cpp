#include "entities/Platform.hpp"

const int Platform::JUMP_SIZE = 15;
const sf::Vector2f Platform::DEFAULT_SIZE = sf::Vector2f(15, 150);

Platform::Platform(const sf::Vector2u& size, Position position)
        : bounds(15, 15, size.x - 15, size.y - 15),
          position(position) {
    // Set size
    sf::Vector2f rSize(DEFAULT_SIZE);
    if(position == Top || position == Bottom) {
        std::swap(rSize.x, rSize.y);
    }
    this->platform.setSize(rSize);

    // Set position
    sf::Vector2f pos(
        bounds.width / 2 - rSize.x / 2,
        bounds.height / 2 - rSize.y / 2
    );
    switch(position) {
        case Top:
            pos.y = bounds.top;
            break;
        case Bottom:
            pos.y = bounds.height - rSize.y;
            break;
        case Left:
            pos.x = bounds.left;
            break;
        case Right:
            pos.x = bounds.width - rSize.x;
            break;
    }
    this->platform.setPosition(pos);

    // Set decorations
    this->platform.setOutlineColor(sf::Color(60, 60, 60));
    this->platform.setOutlineThickness(-2);
}

Platform::Platform(const Platform& p) : platform(p.platform), bounds(p.bounds), position(p.position) {
}

void Platform::draw(sf::RenderWindow& window) {
    window.draw(this->platform);
}
