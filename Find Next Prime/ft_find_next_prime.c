#include <stdio.h>

int ft_find_prime(int nb)
{
  if(nb <= 1)
    return 0;
  int i = 2;
  while (i <= nb / 2)
  {
    if (nb % i == 0)
      return 0;
    i++;
  }
  return 1;
}

int ft_find_next_prime(int nb)
{
  if (ft_find_prime(nb) == 1)
    return (nb);
  else return (ft_find_next_prime(nb + 1));
}

int main(void)
{
  int p = 0;
  printf("Enter your number : ");
  scanf("%d", &p);
  int i = ft_find_next_prime(p);
  printf("your prime or next prime is : %d\n", i);
  return 0;
}
