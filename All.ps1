mkdir build
Set-Location build
conan install --build missing ..
cmake ..
cmake --build . --config Release

