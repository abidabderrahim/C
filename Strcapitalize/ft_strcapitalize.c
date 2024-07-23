#include <stdio.h>

char *ft_strcapitalize(char *str)
{
  int i;
  int flag;
  i = 0;
  flag = 1;
  while(str[i] != '\0')
  {
    if (str[i] >= 'a' && str[i] <= 'z' && flag == 1)
    {
      str[i] -= 32;
      flag = 0;
    }else if (str[i] >= 'A' && str[i] <= 'Z' && flag == 0)
      str[i] += 32;
    else if (str[i] >= '0' && str[i] <= '9')
      flag = 0;
    else if ((str[i] < 'a' || str[i] > 'z') && 
                            (str[i] < 'A' || str[i] > 'z'))
      flag = 1;
    else if (str[i] >= 'A' && str[i] <= 'Z' && flag == 1)
      flag = 0;
    i++;
  }
  return (str);
}

int main(void)
{
  char str[] = "";
  printf("Enter string : ");
  scanf("%s", str);
  printf("string capitalize first character : %s\n", ft_strcapitalize(str));
  return (0);
}

