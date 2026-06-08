#include "arcfour.h"

int main(void);

int main() {
    Arcfour *rc4;
    int16 size_key, size_text;
    char *key, *source, *encrypted, *decrypted;

    key = "8fA2bX9vE1mQ7zP4kL6wT9jR3cH5nG1p";
    size_key = strlen(key);
    source = "Example. Verification code: 481516. Is the Arcfour algorithm "
             "functioning correctly?";
    size_text = strlen(source);

    printf("Initializing encryption...\n");
    rc4 = rc4_init(key, size_key);
    printf("Done.\n");

    printf("'%s'\n ->", source);
    encrypted = rc4_encrypt(source, size_text);
}
