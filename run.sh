#!/bin/bash

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

mkdir build
cd build
cmake ..
cmake --build .
./i6_engine
cd ..
