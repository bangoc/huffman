/*
 * (c)2020 bangoc
 */

#include <stdio.h>
#include <stdlib.h>

#include "vect.h"

int v_setsize(vec_t const v, long newsize) {
  long capacity = (long) v_capacity(v);
  if (newsize <= capacity && v) {
    ((size_t *)(v))[-2] = (newsize);
    return 0;
  }
  return 1;
}

long v_capacity(vec_t const v) {
  return ((v) ? ((size_t *)(v))[-1] : (size_t)0);
}

long v_size(vec_t const v) {
  return ((v) ? ((size_t *)(v))[-2] : (size_t)0);
}

vec_t v_create() {
  return (vec_t)&((size_t*)calloc(2, sizeof(size_t)))[2];
}

int v_grow(vec_t *v, long newcapacity) {
  long capacity = (long) v_capacity((*v));
  if (capacity < newcapacity) {
    const size_t __sz = newcapacity * sizeof(long) + (sizeof(size_t) * 2);
    size_t *__p1 = &((size_t *)(*v))[-2];
    size_t *__p2 = realloc(__p1, (__sz));
    assert(__p2);
    (*v) = (vec_t)(&__p2[2]);
    vec_t vec = *v;
    if (vec) {
      ((size_t *)(vec))[-1] = newcapacity;
    }
  }
  return 0;
}

int v_init(vec_t *v, long size) {
  v_grow(v, size);
  v_setsize(*v, size);
  return 0;
}

int v_push_back(vec_t *v, UCHAR value) {
  size_t __cap = v_capacity(*v);
  if (__cap <= v_size(*v)) {
    v_grow(v, !__cap ? __cap + 1 : __cap * 2);
  }
  vec_t vec = *v;
  vec[v_size(vec)] = (value);
  v_setsize((vec), v_size(vec) + 1);
  return 0;
}

int v_ensure_index(vec_t *v, long idx) {
  size_t __cap = v_capacity(*v);
  if (__cap <= idx) {
    while (__cap <= idx) {
      if (__cap == 0) {
        __cap = 1;
      } else {
        __cap *= 2;
      }
    }
    v_grow(v, __cap);
  }
  return 0;
}

int v_free(vec_t *v) {
  vec_t vec = *v;
  if (vec) {
    size_t *p1 = &((size_t *)(vec))[-2];
    free(p1);
  }
  return 0;
}
