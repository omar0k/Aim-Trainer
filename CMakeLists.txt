cmake_minimum_required(VERSION 3.20)

project(my_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DVALOR_WINDOWS)
elseif(APPLE)
	add_definitions(-DVALOR_MAC)
elseif(UNIX)
	add_definitoins(-DVALOR_LINUX)
endif()


add_subdirectory(MyGame)
add_subdirectory(Valor)
add_subdirectory(glfw)