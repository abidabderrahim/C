#include <stdio.h>
#include <stdlib.h>

void func(char *name)
{
  printf("hello %s\n", name);
}

int main()
{
  char *name = calloc(50, sizeof(50));
  printf("Enter Your Name : ");
  scanf("%s", name);

  func(name);

  return 0;
}
