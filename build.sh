#!/bin/bash

# Define the build directory
build_dir=build

# Check if the build directory exists, if not, create it
if [[ ! -e $build_dir ]]; then
    mkdir $build_dir
fi

# Move into the build directory
cd $build_dir

# Run CMake and make
cmake ..
make

# If the project compiled successfully, run it
if [[ $? -eq 0 ]]; then
    ./GraphicalAlgoExplorer
fi

