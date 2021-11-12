If(!(test-path ./build/Release/dynlibsWindows)) {
    New-Item -Path './build/Release/dynlibsWindows' -ItemType Directory
}
mv build/Release/*.dll  build/Release/dynlibsWindows