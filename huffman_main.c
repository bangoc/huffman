/*
 * (c)2020 bangoc
 */

#include "huffman.h"
#include "vect.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: \n"
           "To compress:   huffman encode <input> <output>\n"
           "To uncompress: huffman decode <input> <output>\n");
    return 1;
  }
  vec_t inp = v_create();
  {
    FILE *fin = fopen(argv[2], "rb");
    const long N = 1024;
    UCHAR buff[N];
    long len = 0;
    while (len = fread(buff, sizeof(UCHAR), N, fin)) {
      for (long i = 0; i < len; ++i) {
        v_push_back(&inp, buff[i]);
      }
    }
    fclose(fin);
  }
  vec_t out = v_create();
  long sz = 0;
  if (strcmp(argv[1], "encode") == 0) {
    printf("Encoding %s to %s\n", argv[2], argv[3]);
    sz = huffman_compress(inp, v_size(inp), &out);
  } else if (strcmp(argv[1], "decode") == 0) {
    printf("Decoding %s to %s\n", argv[2], argv[3]);
    sz = huffman_decompress(inp, v_size(inp), &out);
  } else {
    printf("Unknown command!\n");
    return 1;
  }
  if (sz != v_size(out)) {
    printf("Something wrong!");
    return 1;
  }
  {
    FILE *fout = fopen(argv[3], "wb");
    fwrite(out, sizeof(UCHAR), sz, fout);
    fclose(fout);
  }
  printf("Done!\n");
  return 0;
}