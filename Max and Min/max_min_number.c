#include <stdio.h>

char *ft_min_max_number(int a, int b)
{
  return a > b ? "1 is max number and 2 is min number ." :\
    "1 min number and 2 is max number .";
}

int main(void)
{
  int a = 0;
  int b = 0;
  printf("Enter number 1: ");
  scanf("%d", &a);
  printf("Enter number 2: ");
  scanf("%d", &b);
  printf("%s\n", ft_min_max_number(a, b));
  return 0;
}
