#include <stdio.h>

int main()
{

  FILE *file;
  char filename[100] = "";
  int line = 0;
  int line_count = 1;

  printf("Enter Your File Name : ");
  scanf("%s", filename);

  printf("Enter Line Number : ");
  scanf("%d", &line);

  file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Unable To Open File \n");
    return -1;
  }

  char buffer[1000] = "";
  while(fgets(buffer, sizeof(buffer), file ) != NULL)
  {
    if(line_count == line)
    {
      printf("%s",buffer);
      break;
    }
    line_count++;
  }

  fclose(file);

  return 0;
}
