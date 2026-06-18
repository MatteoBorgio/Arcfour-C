#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define export __attribute__((visibility("default")))
#define rc4_decrypt(x, y, z) rc4_encrypt(x, y, z)
#define rc4_ununit(x) free(x)

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

// Internal state of the encryption
typedef struct {
    int16 i;
    int8 j;
    int8 s[256];
} Arcfour;

export Arcfour *rc4_init(int8 *key, int16 size);
int8 rc4_byte(Arcfour *p);
export int8 *rc4_encrypt(Arcfour *p, int8 *source, int16 size);
