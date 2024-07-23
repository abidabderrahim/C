#include <stdio.h>

void ft_is_negative(int n)
{
  if (n >= 0)
    printf("your number is Positive .\n");
  else
    printf("your number is Negative .\n");
}

int main(void)
{
  int i = 0;
  printf("Enter a number : ");
  scanf("%d", &i);
  ft_is_negative(i);
  return 0;
}
