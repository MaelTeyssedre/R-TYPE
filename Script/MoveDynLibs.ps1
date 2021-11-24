If(!(test-path ./build/Release/dynlibsWindows)) {
    New-Item -Path './build/Release/dynlibsWindows' -ItemType Directory
}
Move-Item -Path build/Release/*.dll -Destination build/Release/dynlibsWindows