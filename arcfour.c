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
