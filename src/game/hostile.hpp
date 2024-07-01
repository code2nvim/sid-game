#ifndef SID_HOSTILE_HPP
#define SID_HOSTILE_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

namespace Sid {

    class Hostile {
    public:
        Hostile(sf::RenderWindow& window, Player& player);
        ~Hostile() = default;
        Hostile(const Hostile&) = delete;
        Hostile& operator=(const Hostile&) = delete;
        Hostile(Hostile&&) noexcept = delete;
        Hostile& operator=(Hostile&&) noexcept = delete;

        bool hit();
        void approach();
        void draw();
        void process();

    private:
        sf::RenderWindow& _window;
        Player& _player;
        struct {
            sf::CircleShape body;
            sf::CircleShape eye;
        } _elem;
        std::vector<decltype(_elem)> _hostile;
    };

}

#endif // SID_HOSTILE_HPP
