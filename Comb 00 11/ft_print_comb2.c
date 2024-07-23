#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_print_comb2(void)
{
  int i = 0;
  int j = 0;
  while (i <= 98)
  {
    j = i + 1;
    while (j <= 99)
    {
      ft_putchar(i / 10 + '0');
      ft_putchar(i % 10 + '0');
      write (1, " ", 1);
      ft_putchar(j / 10 + '0');
      ft_putchar(j % 10 + '0');
      if (i != 98) write (1, ", ", 2);
      j++;
    }
    i++;
  }
}

int main(void)
{
  printf("this is your combinations 00 01 to 98 99 : \n");
  ft_print_comb2();
  write(1, "\n", 1);
  return 0;
}
