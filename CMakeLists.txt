cmake_minimum_required(VERSION 3.10)
project(calcli VERSION 0.1.0 LANGUAGES CXX)

# Compilation of vendors
add_subdirectory(vendor/googletest)

# Compilation of sources
add_subdirectory(calcli/core)
add_subdirectory(calcli/app)

# Compilation of tests 
add_subdirectory(tests)
