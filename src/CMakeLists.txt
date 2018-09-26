project(SMHasher)

cmake_minimum_required(VERSION 2.4)

set(CMAKE_BUILD_TYPE Release)

add_executable(
  SMHasher
  AvalancheTest.cpp
  Bitslice.cpp
  Bitvec.cpp
  CityTest.cpp
  City.cpp
  crc.cpp
  DifferentialTest.cpp
  Hashes.cpp
  KeysetTest.cpp
  lookup3.cpp
  md5.cpp
  MurmurHash1.cpp
  MurmurHash2.cpp
  MurmurHash3.cpp
  Platform.cpp
  Random.cpp
  sha1.cpp
  SpeedTest.cpp
  Spooky.cpp
  SpookyTest.cpp
  Stats.cpp
  SuperFastHash.cpp
  Types.cpp
  PMurHash.c
  wasm.cpp
)

string(CONCAT LINK_FLAGS 
  " -s WASM=1"
  " -s ALLOW_MEMORY_GROWTH=1"
  " -s MODULARIZE=1"
  " -s ASSERTIONS=1"
  " -s EXPORTED_FUNCTIONS='[\"_MurmurHash3_x86_128_reference\", \"_MurmurHash3_x86_32_reference\", \"_MurmurHash3_x64_128_reference\"]'"
  " -s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\", \"cwrap\"]'"
)

set_target_properties(SMHasher PROPERTIES LINK_FLAGS ${LINK_FLAGS})
