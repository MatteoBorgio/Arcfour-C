#include "arcfour.h"

void printbin(int8 *text, const int16 size) {
    int16 i;
    int8 *p;

    assert(size > 0);

    for (i = size, p = text; i; i--, p++) {
        if (!(i % 2)) {
            printf(" ");
        }
        printf("%.02x", *p);
    }
    printf("\n");
    return;
}

int main(void) {
    Arcfour *rc4;
    int16 size_key, size_text;
    int8 *key, *source;

    key = (int8 *)"8fA2bX9vE1mQ7zP4kL6wT9jR3cH5nG1p";
    size_key = strlen((char *)key);
    source = (int8 *)"Example. Verification code: 481516. Is the Arcfour "
                     "algorithm functioning correctly?";
    size_text = strlen((char *)source);

    printf("Initializing encryption...\n");
    rc4 = rc4_init(key, size_key);
    printf("Done.\n\n");

    // --- TEST DI VERIFICA DI rc4_init ---
    if (rc4 != NULL) {
        printf("Verifica puntatori interni dopo il reset:\n");
        printf("rc4->i attuale: %d (Atteso: 0)\n", rc4->i);
        printf("rc4->j attuale: %d (Atteso: 0)\n\n", rc4->j);

        printf("Primi 16 byte della S-Box mescolata (KSA):\n");
        printbin(rc4->s, 16);

        free(rc4);
    } else {
        printf("Errore: rc4_init ha restituito un puntatore NULL.\n");
    }
    // -------------------------------------

    return 0;
}
