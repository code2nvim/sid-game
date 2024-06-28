#ifndef SID_PLAYER_HPP
#define SID_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace Sid {

    class Player {
    public:
        Player(sf::RenderWindow& window);
        ~Player() = default;
        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
        Player(Player&&) noexcept = delete;
        Player& operator=(Player&&) noexcept = delete;

        bool valid(sf::Keyboard::Key key);
        void move();
        auto position() const -> const sf::Vector2f&;
        void draw() const;

    private:
        sf::RenderWindow& _window;
        sf::CircleShape _body;
        sf::CircleShape _eye;
        struct {
            bool forward = true;
        } _status;
    };

}

#endif // SID_PLAYER_HPP
