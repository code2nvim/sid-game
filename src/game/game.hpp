#ifndef SID_GAME_HPP
#define SID_GAME_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window.hpp>

namespace Sid {

    class Game {
    public:
        Game();
        ~Game() = default;
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        Game(Game&&) noexcept = delete;
        Game& operator=(Game&&) noexcept = delete;

        void start();

    private:
        sf::RenderWindow _window;
        Player _player;
        struct {
            sf::Clock time;
        } _status;
    };

}

#endif // SID_GAME_HPP
