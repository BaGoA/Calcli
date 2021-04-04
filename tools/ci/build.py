#!/usr/bin/python3

import sys
import os
import platform
import subprocess
import argparse


def setup(build_type, compiler_option):
    # Set project directory
    path_script = os.path.realpath(__file__)
    dir_script = os.path.dirname(path_script)
    
    dir_tools = os.path.dirname(dir_script)
    dir_project = os.path.dirname(dir_tools)

    # Create "/build" directory if necessary
    base_dir_build = dir_project + "/build"

    if not os.path.exists(base_dir_build):
        os.mkdir(base_dir_build)

    # Create build directory according to build type if necessary
    dir_build = base_dir_build

    if compiler_option == "gcc":
        compiler = "gcc"

        if build_type == "debug":
            build_type = "debug"
            dir_build += "/debug-gcc"
        elif build_type == "release":
            build_type = "release"
            dir_build += "/release-gcc"
        else:
            build_type = "debug"
            dir_build += "/debug-gcc"
    elif compiler_option == "clang":
        compiler = "clang"

        if build_type == "debug":
            build_type = "debug"
            dir_build += "/debug-clang"
        elif build_type == "release":
            build_type = "release"
            dir_build += "/release-clang"
        else:
            build_type = "debug"
            dir_build += "/debug-gcc"
    else:
        compiler = ""

        if build_type == "debug":
            build_type = "debug"
            dir_build += "/debug"
        elif build_type == "release":
            build_type = "release"
            dir_build += "/release"
        else:
            build_type = "debug"
            dir_build += "/debug"

    if not os.path.exists(dir_build):
        os.mkdir(dir_build)

    return build_type, compiler, dir_build, dir_project


def build(build_type, compiler, dir_build, dir_project):
    str_error = "No Error"

    # Create cmake command line according to build type and platform
    cmake_command = ["cmake", "-D"]

    if build_type == "debug":
        cmake_command.append("CMAKE_BUILD_TYPE=Debug")
    else:
        cmake_command.append("CMAKE_BUILD_TYPE=Release")

    if compiler == "clang":
        cmake_command.append("-DCMAKE_CXX_COMPILER=clang++")
        cmake_command.append("-DCMAKE_C_COMPILER=clang")
    elif compiler == "gcc":
        cmake_command.append("-DCMAKE_CXX_COMPILER=g++")
        cmake_command.append("-DCMAKE_C_COMPILER=gcc")

    cmake_command.append("-G")

    if platform.system() == "Linux":
        cmake_command.append("Ninja")
    elif platform.system() == "Windows":
        cmake_command.append("Ninja")
    else:
        str_error = "Platform not supported"
        return str_error

    cmake_command.append(dir_project)

    # Run cmake on project
    os.chdir(dir_build) # go into build directory
    response = subprocess.run(cmake_command)

    if response.returncode != 0:
        str_error = "Error in CMake command"
        return str_error

    # Build project
    response = subprocess.run(["cmake", "--build", dir_build])

    if response.returncode != 0:
        str_error = "Error in Make command"

    return str_error


def main(argv):
    # Initialization of arguments parser
    parser = argparse.ArgumentParser(description="Build of Pinky project")
    parser.add_argument("-t", "--type", default="", help="Build type (debug or release)")
    parser.add_argument("-c", "--compiler", default="", help="Compiler identifier (gcc or clang)")

    # Check if list of argument is not empty
    if len(argv) == 0:
        print("Arguments are needed!\n")
        parser.print_help()
        sys.exit(-1)
    
    # Recovery build type options
    arguments = parser.parse_args(argv)
    type_option = arguments.type

    if type_option != "debug" and type_option != "release":
        print("Unknown build type")
        parser.print_help()
        sys.exit(-1)

    compiler_option = arguments.compiler

    # Recovery build information
    build_type, compiler, dir_build, dir_project = setup(type_option, compiler_option)

    # Build project
    str_error = build(build_type, compiler, dir_build, dir_project)

    if str_error != "No Error":
        print(str_error)
        sys.exit(-1)




if __name__ == "__main__":
    main(sys.argv[1:])
