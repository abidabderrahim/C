#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char name[50] = "";
  printf("Enter Your FullName : ");
  fgets(name, 50, stdin);

  char *n = malloc(sizeof(char) * strlen(name) + 1);
  if (n == NULL)
  {
    return -1;
  }

  strcpy(n, name);
  printf("hello %s", n);

  free(n);
  return 0;
}
