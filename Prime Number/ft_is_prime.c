#include <stdio.h>

int ft_is_prime(int nb)
{
  if (nb == 0 || nb == 1)
    return 0;
  int i = 2;
  while (i < nb / 2)
  {
    if (nb % i == 0)
      return (0);
    i++;
  }
  return (1);
}

int main(void)
{
  int p = 0;
  printf("Enter a number : ");
  scanf("%d", &p);
  int i = ft_is_prime(p);
  if (i == 1)
  {
    printf("your number is prime .\n");
  }else
  {
    printf("your number is not prime .\n");
  }
  return 0;
}
