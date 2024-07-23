#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
  int *p;
  int min_point;
  if (min >= max)
    p = ((void*)0);
  p = (int *)malloc(sizeof(*p) * (max - min));
  min_point = min;
  while (min < max)
  {
    p[min - min_point] = min;
    min++;
  }
  return (p);
}

int main(void)
{
  int a = 0;
  int b = 0;
  printf("Enter a number 1 : ");
  scanf("%d", &a);
  printf("Enter a number 2 : ");
  scanf("%d", &b);
  int *tab = ft_range(a,b);
  printf("this is the number between range : ");
  for (int i = 0; i < 5; i++)
  {
    printf("%d ", tab[i]);
  }
  printf("\n");
  return (0);
}
