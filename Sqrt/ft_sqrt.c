#include <stdio.h>

int ft_sqrt(int nb)
{
  int i = 1;
  while(i <=  nb)
  {
    if (i * i == nb)
      return (i);
    i++;
  }
  return (0);
}

int main(void)
{
  int sqrt = 0;
  printf("Enter the Number : ");
  scanf("%d", &sqrt);
  int i = ft_sqrt(sqrt);
  printf("sqrt of %d is %d\n",sqrt,  i);
  return 0;
}
