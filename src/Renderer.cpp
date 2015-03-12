#include "Renderer.hpp"

Renderer::Renderer(sf::RenderWindow& window, const std::multiset<Entity*, Entity::ByLayer>& entities)
    : window(window), entities(entities) {
}

Renderer& Renderer::setBackground(const sf::Color& color) {
    this->bgColor = color;
    return *this;
}

void Renderer::render() {
    this->window.clear(this->bgColor);
    for(Entity* entity : this->entities) {
        entity->draw(this->window);
    }
    this->window.display();
}
