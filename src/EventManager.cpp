#include "EventManager.hpp"

EventManager::EventManager(sf::RenderWindow& window, const std::multiset<Entity*, Entity::ByPriority>& entities)
    : window(window), entities(entities), shouldClose(false) {
}

void EventManager::tick(unsigned long frameLived) {
    for(Entity* entity : this->entities) {
        entity->tick(frameLived);
    }
}

void EventManager::update() {
    static sf::Event event;

    while(this->window.pollEvent(event)) {
        if(event.type == sf::Event::Closed
                || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Q)) {
            this->shouldClose = true;
            return;
        }

        for(Entity* entity : this->entities) {
            entity->update(event);
        }
    }
}
