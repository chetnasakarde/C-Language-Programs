// File: mini_json.c
#include <stdio.h>
#include <string.h>

void parse_json(const char* json) {
    char key[50], value[50];
    const char* p = json;
    while (*p) {
        if (*p == '"') {
            p++;
            char* k = key;
            while (*p && *p!='"') *k++ = *p++;
            *k='\0'; p+=3; // skip ":"
            char* v=value;
            while (*p && *p!='"') *v++=*p++;
            *v='\0';
            printf("%s => %s\n", key, value);
        }
        p++;
    }
}

int main() {
    char json[] = "{\"name\":\"Chetna\",\"event\":\"Hacktoberfest\",\"year\":\"2025\"}";
    parse_json(json);
    return 0;
}
