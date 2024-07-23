#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char text[100] = "";
  printf("Enter Some Text : ");
  fgets(text, 100, stdin);
  char *m = malloc(sizeof(char) * strlen(text) + 1);
  if (m == NULL)
    return 1;
  strcpy(m, text);
  printf("%s", m);
  free(m);
  return 0;
}
