#include <stdio.h>
#include <stdlib.h>
#include "Regex.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./re MODE PATTERN STRING\n");
    } else {
        if (argv[1][0] == 'm') {
            if (match(argv[2], argv[3]))
                printf("Match\n");
            else
                printf("No match\n");
        } else if (argv[1][0] == 'f') {
        }
    }
    return EXIT_SUCCESS;
}
