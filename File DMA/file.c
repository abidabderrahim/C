/* load large file into memory with C language .*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int C_SIZE = 100;

char **load_large_file(char *filename, int *length)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Unable to open file \n .");
    return NULL;
  }

  int list_len = C_SIZE;
    
  char **lines = malloc(list_len * sizeof(char *));

  char buffer[1000];
  int i = 0;
  while(fgets(buffer, 1000, file) != NULL)
  {
    if (i == list_len)
    {
      list_len += C_SIZE;
      char **newlines = realloc(lines, list_len * sizeof(char *));
      if (!newlines)
      {
        fprintf(stderr, "Cant' Allocate .\n");
        exit(1);
      }
      lines = newlines;
    }
    buffer[strlen(buffer)] = '\0';
    int strl = strlen(buffer);
    char *str = malloc((strl + 1) * sizeof(char));
    strcpy(str, buffer);
    lines[i] = str;
    i++;
  }
  *length = i;
  return lines;
}

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    fprintf(stderr, "Must Define File Name \n .");
    exit(1);
  }

  int length = 0;
  char **content = load_large_file(argv[1], &length);
  printf("File Legnth : %d \n", length);

  for (int i = 0; i < length; i++)
  {
    printf("%s", content[i]);
  }
  return 0;
}
