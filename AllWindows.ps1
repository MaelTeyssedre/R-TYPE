If(!(test-path build)) {
    mkdir build
}
Set-Location build
conan install --build missing ..
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
Set-Location ..
