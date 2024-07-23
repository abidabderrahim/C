#include <stdio.h>

void ft_ultimate_ft(int *********nbr, int n)
{
  *********nbr = n;
}

int main(void)
{
  int n = 0;
  printf("Enter number : ");
  scanf("%d", &n);
  int nb = 0;
  int *nbr1 = &nb;
  int **nbr2 = &nbr1;
  int ***nbr3 = &nbr2;
  int ****nbr4 = &nbr3;
  int *****nbr5 = &nbr4;
  int ******nbr6 = &nbr5;
  int *******nbr7 = &nbr6;
  int ********nbr8 = &nbr7;
  int *********nbr9 = &nbr8;
  ft_ultimate_ft(nbr9, n);
  printf("this your number after dereferencing : %d\n", nb);
  return 0;
}
