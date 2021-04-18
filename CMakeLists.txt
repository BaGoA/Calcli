cmake_minimum_required(VERSION 3.12)
project(pinky VERSION 0.1.0 LANGUAGES CXX)

# Compilation of sources
add_subdirectory(src/core)
add_subdirectory(src/cli)

# Compilation of tests 
add_subdirectory(tests)
