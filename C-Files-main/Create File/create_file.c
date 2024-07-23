#include <stdio.h>

int main()
{
  FILE *file;
  char filename[100] = "";
  printf("Enter File Name : ");
  scanf("%s", filename);
  
  file = fopen(filename, "w");
  if(file == NULL)
  {
    printf("Unable to Open file \n");
    return -1;
  }
  char text[] = "";
  fwrite(text, sizeof(char), sizeof(text) - 1, file);
  fclose(file);
  printf("File Created . \n");
  return 0;
}
