#!/bin/bash

if [[ ! -d "./build/bin/dynlibsLinux" ]]
then
    mkdir ./build/bin/dynlibsLinux
fi
mv build/bin/*.so  .build/bin/dynlibsLinux