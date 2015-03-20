#ifndef FRAMES_HPP
#define FRAMES_HPP

#include "entities/Entity.hpp"

class Frames : public Entity {

public:
    Frames(sf::Font&, unsigned int, unsigned int);
    Frames(const Frames&);

    void tick(unsigned long) override;
    void draw(sf::RenderWindow&) override;

    Entity* clone() const override { return new Frames(*this); }

private:
    sf::Text text;

};

#endif
