#!/usr/bin/env bash

#clean build
rm -rf build && mkdir build && cd build && cmake .. && cmake --build .

#test
./tests/rps_test
echo -e "Test ended. Now running the executable.\n\n"
./src/rps/rps_exe 5
