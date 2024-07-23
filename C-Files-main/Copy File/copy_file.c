#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 500
#define BUFFER_SIZE 1000

int main()
{
  FILE *file1;
  
  char filename[MAX_FILENAME_LENGTH] = "";
  char newfile[MAX_FILENAME_LENGTH] = "";
  
  printf("Enter SRC File : ");
  scanf("%s", filename);
  printf("Enter DEST File : ");
  scanf("%s", newfile);

  file1 = fopen(filename, "r");
  if (file1 == NULL)
  {
    printf("Unable to open file \n");
    return -1;
  }

  FILE *file2;
  file2 = fopen(newfile, "w");
  
  if (file2 == NULL)
  {
    printf("Unable to open file \n");
    fclose(file1);
    return -1;
  } 
  
  char buffer[BUFFER_SIZE];
  size_t bytesRead;
  
  while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), file1)) > 0)
  {
    fwrite(buffer, sizeof(char), bytesRead, file2);
  }
  
  fclose(file2);
  
  printf("File Copyed \n");
  return 0;
}






