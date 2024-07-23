#include <stdio.h>

int main()
{
  FILE *file;
  file = fopen("../data.txt", "r");
  if (file == NULL)
  {
    printf("UNable to Open the file\n");
    return -1;
  }
  char buffer[1000];
  while(fgets(buffer, sizeof(buffer), file) != NULL)
  {
    printf("%s", buffer);
  }
  fclose(file);
  return 0;
}
