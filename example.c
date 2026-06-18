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

    printf("Initializing RC4 with key...\n");
    rc4 = rc4_init(key, size_key);
    if (rc4 == NULL) {
        fprintf(stderr, "Errore di inizializzazione.\n");
        return 1;
    }

    int8 *encrypted = malloc(sizeof(int8) * size_text);
    if (encrypted == NULL) {
        fprintf(stderr, "Errore allocazione memoria encrypted.\n");
        free(rc4);
        return 1;
    }

    printf("Encrypting plaintext...\n");
    for (int16 l = 0; l < size_text; l++) {
        encrypted[l] = rc4_byte(rc4) ^ source[l];
    }

    printf("\nTesto in chiaro: '%s'\n", (char *)source);
    printf("Testo cifrato (Hex):");
    printbin(encrypted, size_text);

    free(rc4);

    printf("\nRe-initializing RC4 for decryption...\n");
    rc4 = rc4_init(key, size_key);

    int8 *decrypted = malloc(sizeof(int8) * (size_text + 1));
    if (decrypted == NULL) {
        fprintf(stderr, "Errore allocazione memoria decrypted.\n");
        free(encrypted);
        free(rc4);
        return 1;
    }

    printf("Decrypting ciphertext...\n");
    for (int16 l = 0; l < size_text; l++) {
        decrypted[l] = rc4_byte(rc4) ^ encrypted[l];
    }
    decrypted[size_text] = '\0';

    printf("Testo decifrato ottenuto: '%s'\n", (char *)decrypted);

    free(encrypted);
    free(decrypted);
    free(rc4);

    return 0;
}
