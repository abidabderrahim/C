#include <stdio.h>

int main()
{
  FILE *file;
  const char *filename = "../data.txt";
  file = fopen(filename, "r");
  if (file != NULL)
  {
    printf("FILE '%s' EXIST \n", filename);
    fclose(file);
  }
  else
    printf("FILE '%s' NOT EXIST \n");
  return 0;
}
