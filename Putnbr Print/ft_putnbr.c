#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putnbr(int nb)
{
  long nbr = nb;
  if (nbr < 0)
  {
    nbr *= -1;
    write(1, "-", 1);
  }
  if (nbr / 10 == 0)
  {
    ft_putchar(nbr + 48);
  }
  if (nbr > 9)
  {
    ft_putnbr(nbr / 10);
    ft_putchar((nbr % 10) + 48);
  }
}

int main(void)
{
  int n = 0;
  printf("Enter number for print without printf : ");
  scanf("%d", &n);
  ft_putnbr(n);
  printf("\n");
  return 0;
}
