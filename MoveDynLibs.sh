#!/bin/bash

if [[ ! -d "./build/Release/dynlibsLinux" ]]
then
    mkdir .build/Release/dynlibsLinux
fi
mv build/Release/*.so  .build/Release/dynlibsLinux