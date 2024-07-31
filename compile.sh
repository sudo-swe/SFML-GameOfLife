#!/usr/bin/env bash

echo -e "\n\tStarting compiling script...\n"

BUILD_DIR="build"
PROJECT_NAME="GameOfLife"

if [ -d "$BUILD_DIR" ]; then
    echo -e "\t$BUILD_DIR directory already created. Changing into the directory.\n"
    cd "$BUILD_DIR"
else
    echo -e "\t$BUILD_DIR directory not created. Creating directory.\n"
    mkdir "$BUILD_DIR"
    echo -e "\t$BUILD_DIR directory created. Changing into the directory.\n"
    cd "$BUILD_DIR"
fi

cmake ..
make
./"$PROJECT_NAME"
