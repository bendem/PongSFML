#include "EventManager.hpp"

EventManager::EventManager(sf::RenderWindow& window, const std::multiset<Entity*, Entity::ByPriority>& entities)
    : window(window), entities(entities) {
}

void EventManager::tick(unsigned long frameLived) {
    for(Entity* entity : this->entities) {
        entity->tick(frameLived);
    }
}

void EventManager::update() {
    static sf::Event event;

    while(this->window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            this->window.close();
            return;
        }

        for(Entity* entity : this->entities) {
            entity->update(event);
        }
    }
}
