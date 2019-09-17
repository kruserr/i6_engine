#!/bin/bash

mkdir build
cd build
cmake ..
cmake --build .
test = $(./i6_engine)
echo "$test"
cd ..
