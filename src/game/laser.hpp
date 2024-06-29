#ifndef SID_LASER_HPP
#define SID_LASER_HPP

#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace Sid {

    class Laser {
    public:
        Laser(sf::RenderWindow& window, Player& Player);
        ~Laser() = default;
        Laser(const Laser&) = delete;
        Laser& operator=(const Laser&) = delete;
        Laser(Laser&&) noexcept = delete;
        Laser& operator=(Laser&&) noexcept = delete;

        void emit();
        void draw();
        void process();

    private:
        sf::RenderWindow& _window;
        Player& _player;
        sf::VertexArray _laser;
    };

}

#endif // SID_LASER_HPP
