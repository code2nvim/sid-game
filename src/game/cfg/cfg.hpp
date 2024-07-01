#ifndef SID_CONFIG_HPP
#define SID_CONFIG_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <string>

namespace Sid {

    const struct {

        // window
        struct {
            sf::Color color {55, 55, 55};
            sf::VideoMode mode {1280, 720};
            std::string title {"Sid"};
            unsigned style = sf::Style::Titlebar;
            unsigned limit = 60;
        } window;

        // player
        struct {
            sf::Vector2f position {80, 360};
            float speed = 10.0F;
            struct {
                sf::Color color {sf::Color::Black};
                float radius = 30.0F;
            } body;
            struct {
                sf::Color color {sf::Color::White};
                sf::Vector2f forward {12.5F, -3.0F};
                sf::Vector2f backward {-12.5F, -3.0F};
                float radius = 5.0F;
            } eye;
        } player;

        // laser
        struct {
            sf::Color color {sf::Color::Red};
        } laser;

        // dot
        struct {
            sf::Color color {sf::Color::Yellow};
        } dot;

        // hostile
        struct {
            sf::Vector2f upper {1200, 180};
            sf::Vector2f middle {1200, 360};
            sf::Vector2f lower {1200, 540};
            float speed = 5.0F;
            struct {
                sf::Color color {22, 22, 22};
                float radius = 40.0F;
            } body;
            struct {
                sf::Color color {sf::Color::White};
                sf::Vector2f forward {-20.0F, -7.5F};
                float radius = 7.5F;
            } eye;
        } hostile;

    } cfg;

}

#endif // SID_CONFIG_HPP
