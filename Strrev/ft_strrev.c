#include <unistd.h>
#include <stdio.h>

char *ft_strrev(char *str)
{
  int i = 0;
  while(str[i] != '\0')
    i++;
  int j = 0;
  int c;
  while(j < i / 2)
  {
    c = str[j];
    str[j] = str[i - j - 1];
    str[i - j - 1] = c;
    j++;
  }
  return (str);
}

int main(void)
{
  char str[100] = "";
  printf("Enter string : ");
  scanf("%s", str);
  printf("reverse string is : %s\n", ft_strrev(str));
  return 0;
}
