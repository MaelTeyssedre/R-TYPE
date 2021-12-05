#!/bin/bash

if [[ ! -d "build" ]]
then
    mkdir build
fi
cd build
conan install --build missing ..
cmake ..
cmake --build . --config Release
cd ..
ln -sf ./rtype_server ./build/bin/rtype_server
ln -sf ./rtype_client ./build/bin/rtype_client
