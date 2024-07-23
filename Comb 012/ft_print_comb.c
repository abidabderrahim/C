#include <unistd.h>
#include <stdio.h>

void ft_print_comb(void)
{
  char i = '0';
  char j = '0';
  char k = '0';
  while (i <= '7')
  {
    j = i + 1;
    while (j <= '8')
    {
      k = j + 1;
      while (k <= '9')
      {
        write(1, &i, 1);
        write(1, &j, 1);
        write(1, &k, 1);
        if (i != '7') write (1, ", ", 2);
        k++;
      }
      j++;
    }
    i++;
  }
}

int main(void)
{
  printf("this is your combination numbers 012 to 789 : \n");
  ft_print_comb();
  write(1, "\n", 1);
  return 0;
}
