#include <stdio.h>

int ft_recursive_factorial(int nb)
{
  if(nb == 0 || nb == 1)
    return 1;
  return (nb * ft_recursive_factorial(nb - 1));
}

int main(void)
{
  int p = 0;
  printf("Enter a number : ");
  scanf("%d", &p);
  int i = ft_recursive_factorial(p);
  printf("Factorial of %d is %d\n",p, i);
  return 0;
}
