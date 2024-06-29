#include "player.hpp"

#include "cfg/cfg.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

Sid::Player::Player(sf::RenderWindow& window)
    : _window {window},
      _body {cfg.player.body.radius},
      _eye {cfg.player.eye.radius}
{
    _body.setFillColor(cfg.player.body.color);
    _body.setOrigin(cfg.player.body.radius,
                    cfg.player.body.radius);

    _eye.setFillColor(cfg.player.eye.color);
    _eye.setOrigin(cfg.player.eye.radius,
                   cfg.player.eye.radius);
}

bool Sid::Player::valid(sf::Keyboard::Key key)
{
    sf::FloatRect bounds = _body.getGlobalBounds();
    sf::Vector2u size = _window.getSize();
    switch (key) {
    case sf::Keyboard::A:
        return bounds.left > 0;
    case sf::Keyboard::D:
        return bounds.left + bounds.width < static_cast<float>(size.x);
    case sf::Keyboard::S:
        return bounds.top + bounds.height < static_cast<float>(size.y);
    case sf::Keyboard::W:
        return bounds.top > 0;
    default:
        return false;
    }
}

// TODO: control.hpp and control.cpp
void Sid::Player::move()
{
    // left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _status.forward = false;
        if (valid(sf::Keyboard::A)) {
            _body.move(-cfg.player.speed, 0);
        }
    }
    // right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _status.forward = true;
        if (valid(sf::Keyboard::D)) {
            _body.move(cfg.player.speed, 0);
        }
    }
    // down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (valid(sf::Keyboard::S)) {
            _body.move(0, cfg.player.speed);
        }
    }
    // up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (valid(sf::Keyboard::W)) {
            _body.move(0, -cfg.player.speed);
        }
    }
    const auto offset = _status.forward ? cfg.player.eye.forward
                                        : cfg.player.eye.backward;
    _eye.setPosition(_body.getPosition() + offset);
}

void Sid::Player::draw()
{
    _window.draw(_body);
    _window.draw(_eye);
}

void Sid::Player::process()
{
    if (_status.laser) {
        _eye.setFillColor(cfg.laser.color);
        _status.laser = false;
    }
    else {
        _eye.setFillColor(cfg.player.eye.color);
    }
    move();
    draw();
}

auto Sid::Player::position() const
    -> const sf::Vector2f&
{
    return _body.getPosition();
}
