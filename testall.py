#!/usr/local/bin/python3

"""
This script ochestrate all the source file test for C++/C
"""

import os
import subprocess
import re

BLD_DIR = os.path.join(os.path.dirname(os.path.realpath(__file__)), "cmake-build-debug")


def test_leetcode():
    """
    Test generated binary of leetcode/
    """
    exec_dir = os.path.join(BLD_DIR, "leetcode")
    os.chdir(exec_dir)
    files = os.listdir()
    p = re.compile("^[0-9]*$")
    for file in files:
        if p.match(file):
            print("test: {}".format(file))
            subprocess.run(
                [os.path.join(exec_dir, file)], check=True, capture_output=True
            )
    print("leetcode all PASS")


def test_misc():
    """
    Test generated binary of misc/
    """
    exec_dir = os.path.join(BLD_DIR, "misc")
    os.chdir(exec_dir)
    files = os.listdir()
    p = re.compile("^[0-9]*$")
    for file in files:
        if p.match(file):
            print("test: {}".format(file))
            subprocess.run(
                [os.path.join(exec_dir, file)], check=True, capture_output=True
            )
    print("misc all PASS")


def test_hackerrank():
    """
    Test generated binary of hackerrank/

    We parse 'target_list.txt' file for the list of binaries, which is written by CMake
    """
    exec_dir = os.path.join(BLD_DIR, "hackerrank")
    os.chdir(exec_dir)
    with open("target_list.txt") as f:
        binary = [line.rstrip("\n") for line in f]
        for b in binary:
            print("test: {}".format(b))
            subprocess.run([os.path.join(exec_dir, b)], check=True, capture_output=True)
    print("hackerrank all PASS")


def testall():
    """
    Test all the generated binary of C++/C
    """
    os.makedirs(BLD_DIR, exist_ok=True)
    os.chdir(BLD_DIR)
    subprocess.run("cmake ..", shell=True, check=True)
    subprocess.run("make -j4", shell=True, check=True)
    test_leetcode()
    test_misc()
    test_hackerrank()


if __name__ == "__main__":
    testall()
