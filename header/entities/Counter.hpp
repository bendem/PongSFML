#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "entities/Entity.hpp"

class Counter : public Entity {

public:
    Counter(const std::wstring&, const sf::Int64& number, const sf::Vector2f&, const sf::Font&);

    void tick(unsigned long) override;
    void draw(sf::RenderWindow&) override;

private:
    sf::Text text;
    std::wstring prefix;
    const sf::Int64& number;

};

#endif
