#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

#include <chrono>
#include <iostream>
#include <set>
#include <string>
#include <thread>

#include "EventManager.hpp"
#include "Renderer.hpp"
#include "entities/Ball.hpp"
#include "entities/Counter.hpp"
#include "entities/Entity.hpp"
#include "entities/Frames.hpp"
#include "entities/HorizontalPlatform.hpp"
#include "entities/VerticalPlatform.hpp"

class Application {

public:
    Application(std::string);
    ~Application();

    Application& registerEntity(Entity*);
    void start();

private:

    static const sf::Time TIME_PER_FRAME;

    sf::RenderWindow window;
    Renderer renderer;
    EventManager eventManager;

    std::vector<Entity*> entities;
    // As always, is that container really adapted to this usage (thousands of sorted iterations for each insertion)
    std::multiset<Entity*, Entity::ByLayer> entitiesByLayer;
    std::multiset<Entity*, Entity::ByPriority> entitiesByPriority;

    sf::Int64 tickTime;
    sf::Int64 updateTime;
    sf::Int64 renderTime;
    sf::Int64 totalTime;
    sf::Int64 waitTime;

    unsigned long frameLived;

    void setup();

    friend class Renderer;
    friend class EventManager;

};

#endif
