#include <stdio.h>

char *ft_strlowcase(char *str)
{
  int i = 0;
  while(str[i] != '\0')
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] += 32;
    }
    i++;
  }
  str[i] = '\0';
  return (str);
}

int main(void)
{
  char str[100] = "";
  printf("Enter string : ");
  scanf("%s",str);
  printf("your string is : %s\n", ft_strlowcase(str));
  return 0;
}
