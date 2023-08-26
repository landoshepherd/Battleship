cmake_minimum_required(VERSION 3.10)

project(battleship VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

OPTION(DEBUG_MODE ON)
OPTION(MAC_OS=1)

IF(DEBUG_MODE)
	ADD_DEFINITIONS(-DDEBUG_MODE)
ENDIF(DEBUG_MODE)

IF(MAC_OS)
    ADD_DEFINITIONS(-DMAC_OS)
ENDIF(MAC_OS)

add_executable(battleship
		../main.cpp
		player.cpp
		engine.cpp
		bs_utilities.cpp
		vessel.hpp)
