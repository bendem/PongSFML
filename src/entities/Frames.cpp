#include "entities/Frames.hpp"

Frames::Frames(sf::Font& f, unsigned int x, unsigned int y)
        : Entity(Front), text("0", f, 25) {
    this->text.setColor(sf::Color(255, 255, 255, 200));
    this->text.setPosition(x, y);
}

void Frames::tick(unsigned long frameLived) {
    this->text.setString(std::to_string(frameLived));
}

void Frames::draw(sf::RenderWindow& window) {
    window.draw(this->text);
}
