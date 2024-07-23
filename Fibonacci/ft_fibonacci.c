#include <stdio.h>

int ft_fibonacci(int index)
{
  if (index < 0)
    return -1;
  if (index == 0)
    return 0;
  if (index == 1)
    return 1;
  return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int main(void)
{
  int fb = 0;
  printf("Enter a number : ");
  scanf("%d", &fb);
  int i = ft_fibonacci(fb);
  printf("fibonaccie of %d is %d\n",fb, i);
  return 0;
}
