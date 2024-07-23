#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    int numStrings = 0;
    printf("Hello Enter Numbers of Strings : ");
    scanf("%d", &numStrings);

    char** arrayOfStrings = (char**)malloc(numStrings * sizeof(char*));

    if (arrayOfStrings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < numStrings; ++i) {
        arrayOfStrings[i] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));

        if (arrayOfStrings[i] == NULL) {
            printf("Memory allocation for string %d failed.\n", i + 1);

            for (int j = 0; j < i; ++j) {
                free(arrayOfStrings[j]);
            }
            free(arrayOfStrings);

            return 1;
        }

        printf("Enter string %d: ", i + 1);

        if (fgets(arrayOfStrings[i], MAX_STRING_LENGTH, stdin) == NULL) {

            printf("Error reading input.\n");

            for (int j = 0; j <= i; ++j) {
                free(arrayOfStrings[j]);
            }
            free(arrayOfStrings);

            return 1;
        }

        size_t len = strlen(arrayOfStrings[i]);
        if (len > 0 && arrayOfStrings[i][len - 1] == '\n') {
            arrayOfStrings[i][len - 1] = '\0';
        }
    }

    for (int i = 0; i < numStrings; ++i) {
        printf("String %d: %s\n", i + 1, arrayOfStrings[i]);
    }

    for (int i = 0; i < numStrings; ++i) {
        free(arrayOfStrings[i]);
    }
    free(arrayOfStrings);

    return 0;
}

