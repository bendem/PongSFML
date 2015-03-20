#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <SFML/Graphics.hpp>

#include <set>

#include "entities/Entity.hpp"

class EventManager {

public:
    EventManager(sf::RenderWindow&, const std::multiset<Entity*, Entity::ByPriority>&);

    void tick(unsigned long);
    void update();

    bool done() const { return this->shouldClose; }

private:
    sf::RenderWindow& window;
    const std::multiset<Entity*, Entity::ByPriority>& entities;
    bool shouldClose;

};

//std::function<bool(int, int, int)> isAround = [](int x1, int x2, int precision) -> bool {
//    return x1 > x2 - precision && x1 < x2 + precision;
//};

#endif
