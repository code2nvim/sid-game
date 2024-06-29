#include "laser.hpp"

#include "cfg/cfg.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

Sid::Laser::Laser(sf::RenderWindow& window, Player& player)
    : _window {window},
      _player {player},
      _laser {sf::Lines, 2}
{
    _laser[0].color = Sid::cfg.laser.color;
    _laser[1].color = Sid::cfg.laser.color;
}

void Sid::Laser::emit()
{
    _laser[0].position = _player.position();
    _laser[1].position = sf::Vector2f(sf::Mouse::getPosition(_window));
    _player.laser();
}

void Sid::Laser::draw()
{
    _window.draw(_laser);
}

void Sid::Laser::process()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        emit();
        draw();
    }
}
