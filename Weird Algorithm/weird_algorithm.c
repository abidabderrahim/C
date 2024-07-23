#include <stdio.h>

int main(void)
{
  int n = 0;
  printf("Enter Number :");
  scanf("%d", &n);
  if (n == 1)
    return 0;
  start:
  if (n % 2 == 0 && n != 0)
  {
    n = n / 2;
    printf("%d", n);
    if (n != 1)
      printf(" -> ");
  }
  else if (n % 2 == 1 && n != 0)
  {
    n = (n * 3) + 1;
    printf("%d", n);
    if (n != 1)
      printf(" -> ");
  }
  if (n != 1 && n != 0)
    goto start;
  printf("\n");
  return 0;
}
