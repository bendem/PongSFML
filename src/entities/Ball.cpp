#include "entities/Ball.hpp"

Ball::Ball(const sf::Vector2u& bounds, const sf::Vector2f& position, const sf::Vector2f& velocity)
        : bounds(sf::FloatRect(0, 0, bounds.x, bounds.y)),
          ball(12),
          velocity(velocity) {
    this->ball.setPosition(position);
    this->ball.setOutlineColor(sf::Color(60, 60, 60));
    this->ball.setOutlineThickness(-2);
}

Ball::Ball(const Ball& p) : bounds(p.bounds), ball(p.ball), velocity(p.velocity) {
}

void Ball::tick(unsigned long) {
    sf::Vector2f pos(this->ball.getPosition());

    if(pos.x + this->velocity.x <= 0) {
        this->velocity.x *= -1;
        pos.x = 0;
    } else if(pos.x + this->ball.getRadius()*2 + this->velocity.x >= this->bounds.width) {
        this->velocity.x *= -1;
        pos.x = this->bounds.width - this->ball.getRadius()*2;
    }
    if(pos.y + this->velocity.y <= 0) {
        this->velocity.y *= -1;
        pos.y = 0;
    } else if(pos.y + this->ball.getRadius()*2 + this->velocity.y >= this->bounds.height) {
        this->velocity.y *= -1;
        pos.y = this->bounds.height - this->ball.getRadius()*2;
    }

    if(pos != this->ball.getPosition()) {
        this->ball.setPosition(pos);
    } else {
        this->ball.move(this->velocity);
    }
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(this->ball);
}
