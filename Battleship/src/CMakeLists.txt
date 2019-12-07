cmake_minimum_required(VERSION 3.13.2)

project(terminal_battleship)

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp
                               utilities/BS_Utilities.cpp
                               engine.cpp
                               Player.cpp)

