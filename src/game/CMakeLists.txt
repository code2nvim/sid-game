add_library(game control.cpp game.cpp hostile.cpp laser.cpp player.cpp)

target_link_libraries(game PRIVATE sfml-graphics sfml-system sfml-window)
