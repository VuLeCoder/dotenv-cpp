rm -rf build
clear

mkdir build
cd build
clear

cmake .. -DENVCPP_BUILD_EXAMPLES=ON
cmake --build .
cd ..