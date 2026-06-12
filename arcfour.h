#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define rc4_decrypt(x, y) rc4_encrypt(x, y)

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

// Internal state of the encryption
typedef struct {
    int16 i;
    int8 j;
    int8 s[256];
} Arcfour;

Arcfour *rc4_init(int8 *key, int16 size);
int8 rc4_byte(void);
int8 *rc4_encrypt(int8 *source, int16 size);
