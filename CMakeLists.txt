cmake_minimum_required(VERSION 3.13)
project(sfml_dino)

set(CMAKE_CXX_STANDARD 14)
#set(SFML_STATIC_LIBRARIES TRUE)
#set(SFML_DIR "/home/fhaze/libs/SFML/build")
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

find_package(SFML REQUIRED system window graphics network)
add_executable(sfml_dino SFMLDino.cpp Player.cpp Player.h Obstacle.cpp Obstacle.h ObstacleGenerator.cpp ObstacleGenerator.h)
target_link_libraries(sfml_dino sfml-system sfml-window sfml-graphics sfml-network)