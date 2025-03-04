cmake_minimum_required(VERSION 3.14)
project(chip8)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_library(glad STATIC src/glad.c)
target_include_directories(glad PRIVATE include)

add_executable(
	chip8
	Chip8.cpp
	Main.cpp
	Platform.cpp)

target_include_directories(chip8 PRIVATE include)

target_compile_options(chip8 PRIVATE -Iinclude -Wall -lglfw -ldl -lGL -lGLESv2 -lm -lglfw3 -lX11 -lpthread -lXrandr -lXi -ldl)
include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(chip8 PRIVATE ${SDL2_LIBRARIES} glad glfw OpenGL::GL)