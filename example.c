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
    int8 *key, *source, *encrypted, *decrypted;

    key = (int8 *)"8fA2bX9vE1mQ7zP4kL6wT9jR3cH5nG1p";
    size_key = strlen((char *)key);
    source = (int8 *)"Example. Verification code: 481516. Is the Arcfour "
                     "algorithm functioning correctly?";
    size_text = strlen((char *)source);

    printf("Initializing encryption...\n");
    rc4 = rc4_init(key, size_key);

    printf("Encrypting...\n");
    encrypted = rc4_encrypt(rc4, source, size_text);

    printf("\nTesto originale: '%s'\n", (char *)source);
    printf("Testo cifrato (Hex):");
    if (encrypted != NULL) {
        printbin(encrypted, size_text);
    }

    free(rc4);

    printf("\nRe-initializing for decryption...\n");
    rc4 = rc4_init(key, size_key);

    printf("Decrypting...\n");
    decrypted = rc4_encrypt(rc4, encrypted, size_text);

    if (decrypted != NULL) {
        printf("Testo decifrato: ");
        for (int i = 0; i < size_text; i++) {
            putchar(decrypted[i]);
        }
        printf("\n");
    }

    free(encrypted);
    free(decrypted);
    free(rc4);

    return 0;
}
