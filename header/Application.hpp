#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

#include <chrono>
#include <iostream>
#include <set>
#include <string>
#include <thread>

#include "EventManager.hpp"
#include "GameState.hpp"
#include "GameUpdater.hpp"
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

    Application& registerEntity(Entity*);
    void start(unsigned long);

private:
    sf::RenderWindow window;
    GameState state;
    Renderer renderer;
    EventManager eventManager;
    GameUpdater gameUpdater;

    sf::Int64 cloneTime;
    sf::Int64 renderTime;
    sf::Int64 frameTime;
    sf::Int64 totalTime;
    sf::Int64 waitTime;

    unsigned long frameLived;

    void setup();

    friend class Renderer;
    friend class EventManager;

};

#endif
