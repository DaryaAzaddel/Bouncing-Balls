cmake_minimum_required(VERSION 3.21)
project(untitled6)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled6   main.cpp )
target_link_libraries(untitled6 PRIVATE mingw32 SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer)
