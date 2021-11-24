cd build
cmake ..
cmake --build . --config Release
cd ..
ln -sf my_file.txt my_link.txt ./rtype_server.exe ./build/bin/rtype_server.exe
ln -sf my_file.txt my_link.txt ./rtype_client.exe ./build/bin/rtype_client.exe