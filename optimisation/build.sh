#/bin/bash

cmake -S . -B ./build
cmake --build build --config Release --parallel 14 --target clean
cmake --build build --config Release --parallel 14