#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
  int *p;
  int min_point;
  int size_range = max - min;
  if (min >= max)
    p = ((void*)0);
  p = (int *)malloc(sizeof(*p) * (max - min));
  min_point = min;
  while(min < max)
  {
    p[min - min_point] = min;
    min++;
  }
  *range = p;
  return (size_range);
}

int main(void)
{
  int *tab;
  int a = 0;
  int b = 0;
  printf("Enter number 1 : ");
  scanf("%d", &a);
  printf("Enter number 2 : ");
  scanf("%d", &b);
  int size_range = ft_ultimate_range(&tab, a, b);
  printf("range size :%d \n", size_range);
  printf("this the number in this range : ");
  for (int i=0; i < 5; i++)
  {
    printf("%d ", tab[i]);
  }
  printf("\n");
  return 0;
}
