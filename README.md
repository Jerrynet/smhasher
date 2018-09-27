
# Build SMHasher for WebAssembly ([see it running](https://cimi.io/murmurhash3js-revisited))

The original `src/CMakeLists.txt` has been changed:

* the build now produces only one target instead of executable + library
* in includes the new `src/wasm.cpp` file (containing the exported functions)
* other required configurations have been added as `LINK_FLAGS`

The project builds successfully; I've used it in an evaluation of JS implementations of murmurhash - [you can try it out here](https://cimi.io/murmurhash3js-revisited).

SMHasher uses `CMake` so with the [emscripten CMAKE toolchain file](https://github.com/kripken/emscripten/blob/incoming/cmake/Modules/Platform/Emscripten.cmake) we generate the build files and then run `make` to get the binary wasm file and the generated JS module file.

For convenience, two build scripts are included in the root of this fork:

```bash
➜  smhasher git:(master) ./prebuild-wasm.sh
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/ciminian/code/smhasher/wasm
➜  smhasher git:(master) ./build-wasm.sh
Scanning dependencies of target SMHasher
[  3%] Building CXX object CMakeFiles/SMHasher.dir/AvalancheTest.o
[  7%] Building CXX object CMakeFiles/SMHasher.dir/Bitslice.o
[ 11%] Building CXX object CMakeFiles/SMHasher.dir/Bitvec.o
[ 15%] Building CXX object CMakeFiles/SMHasher.dir/CityTest.o
[ 19%] Building CXX object CMakeFiles/SMHasher.dir/City.o
[ 23%] Building CXX object CMakeFiles/SMHasher.dir/crc.o
[ 26%] Building CXX object CMakeFiles/SMHasher.dir/DifferentialTest.o
[ 30%] Building CXX object CMakeFiles/SMHasher.dir/Hashes.o
[ 34%] Building CXX object CMakeFiles/SMHasher.dir/KeysetTest.o
[ 38%] Building CXX object CMakeFiles/SMHasher.dir/lookup3.o
[ 42%] Building CXX object CMakeFiles/SMHasher.dir/md5.o
[ 46%] Building CXX object CMakeFiles/SMHasher.dir/MurmurHash1.o
[ 50%] Building CXX object CMakeFiles/SMHasher.dir/MurmurHash2.o
[ 53%] Building CXX object CMakeFiles/SMHasher.dir/MurmurHash3.o
[ 57%] Building CXX object CMakeFiles/SMHasher.dir/Platform.o
[ 61%] Building CXX object CMakeFiles/SMHasher.dir/Random.o
[ 65%] Building CXX object CMakeFiles/SMHasher.dir/sha1.o
[ 69%] Building CXX object CMakeFiles/SMHasher.dir/SpeedTest.o
[ 73%] Building CXX object CMakeFiles/SMHasher.dir/Spooky.o
[ 76%] Building CXX object CMakeFiles/SMHasher.dir/SpookyTest.o
[ 80%] Building CXX object CMakeFiles/SMHasher.dir/Stats.o
[ 84%] Building CXX object CMakeFiles/SMHasher.dir/SuperFastHash.o
[ 88%] Building CXX object CMakeFiles/SMHasher.dir/Types.o
[ 92%] Building C object CMakeFiles/SMHasher.dir/PMurHash.o
[ 96%] Building CXX object CMakeFiles/SMHasher.dir/wasm.o
[100%] Linking CXX executable SMHasher.js
[100%] Built target SMHasher
/Users/ciminian/code/smhasher
```

Here's how my emsdk is set up and the versions I am running:

```bash
➜  smhasher git:(master) activate-emsdk
Adding directories to PATH:
PATH += /Users/ciminian/code/emsdk
PATH += /Users/ciminian/code/emsdk/clang/e1.38.12_64bit
PATH += /Users/ciminian/code/emsdk/node/8.9.1_64bit/bin
PATH += /Users/ciminian/code/emsdk/emscripten/1.38.12

[...]
```

Please read below for the original README.

## [SMHasher](https://github.com/aappleby/smhasher/wiki) is a test suite designed to test the distribution, collision, and performance properties of non-cryptographic hash functions.

This is the home for the [MurmurHash](https://github.com/aappleby/smhasher/tree/master/src) family of hash functions along with the [SMHasher](https://github.com/aappleby/smhasher/tree/master/src) test suite used to verify them. SMHasher is released under the MIT license. All MurmurHash versions are public domain software, and the author disclaims all copyright to their code.

SMHasher is a test suite designed to test the distribution, collision, and performance properties of non-cryptographic hash functions - it aims to be the [DieHarder](http://www.phy.duke.edu/~rgb/General/dieharder.php) of hash testing, and does a pretty good job of finding flaws with a number of popular hashes.

The SMHasher suite also includes [MurmurHash3](https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp), which is the latest version in the series of MurmurHash functions - the new version is faster, more robust, and its variants can produce 32- and 128-bit hash values efficiently on both x86 and x64 platforms.


## Updates

### 1/8/2016

Woo, we're on Github! I've been putting off the migration for a few, uh, years or so, but hopefully Github won't be shutting down any time soon so I don't have to move things again. MurmurHash is still used all over the place, SMHasher is still the defacto hash function test suite, and there are all sorts of interesting new hash functions out there that improve bulk hashing speed and use new shiny hardware instructions for AES and whatnot. Interesting times. :)

I've copied the few wiki pages from code.google.com/p/smhasher to this wiki, though I haven't reformatted them to Markdown yet. The MurmurHash page on Wikipedia should also be linking here now as well. Feel free to send me pull requests.
