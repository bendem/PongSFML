#include "entities/Entity.hpp"

Entity::Entity(Layer layer, Priority priority)
    : layer(layer), priority(priority) {
}

Entity::Entity(const Entity& p) : layer(p.layer), priority(p.priority) {
}

void Entity::tick(unsigned long) {
}

void Entity::update(const sf::Event&) {
}

void Entity::draw(sf::RenderWindow&) {
}

bool Entity::ByLayer::operator()(Entity* left, Entity* right) {
    return left->layer < right->layer;
}

bool Entity::ByPriority::operator()(Entity* left, Entity* right) {
    return left->priority < right->priority;
}
