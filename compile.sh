#!/bin/bash

BUILD_DIR="./build"
SRC_DIR="./src"

rm -rf $BUILD_DIR
[ ! -d "$BUILD_DIR" ] && mkdir "$BUILD_DIR"
cd $BUILD_DIR
cmake ..
cmake --build .