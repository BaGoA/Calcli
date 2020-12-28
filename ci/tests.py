#!/usr/bin/python3

import os
import sys
import subprocess
import argparse


def setup(build_type):
    # Get project directory
    path_script = os.path.realpath(__file__)
    dir_script = os.path.dirname(path_script)
    
    dir_project = os.path.dirname(dir_script)

    # Set binaries tests directory 
    dir_bin_tests = dir_project + "/bin/" + build_type + "/tests"

    return dir_bin_tests


def list_tests(dir_bin_tests):
    binaries = []

    for f in os.listdir(dir_bin_tests):
        path = os.path.join(dir_bin_tests, f)

        if os.path.isfile(path):
            binaries.append(path)

    return binaries


def launch_tests(binaries_test):
    str_error = "No Error"

    for binary in binaries_test:
        response = subprocess.run([binary], stdout=subprocess.PIPE)
        print(response.stdout.decode('ascii'))

        tests_are_run = (response.returncode == 0)

        if not tests_are_run:
            str_error = "Error when executing " + os.path.relpath(binary)

        tests_are_passed = (response.stdout.find(b"failed") == -1)

        if not tests_are_passed:
            str_error = "Some tests failed in " + os.path.relpath(binary)

    return str_error


def main(argv):
    # Intialization of arguments parser
    parser = argparse.ArgumentParser(description="Continuous Integration of Calcli project")
    parser.add_argument("-t", "--type", default="", help="Build project according to build type (debug or release)")

    # Check if list of argument is not empty
    if len(argv) == 0:
        print("Arguments are needed!\n")
        parser.print_help()
        sys.exit(-1)
    
    # Recovery CI options
    arguments = parser.parse_args(argv)
    build_type = arguments.type

    if build_type != "debug" and build_type != "release":
        parser.print_help()
        sys.exit(-1)

    dir_bin_tests = setup(build_type)
    binaries = list_tests(dir_bin_tests)
    str_error = launch_tests(binaries)

    if str_error != "No Error":
        print(str_error)
        sys.exit(-1)




if __name__ == "__main__":
    main(sys.argv[1:])
