#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow& window) : window(window) {
}

Renderer& Renderer::setBackground(const sf::Color& color) {
    this->bgColor = color;
    return *this;
}

void Renderer::render(const GameState& state) {
    this->window.clear(this->bgColor);
    for(Entity* entity : state.getEntitiesByLayer()) {
        entity->draw(this->window);
    }
    this->window.display();
}
