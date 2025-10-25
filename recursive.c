// File: dir_tree.c
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void print_tree(const char *path, int level) {
    DIR *dir = opendir(path);
    if (!dir) return;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name,"..")==0) continue;
        for (int i=0; i<level; i++) printf("  ");
        printf("├── %s\n", entry->d_name);

        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(fullpath, &st)==0 && S_ISDIR(st.st_mode))
            print_tree(fullpath, level+1);
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *path = (argc > 1) ? argv[1] : ".";
    printf("Directory Tree of %s\n", path);
    print_tree(path, 0);
    return 0;
}
