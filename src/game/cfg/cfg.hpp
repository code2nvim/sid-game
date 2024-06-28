#ifndef SID_CONFIG_HPP
#define SID_CONFIG_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

namespace Sid {

    const struct {

        struct {
            sf::Color color {55, 55, 55};
            sf::VideoMode mode {1280, 720};
            std::string title {"Sid"};
            unsigned style = sf::Style::Titlebar;
            unsigned limit = 60;
        } window;

        struct {
            struct {
                float radius = 30.0F;
                sf::Color color {sf::Color::Black};
            } body;
            struct {
                float radius = 5.0F;
                sf::Color color {sf::Color::White};
                sf::Vector2f forward {10.0F, -3.0F};
                sf::Vector2f backward {-10.0F, -3.0F};
            } eye;
            float speed = 10.0F;
        } player;

        struct {
            sf::Color color {sf::Color::Red};
        } line;

        struct {
            sf::Color color {sf::Color::Yellow};
        } dot;

    } cfg;

}

#endif // SID_CONFIG_HPP
