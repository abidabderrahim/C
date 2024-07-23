#include <stdio.h>

int main()
{
  FILE *file;
  file = fopen("../data.txt", "a");
  if (file == NULL)
  {
    printf("Unable to open file .\n");
    return -1;
  }
  char text[] = "hello world\n";
  fwrite(text, sizeof(char), sizeof(text) - 1, file);
  fclose(file);
  printf("Text has ben appended to the file . \n");
  return 0;
}
