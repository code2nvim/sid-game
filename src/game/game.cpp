#include "game.hpp"

#include "cfg/cfg.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

Sid::Game::Game()
    : _window {cfg.window.mode, cfg.window.title, cfg.window.style},
      _player {_window}
{
    _window.setFramerateLimit(cfg.window.limit);
}

void Sid::Game::start()
{
    while (_window.isOpen()) {
        float time = _status.time.getElapsedTime().asSeconds();
        for (sf::Event event {}; _window.pollEvent(event);) {
            switch (event.type) {
            case sf::Event::Closed:
                _window.close();
                break;
            default:
                break;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            _status.time.restart();
        }

        _window.clear(cfg.window.color);
        _player.move();
        _player.draw();
        _window.display();
        std::cout << time << '\n';
    }
}
