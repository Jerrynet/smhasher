#include "MurmurHash3.h"
#include <stdio.h>
#include <string.h>

extern "C" {
  void printHex(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
      printf("%02X ", (unsigned char)str[i]);
    }
    printf("\n");
  }

  void logInput(const char* variant, const char* input) {
    printf("====================================\n");
    printf("WASM %s input: %s\n", variant, input);
    printf("WASM %s bytes: ", variant); printHex(input);
  }

  void logOutput(const char* variant, void* bytes) {
    printf("WASM %s output: ", variant); printHex((char *) bytes);
    printf("====================================\n\n");
  }

  char* hexStr32(void* bytes) {
    char *output = new char[32];
    int *ints = (int*) bytes;
    for (int i = 0; i < 4; i++) {
      sprintf(&output[i * 8], "%08x", ints[i]);
    }
    return output;
  }

  char* hexStr64(void* bytes) {
    char *output = new char[32];
    uint64_t *ints = (uint64_t*) bytes;
    for (int i = 0; i < 2; i++) {
      sprintf(&output[i * 16], "%016llx", ints[i]);
    }
    return output;
  }

  char* MurmurHash3_x86_32_reference(const char* input) {
    logInput("x86_32", input);

    uint32_t buffer[1];
    MurmurHash3_x86_32(input, strlen(input), 0, &buffer);
    char *output = new char[16];
    sprintf(&output[0], "%u", buffer[0]);

    logOutput("x86_32", buffer);

    return output;
  }

  char* MurmurHash3_x86_128_reference(const char* input) {
    logInput("x86_128", input);

    uint64_t buffer[2];
    MurmurHash3_x86_128(input, strlen(input), 0, &buffer);

    logOutput("x86_128", buffer);

    char *output = hexStr32(buffer);
    return output;
  }

  char* MurmurHash3_x64_128_reference(const char* input) {
    logInput("x64_128", input);

    uint64_t buffer[2];
    MurmurHash3_x64_128(input, strlen(input), 0, &buffer);

    logOutput("x64_128", buffer);

    char *output = hexStr64(buffer);
    return output;
  }
}
