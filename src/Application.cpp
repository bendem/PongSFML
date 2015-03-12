#include "Application.hpp"

Application::Application(std::string title)
        : window(sf::VideoMode(900, 600), title, sf::Style::Default, sf::ContextSettings(0, 0, 16)),
          renderer(window, this->entitiesByLayer),
          eventManager(window, this->entitiesByPriority) {
    this->tickTime = 0;
    this->updateTime = 0;
    this->renderTime = 0;
    this->frameLived = 0;
}

Application::~Application() {
    for(Entity* entity : this->entities) {
        delete entity;
    }
}

Application& Application::registerEntity(Entity* entity) {
    this->entities.push_back(entity);
    this->entitiesByLayer.insert(entity);
    this->entitiesByPriority.insert(entity);
    return *this;
}

void Application::start(unsigned long fps) {
    this->setup();
    const sf::Time timePerFrame = sf::seconds(1.f/fps);

    std::cout << "Starting application at "
        << fps << "fps / "
        << timePerFrame.asMicroseconds() << "µs per frame" << std::endl;

    sf::Clock fpsClock;
    sf::Clock profilerClock;

    while(this->window.isOpen()) {
        // TODO Profile these 3 calls
        profilerClock.restart();
        this->eventManager.tick(this->frameLived);
        this->tickTime += (profilerClock.restart()).asMicroseconds();
        this->tickTime /= 2;

        this->eventManager.update();
        this->updateTime += (profilerClock.restart()).asMicroseconds();
        this->updateTime /= 2;

        this->renderer.render();
        this->renderTime += (profilerClock.restart()).asMicroseconds();
        this->renderTime /= 2;

        this->totalTime = this->tickTime + this->updateTime + this->renderTime;

        ++this->frameLived;

        this->waitTime = (timePerFrame - fpsClock.restart()).asMicroseconds();
        if(this->waitTime > 0) {
            std::this_thread::sleep_for(std::chrono::microseconds(this->waitTime));
        }
    }
}

void Application::setup() {
    std::cerr << "Application setup start" << std::endl;

    static sf::Font f; // "static" keeps the font alive (needed since sf::Text doesn't)
    // TODO You know, that's kinda not portable at all
    if(!f.loadFromFile("./resources/bitstream-vera-sans-mono.roman.ttf")) {
        throw std::runtime_error("Could not load font");
    }

    // TODO Use VerticalPlatform and HorizontalPlatform
    this->registerEntity(new HorizontalPlatform(window.getSize(), Platform::Top, sf::Keyboard::Left, sf::Keyboard::Right));
    this->registerEntity(new VerticalPlatform(window.getSize(), Platform::Left, sf::Keyboard::Z, sf::Keyboard::S));
    this->registerEntity(new HorizontalPlatform(window.getSize(), Platform::Bottom, sf::Keyboard::Numpad4, sf::Keyboard::Numpad6));
    this->registerEntity(new VerticalPlatform(window.getSize(), Platform::Right, sf::Keyboard::O, sf::Keyboard::L));

    this->registerEntity(new Frames(f, 10, this->window.getSize().y - 35));
    this->registerEntity(new Ball(window.getSize(), sf::Vector2f(145, 55), sf::Vector2f(-2, -3)));
    this->registerEntity(new Ball(window.getSize(), sf::Vector2f(345, 55), sf::Vector2f(2, -15)));
    this->registerEntity(new Ball(window.getSize(), sf::Vector2f(845, 405), sf::Vector2f(-2, 3)));

    this->registerEntity(new Counter(L"ticks:  ", this->tickTime, sf::Vector2f(50, 65), f));
    this->registerEntity(new Counter(L"update: ", this->updateTime, sf::Vector2f(50, 90), f));
    this->registerEntity(new Counter(L"render: ", this->renderTime, sf::Vector2f(50, 115), f));
    this->registerEntity(new Counter(L"total:  ", this->totalTime, sf::Vector2f(50, 140), f));
    this->registerEntity(new Counter(L"wait:   ", this->waitTime, sf::Vector2f(50, 170), f));

    this->renderer.setBackground(sf::Color(20, 20, 20));

    std::cerr << "Application setup end" << std::endl;
}
