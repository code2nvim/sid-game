#include "hostile.hpp"

#include "cfg/cfg.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>

Sid::Hostile::Hostile(sf::RenderWindow& window, Player& player)
    : _window {window},
      _player {player},
      _hostile {
          {sf::CircleShape {cfg.hostile.body.radius},
           sf::CircleShape {cfg.hostile.eye.radius}},
          {sf::CircleShape {cfg.hostile.body.radius},
           sf::CircleShape {cfg.hostile.eye.radius}},
          {sf::CircleShape {cfg.hostile.body.radius},
           sf::CircleShape {cfg.hostile.eye.radius}},
      }
{
    for (auto& hostile : _hostile) {
        hostile.eye.setFillColor(cfg.hostile.eye.color);
        hostile.eye.setOrigin(cfg.hostile.eye.radius,
                              cfg.hostile.eye.radius);
        hostile.body.setFillColor(cfg.hostile.body.color);
        hostile.body.setOrigin(cfg.hostile.body.radius,
                               cfg.hostile.body.radius);
    }
    _hostile[0].body.setPosition(cfg.hostile.upper);
    _hostile[1].body.setPosition(cfg.hostile.middle);
    _hostile[2].body.setPosition(cfg.hostile.lower);
    for (auto& hostile : _hostile) {
        hostile.eye.setPosition(hostile.body.getPosition() +
                                cfg.hostile.eye.forward);
    }
}

bool Sid::Hostile::hit()
{
    auto hit = [&](const decltype(_elem)& elem) {
        const auto player = _player.position();
        const auto hostile = elem.body.getPosition();
        double distance = std::sqrt(std::pow((player.x - hostile.x), 2) +
                                    std::pow((player.y - hostile.y), 2));
        return distance < (cfg.hostile.body.radius +
                           cfg.player.body.radius);
    };
    return std::ranges::any_of(_hostile, hit);
}

void Sid::Hostile::approach()
{
    for (auto& elem : _hostile) {
        sf::Vector2f player = _player.position();
        sf::Vector2f hostile = elem.body.getPosition();

        float dis_x = player.x - hostile.x;
        float dis_y = player.y - hostile.y;
        float distance = std::sqrt(dis_x * dis_x + dis_y * dis_y);
        elem.body.move(dis_x / distance,
                       dis_y / distance);
    }
}

void Sid::Hostile::draw()
{
    for (const auto& elem : _hostile) {
        _window.draw(elem.body);
        _window.draw(elem.eye);
    }
}

void Sid::Hostile::process()
{
    approach();
    draw();
}
