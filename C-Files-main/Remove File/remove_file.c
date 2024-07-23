#include <stdio.h>

int main()
{
  char filename[] = "";
  printf("Enter Your File Name : ");
  scanf("%s", filename);
  if (remove(filename) == 0)
    printf("FILE '%s' HAS BEEN REMOVED .\n", filename);
  else
    printf("Unable to remove file '%s' .\n", filename);
  return 0;
}
