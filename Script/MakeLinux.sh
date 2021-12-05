cd build
cmake ..
cmake --build . --config Release
cd ..
ln -sf ./rtype_server ./build/bin/rtype_server
ln -sf ./rtype_client ./build/bin/rtype_client