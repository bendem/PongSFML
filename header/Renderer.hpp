#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>

#include <set>

#include "entities/Entity.hpp"

class Renderer {

public:
    Renderer(sf::RenderWindow& window, const std::multiset<Entity*, Entity::ByLayer>& entities);

    Renderer& setBackground(const sf::Color&);

    void render();

private:
    sf::RenderWindow& window;
    const std::multiset<Entity*, Entity::ByLayer>& entities;
    sf::Color bgColor;

};

#endif
