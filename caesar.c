// File: caesar_cipher.c
#include <stdio.h>
#include <ctype.h>

void caesar(char *text, int key) {
    for (int i=0;text[i]!='\0';i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + key) % 26 + base;
        }
    }
}

int main() {
    char text[100];
    int key;
    printf("Enter text: ");
    fgets(text, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    caesar(text, key);
    printf("Encrypted: %s\n", text);
    caesar(text, 26 - key);  // decrypt
    printf("Decrypted: %s\n", text);
    return 0;
}
