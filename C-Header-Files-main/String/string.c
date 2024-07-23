#include "string.h"

int main()
{
  char name[50] = "";
  printf("What is Your Name : ");
  scanf("%s", name);
  func(name);
  return 0;
}
