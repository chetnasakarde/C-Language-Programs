// File: mini_shell.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 100

int main() {
    char input[MAX];
    char *args[10];
    while (1) {
        printf("mini-shell> ");
        fgets(input, MAX, stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "exit") == 0) break;
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL) args[++i] = strtok(NULL, " ");
        pid_t pid = fork();
        if (pid == 0) execvp(args[0], args);
        else wait(NULL);
    }
    return 0;
}
