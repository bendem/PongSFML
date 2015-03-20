#include "Application.hpp"

Application::Application(std::string title)
        : window(sf::VideoMode(900, 600), title, sf::Style::Default, sf::ContextSettings(0, 0, 16)),
          state(),
          renderer(window),
          eventManager(window, state.getEntitiesByPriority()),
          gameUpdater(eventManager) {
    this->cloneTime = 0;
    this->renderTime = 0;
    this->frameLived = 0;
}

Application& Application::registerEntity(Entity* entity) {
    this->state.registerEntity(entity);
    return *this;
}

void Application::start(unsigned long fps) {
    this->setup();
    const sf::Time timePerFrame = sf::seconds(1.f/fps);

    std::cerr << "Starting application at "
        << fps << "fps / "
        << timePerFrame.asMilliseconds() << "ms per frame" << std::endl;

    sf::Clock fpsClock;
    sf::Clock profilerClock;

    while(this->window.isOpen()) {
        profilerClock.restart();

        GameState snapshot(this->state);
        this->cloneTime += (profilerClock.restart()).asMicroseconds();
        this->cloneTime /= 2;

        // Update on the game updater thread
        this->gameUpdater.update(this->frameLived);

        // while rendering on this one
        this->renderer.render(snapshot);
        this->renderTime += (profilerClock.restart()).asMicroseconds();
        this->renderTime /= 2;

        // Wait for the updates to finish in case they took more time than rendering
        this->gameUpdater.wait();
        this->frameTime += this->renderTime + (profilerClock.restart()).asMicroseconds();
        this->frameTime /= 2;

        if(this->eventManager.done()) {
            this->window.close();
            break;
        }

        this->totalTime = this->cloneTime + this->frameTime;

        ++this->frameLived;

        this->waitTime = (timePerFrame - fpsClock.restart()).asMicroseconds();
        if(this->waitTime > 0) {
            std::this_thread::sleep_for(std::chrono::microseconds(this->waitTime));
        }
    }
    this->gameUpdater.stop();
}

void Application::setup() {
    std::cerr << "Application setup start" << std::endl;

    static sf::Font f; // "static" keeps the font alive (needed since sf::Text doesn't)
    if(!f.loadFromFile("./resources/bitstream-vera-sans-mono.roman.ttf")) {
        throw std::runtime_error("Could not load font");
    }

    this->registerEntity(new HorizontalPlatform(window.getSize(), Platform::Top, sf::Keyboard::Left, sf::Keyboard::Right));
    this->registerEntity(new VerticalPlatform(window.getSize(), Platform::Left, sf::Keyboard::Z, sf::Keyboard::S));
    this->registerEntity(new HorizontalPlatform(window.getSize(), Platform::Bottom, sf::Keyboard::Numpad4, sf::Keyboard::Numpad6));
    this->registerEntity(new VerticalPlatform(window.getSize(), Platform::Right, sf::Keyboard::O, sf::Keyboard::L));

    this->registerEntity(new Frames(f, 10, this->window.getSize().y - 35));
    this->registerEntity(new Ball(window.getSize(), sf::Vector2f(145, 55), sf::Vector2f(-2, -3)));
    this->registerEntity(new Ball(window.getSize(), sf::Vector2f(345, 55), sf::Vector2f(2, -15)));
    this->registerEntity(new Ball(window.getSize(), sf::Vector2f(845, 405), sf::Vector2f(-2, 3)));

    this->registerEntity(new Counter(L"clone:  ", this->cloneTime, sf::Vector2f(50, 50), f));
    this->registerEntity(new Counter(L"render: ", this->renderTime, sf::Vector2f(50, 75), f));
    this->registerEntity(new Counter(L"frame:  ", this->frameTime, sf::Vector2f(50, 100), f));
    this->registerEntity(new Counter(L"total:  ", this->totalTime, sf::Vector2f(50, 125), f));
    this->registerEntity(new Counter(L"wait:   ", this->waitTime, sf::Vector2f(50, 160), f));

    this->renderer.setBackground(sf::Color(20, 20, 20));

    std::cerr << "Application setup end" << std::endl;
}
