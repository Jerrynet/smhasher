set -e

TARGET=website/wasm
cd $TARGET

make

echo "/* eslint-disable */" > ../src/SMHasher.js
cat SMHasher.js >> ../src/SMHasher.js
cp SMHasher.wasm ../public

cd -
