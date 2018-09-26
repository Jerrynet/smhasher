#!/usr/bin/env bash

set -e

TARGET=wasm
EMSCRIPTEN_CMAKE=/Users/ciminian/code/emsdk/emscripten/1.38.12/cmake/Modules/Platform/Emscripten.cmake

rm -rf $TARGET && mkdir -p $TARGET && cd $TARGET
cmake -DCMAKE_TOOLCHAIN_FILE=$EMSCRIPTEN_CMAKE -DCMAKE_BUILD_TYPE=RelWithDebInfo -G "Unix Makefiles" ../src
