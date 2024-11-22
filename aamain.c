#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileutil.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int size;
    char **lines = loadFileAA(argv[1], &size);

    char target[256];
    while (1) {
        printf("Enter a string to search (or DONE to quit): ");
        fgets(target, sizeof(target), stdin);
        target[strcspn(target, "\n")] = '\0';  // Remove newline

        if (strcmp(target, "DONE") == 0) {
            break;
        }

        char *result = substringSearchAA(target, lines, size);
        if (result) {
            printf("Found: %s\n", result);
        } else {
            printf("Not found\n");
        }
    }

    freeAA(lines, size);  
    return 0;
}
