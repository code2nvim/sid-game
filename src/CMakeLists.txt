cmake_minimum_required(VERSION 3.28)

project(sid-game CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(sid-game main.cpp)

add_subdirectory(game)

target_link_libraries(sid-game PRIVATE game)
