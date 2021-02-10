cmake_minimum_required(VERSION 3.12)
project(calcli VERSION 0.1.0 LANGUAGES CXX)

# Compilation of sources
add_subdirectory(calcli/core)
add_subdirectory(calcli/processing)
add_subdirectory(calcli/application)

# Compilation of tests 
add_subdirectory(tests)
