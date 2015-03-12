#ifndef FRAMES_HPP
#define FRAMES_HPP

#include "entities/Entity.hpp"

class Frames : public Entity {

public:
    Frames(sf::Font&, unsigned int, unsigned int);

    void tick(unsigned long) override;
    void draw(sf::RenderWindow&) override;

private:
    sf::Text text;

};

#endif
