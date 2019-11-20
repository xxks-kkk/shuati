#!/bin/bash

# This script ochestrate all the source file test for C++/C
BLD_DIR=$(pwd)/cmake-build-debug
mkdir -p $BLD_DIR

cd $BLD_DIR
cmake ..
make -j4

# test binary under leetcode/
cd $BLD_DIR/leetcode/
"for a in $(ls | grep '^[0-9]*$'); do ./$a; done"

# test binary under misc/
cd $BLD_DIR/misc/
"for a in $(ls | grep '^[0-9]*$'); do ./$a; done"

# test binary under hackerrank
cd $BLD_DIR/hackerrank/
"for a in $(cat target_list.txt); do ./$a; done"
