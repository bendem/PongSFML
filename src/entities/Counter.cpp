#include "entities/Counter.hpp"

Counter::Counter(const std::wstring& prefix, const sf::Int64& number, const sf::Vector2f& position, const sf::Font& font)
        : text("0", font, 20), prefix(prefix), number(number) {
    this->text.setPosition(position);
    this->text.setColor(sf::Color(255, 255, 255, 200));
}

Counter::Counter(const Counter& p) : text(p.text), prefix(p.prefix), number(p.number) {
}

void Counter::tick(unsigned long frameLived) {
    if(!(frameLived & 7)) {
        this->text.setString(prefix + std::to_wstring(this->number));
    }
}

void Counter::draw(sf::RenderWindow& window) {
    window.draw(this->text);
}
