If(!(test-path build)) {
    mkdir build
}
Set-Location build
conan install --build missing ..
cmake ..
cmake --build . --config Release
Set-Location ..

If (!(test-path rtype_server.exe)) {
    New-Item -ItemType SymbolicLink -Path "./rtype_server.exe" -Target "./build/bin/rtype_server.exe"
}
If (!(test-path rtype_client.exe)) {
    New-Item -ItemType SymbolicLink -Path "./rtype_client.exe" -Target "./build/bin/rtype_client.exe"
}