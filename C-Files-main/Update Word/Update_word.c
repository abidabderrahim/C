#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[100] = "";
    const char searchWord[100] = "";
    char replaceWord[100] = "";

    printf("Enter File Name : ");
    scanf("%s", filename);

    printf("Enter Word : ");
    scanf("%s", searchWord);

    printf("Enter Replace Word : ");
    scanf("%s", replaceWord);

    file = fopen(filename, "r+");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return -1;
    }

    char buffer[1000];
    long currentPosition, newPosition;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *wordLocation = strstr(buffer, searchWord);
        while (wordLocation != NULL) {
            // Calculate the position of the word in the buffer
            int position = wordLocation - buffer - 1;

            // Calculate the current position in the file
            currentPosition = ftell(file);

            // Calculate the new position for writing
            newPosition = currentPosition - (strlen(buffer) - position);

            // Move to the new position for writing
            fseek(file, newPosition, SEEK_SET);

            // Write the replacement word
            fputs(replaceWord, file);

            // Move back to the end of the file
            fseek(file, 0, SEEK_END);

            // Find the next occurrence of the search word
            wordLocation = strstr(wordLocation + strlen(replaceWord), searchWord);
        }
    }

    // Add a new line at the end of the file
    fprintf(file, "\n");

    fclose(file);

    printf("Word '%s' has been replaced with '%s' in the file.\n", searchWord, replaceWord);

    return 0;
}

