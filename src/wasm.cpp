#include "MurmurHash3.h"
#include <stdio.h>
#include <string.h>

extern "C" {
  void printHex(const char* str) {
    printf("WASM input bytes: ");
    for (int i = 0; i < strlen(str); i++) {
      printf("%02X ", (unsigned char)str[i]);
    }
    printf("\n");
  }

  char* hexStr(void* bytes, int length) {
    char *output = new char[32];
    int *ints = (int*) bytes;
    printHex((char*)bytes);
    for (int i = 0; i < length; i++) {
      sprintf(&output[i * 8], "%08x", ints[i]);
    }
    return output;
  }

  char* hexStr64(void* bytes) {
    char *output = new char[32];
    uint64_t *ints = (uint64_t*) bytes;
    printHex((char*)bytes);
    for (int i = 0; i < 2; i++) {
      sprintf(&output[i * 16], "%016llx", ints[i]);
    }
    return output;
  }

  char* MurmurHash3_x86_32_reference(const char* input) {
    uint32_t buffer[1];
    MurmurHash3_x86_32(input, strlen(input), 0, &buffer);
    char *output = new char[16];
    sprintf(&output[0], "%u", buffer[0]);
    return output;
  }

  char* MurmurHash3_x86_128_reference(const char* input) {
    uint64_t buffer[2];
    MurmurHash3_x86_128(input, strlen(input), 0, &buffer);

    char *output = hexStr(buffer, 4);
    return output;
  }

  char* MurmurHash3_x64_128_reference(const char* input) {
    uint64_t buffer[2];
    MurmurHash3_x64_128(input, strlen(input), 0, &buffer);

    return hexStr64(buffer);
  }
}
