#include <stdio.h>
#include <string.h>

int main()
{
  FILE *file;
  char filename[500] = "";
  printf("Enter File Name : ");
  scanf("%s", filename);
  file = fopen(filename, "r");
  if(file == NULL)
  {
    printf("Unable to open file \n");
    return -1;
  }
  
  int wordfound = 0;
  char word[20] = "";
  printf("Enter Word You Want to Check : ");
  scanf("%s", word);
  
  char buffer[1000];
  while(fgets(buffer, sizeof(buffer), file) != NULL)
  {
     printf("%s", buffer);
  
       if (strstr(buffer, word) != NULL)
       {
                wordfound = 1;
                break;
       }
  }
  
  if (wordfound)
  {
     printf("Word Exist .\n");
  }else
  {
     printf("Word Not Exist .\n");
  }

  fclose(file);
  return 0;
}
