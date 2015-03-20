#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>

#include <set>

#include "GameState.hpp"
#include "entities/Entity.hpp"

class Renderer {

public:
    Renderer(sf::RenderWindow&);

    Renderer& setBackground(const sf::Color&);

    void render(const GameState&);

private:
    sf::RenderWindow& window;
    sf::Color bgColor;

};

#endif
