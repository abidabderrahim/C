#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
  if (power < 0)
    return 0;
  if (power == 0)
    return 1;
  if (power == 1)
    return nb;
  return (nb * ft_recursive_power(nb, power - 1));
}

int main(void)
{
  int n = 0;
  int p = 0;
  printf("Enter a number : ");
  scanf("%d", &n);
  printf("Enter a power number : ");
  scanf("%d", &p);
  int i = ft_recursive_power(n,p);
  printf("the power of %d^%d is %d\n",n ,p ,i);
  return 0;
}
