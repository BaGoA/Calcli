# Pinky [![Build Status](https://travis-ci.org/BaGoA/Pinky.svg?branch=main)](https://travis-ci.org/BaGoA/Pinky)

Pinky is a simple C++ command line calculator. 

## Build
Build of Pinky project is made by [CMake](https://cmake.org/) associate to [Ninja](https://ninja-build.org/). 

To build Pinky project, you can use script build.py in tools/ci folder like this:

	./build.py -t debug		to compile in debug mode
	./build.py -t debug -a	to compile in debug mode with clang-tidy analysis

	./build.py -t release		to compile in release mode
	./build.py -t release -a	to compile in release mode with clang-tidy analysis

To launch Pinky units tests, you can use script tests.py in tools/ci folder like this:

	./test.py -t debug		to launch units tests with debug build version 
	./test.py -t release	to launch units tests with debug build version

## Licensing
Pinky is free software, you can redistribute it and/or modify it under the terms of the GNU General Public License.
