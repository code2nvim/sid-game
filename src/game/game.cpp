#include "game.hpp"

#include "cfg/cfg.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

Sid::Game::Game()
    : _window {cfg.window.mode, cfg.window.title, cfg.window.style},
      _player {_window},
      _laser {_window, _player},
      _hostile {_window, _player}
{
    _window.setFramerateLimit(cfg.window.limit);
}

void Sid::Game::process()
{
    _window.clear(cfg.window.color);
    _hostile.process();
    _laser.process();
    _player.process();
    _window.display();
}

void Sid::Game::start()
{
    while (_window.isOpen()) {
        for (sf::Event event {}; _window.pollEvent(event);) {
            switch (event.type) {
            case sf::Event::Closed:
                _window.close();
                break;
            default:
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            _status.time.restart();
        }
        process();
    }
}
