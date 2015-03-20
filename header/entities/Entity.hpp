#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {

public:
    enum Priority {
        Low,
        Normal,
        High
    };

    enum Layer {
        Back,
        Middle,
        Front
    };

    Entity(Layer = Middle, Priority = Normal);
    Entity(const Entity&);
    virtual ~Entity() {}

    virtual void tick(unsigned long);
    virtual void update(const sf::Event&);
    virtual void draw(sf::RenderWindow&);
    virtual Entity* clone() const = 0;

    struct ByLayer {
        bool operator()(Entity*, Entity*);
    };
    struct ByPriority {
        bool operator()(Entity*, Entity*);
    };

    const Layer layer;
    const Priority priority;

};

#endif
