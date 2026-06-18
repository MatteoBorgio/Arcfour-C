#include "arcfour.h"

Arcfour *rc4_init(int8 *key, int16 size) {
    Arcfour *p;
    p = malloc(sizeof(Arcfour));

    if (p == NULL) {
        fprintf(stderr, "Errore: allocazione di memoria fallita.\n");
        return NULL;
    }

    int8 temp;

    p->i = 0;
    p->j = 0;

    for (p->i = 0; p->i < 256; p->i++) {
        p->s[p->i] = (int8)p->i;
    }

    for (p->i = 0; p->i < 256; p->i++) {
        p->j = (p->j + p->s[p->i] + key[p->i % size]);
        temp = p->s[p->i];
        p->s[p->i] = p->s[p->j];
        p->s[p->j] = temp;
    }

    p->i = 0;
    p->j = 0;

    return p;
}

int8 rc4_byte(Arcfour *p) {
    int8 temp_swap, temp_index;

    p->i = (p->i + 1) % 256;
    p->j = (p->j + p->s[p->i]);

    temp_swap = p->s[p->i];
    p->s[p->i] = p->s[p->j];
    p->s[p->j] = temp_swap;

    temp_index = p->s[p->i] + p->s[p->j];

    return p->s[temp_index];
}

int8 *rc4_encrypt(Arcfour *p, int8 *source, int16 size) {
    int8 *ciphertext;
    int x;

    ciphertext = (int8 *)malloc(size * sizeof(int8));

    if (ciphertext == NULL) {
        fprintf(stderr, "Errore: allocazione di memoria fallita.\n");
        return NULL;
    }

    for (x = 0; x < size; x++) {
        ciphertext[x] = rc4_byte(p) ^ source[x];
    }

    return ciphertext;
}
