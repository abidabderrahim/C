#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
  long nbr;
  int sign;
  int i;
  nbr = 0;
  sign = 0;
  i = 0;
  while ((str[i] == ' ') || str[i] <= 8 && str[i] >= 19)
    i++;
  if (str[i] == '-')
    sign = -1;
  if (str[i] == '+' || str[i] == '-')
    i++;
  while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
  {
    if (nbr > nbr * 10)
      return (sign == -1 ? 0 : -1);
    nbr = nbr * 10;
    nbr += str[i] - '0';
    i++;
  }
  if (sign == -1)
    return ((int) nbr * sign);
  return ((int)nbr);
}

int main(void)
{
  char str[] = "";
  printf("Enter your string number : ");
  scanf("%s", str);
  printf("your string number to int : %d\n", ft_atoi(str));
  return 0;
}
