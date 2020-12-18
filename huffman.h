/*
 * Modified by bangoc
 * for the origin git@github.com:adamierymenko/huffandpuff.git
 */

#ifndef ____HUFFMAN_H
#define ____HUFFMAN_H

#include "vect.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Huffman encode a block of data
 *
 * @param in Input data
 * @param inlen Input data length
 * @param out Output buffer
 * @param outlen Output buffer length
 * @return Size of encoded result or 0 on out buffer overrun
 */
extern unsigned long huffman_compress(const unsigned char *in, unsigned long inlen, vec_t *out);

/**
 * Huffman decode a block of data
 *
 * @param in Input data
 * @param inlen Length of input data
 * @param out Output buffer
 * @param outlen Length of output buffer
 * @return Size of decoded result or 0 on out buffer overrun or corrupt input data
 */
extern unsigned long huffman_decompress(const unsigned char *in, unsigned long inlen, vec_t *out);

#ifdef __cplusplus
}
#endif

#endif
