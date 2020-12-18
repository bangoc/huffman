/*
 * (c)2020 bangoc
 */

#ifndef VECT_H_
#define VECT_H_

#include <assert.h>
#include <stddef.h>

typedef unsigned char UCHAR;
typedef UCHAR *vec_t;

#ifdef __cplusplus
extern "C"{
#endif

vec_t v_create();

/* Pass vector pointer by value */
int v_setsize(vec_t const v, long newsize);
long v_capacity(vec_t const v);
long v_size(vec_t const v);
int v_print(vec_t const v);

/* Pass vector pointer by reference */
int v_grow(vec_t *v, long newcapacity);
int v_init(vec_t *v, long size);

int v_push_back(vec_t *v, UCHAR value);
int v_ensure_index(vec_t *v, long idx);
int v_free(vec_t *v);

#ifdef __cplusplus
}
#endif

#endif  // VECT_H_