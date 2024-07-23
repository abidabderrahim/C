#include <stdio.h>

int main()
{
  FILE *file;
  file = fopen("new_file.txt", "w");
  if(file == NULL)
  {
    printf("Unable to Open file \n");
    return -1;
  }
  char text[] = "hello world!\n";
  fwrite(text, sizeof(char), sizeof(text) - 1, file);
  fclose(file);
  printf("Text has ben Written to the new_file \n");
  return 0;
}
