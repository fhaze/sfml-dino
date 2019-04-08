cmake_minimum_required(VERSION 3.13)
project(sfml_dino)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 REQUIRED system window graphics network audio)
add_executable(sfml_dino main.cpp player.cpp player.h obstacle.cpp obstacle.h obstacle-generator.cpp obstacle-generator.h)
target_link_libraries(sfml_dino sfml-system sfml-window sfml-graphics sfml-network sfml-audio)