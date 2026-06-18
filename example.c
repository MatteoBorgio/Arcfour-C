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

    // 1. CIFRATURA
    rc4 = rc4_init(key, size_key);
    encrypted = rc4_encrypt(rc4, source, size_text);

    printf("Testo originale: %s\n", (char *)source);
    printf("Cifrato (Hex):   ");
    if (encrypted != NULL)
        printbin(encrypted, size_text);

    rc4_ununit(rc4);

    // 2. DECIFRATURA
    rc4 = rc4_init(key, size_key);

    decrypted = rc4_decrypt(rc4, encrypted, size_text);

    if (decrypted != NULL) {
        printf("Decifrato:       ");
        for (int i = 0; i < size_text; i++)
            putchar(decrypted[i]);
        printf("\n");
    }

    // 3. PULIZIA FINALE
    free(encrypted);
    free(decrypted);
    rc4_ununit(rc4);

    return 0;
}
