cmake_minimum_required(VERSION 3.17)
project(LMT)

set(CMAKE_CXX_STANDARD 14)

# Define the path to the SFML root directory, adjust if necessary
set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(LMT main.cpp
        turtle.cpp
        turtle.h)
target_link_libraries(LMT sfml-graphics sfml-audio)
