#!/bin/bash

if [[ ! -d "build" ]]
then
    mkdir build
fi
cd build
conan install --build missing ..
cd ..