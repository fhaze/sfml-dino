cmake_minimum_required(VERSION 3.13)
project(sfml_dino)

set(CMAKE_CXX_STANDARD 14)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

find_package(SFML 2.5 REQUIRED system window graphics network)
add_executable(sfml_dino SFMLDino.cpp Player.cpp Player.h Obstacle.cpp Obstacle.h ObstacleGenerator.cpp ObstacleGenerator.h)
target_link_libraries(sfml_dino sfml-system sfml-window sfml-graphics sfml-network)