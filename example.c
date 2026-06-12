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
    int8 *key, *source, *encrypted;

    key = (int8 *)"8fA2bX9vE1mQ7zP4kL6wT9jR3cH5nG1p";
    size_key = strlen((char *)key);
    source = (int8 *)"Example. Verification code: 481516. Is the Arcfour "
                     "algorithm functioning correctly?";
    size_text = strlen((char *)source);

    printf("Initializing encryption...\n");
    rc4 = rc4_init(key, size_key);
    printf("Done.\n");

    printf("'%s'\n ->", source);
    encrypted = rc4_encrypt(source, size_text);

    if (encrypted != NULL) {
        printbin(encrypted, size_text);
    }

    return 0;
}
