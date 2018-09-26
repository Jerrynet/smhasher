#!/usr/bin/env bash

set -e

TARGET=wasm

cd $TARGET
make

# disable es-lint on the generated minified module file
echo "/* eslint-disable */" | cat - SMHasher.js > /tmp/out && mv /tmp/out SMHasher.js

cd -
