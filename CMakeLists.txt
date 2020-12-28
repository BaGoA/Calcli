cmake_minimum_required(VERSION 3.12)
project(calcli VERSION 0.1.0 LANGUAGES CXX)

# Check presence of Conan
find_program(CONAN conan)

if (NOT CONAN)
    message(FATAL_ERROR "Needs conan package manager: please visit https://conan.io and install")
endif ()

# Compilation of sources
add_subdirectory(calcli/core)
add_subdirectory(calcli/processing)
add_subdirectory(calcli/application)

# Compilation of tests 
add_subdirectory(tests)
