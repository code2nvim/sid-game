#include "game/game.hpp"
#include <exception>
#include <iostream>

int main()
{
    try {
        Sid::Game game;
        game.start();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
