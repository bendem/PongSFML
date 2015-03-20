#include "GameState.hpp"

GameState::GameState(const GameState& p) {
    for(Entity* entity : p.entities) {
        this->registerEntity(entity->clone());
    }
}

GameState::~GameState() {
    for(Entity* entity : this->entities) {
        delete entity;
    }
}


GameState& GameState::registerEntity(Entity* entity) {
    this->entities.push_back(entity);
    this->entitiesByLayer.insert(entity);
    this->entitiesByPriority.insert(entity);
    return *this;
}

const std::multiset<Entity*, Entity::ByLayer>& GameState::getEntitiesByLayer() const {
    return this->entitiesByLayer;
}

std::multiset<Entity*, Entity::ByPriority>& GameState::getEntitiesByPriority() {
    return this->entitiesByPriority;
}
