If(!(test-path build)) {
    mkdir build
}
Set-Location build
conan install --build missing ..
cmake ..
cmake --build . --config Release
Set-Location ..
