#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <set>
#include <vector>

#include "entities/Entity.hpp"

class GameState {

public:
    GameState() {}
    GameState(const GameState&);
    ~GameState();

    GameState& registerEntity(Entity*);
    const std::multiset<Entity*, Entity::ByLayer>& getEntitiesByLayer() const;
    std::multiset<Entity*, Entity::ByPriority>& getEntitiesByPriority();

private:
    std::vector<Entity*> entities;
    // As always, is that container really adapted to this usage (thousands of sorted iterations for each insertion)
    std::multiset<Entity*, Entity::ByLayer> entitiesByLayer;
    std::multiset<Entity*, Entity::ByPriority> entitiesByPriority;

};

#endif
