#include <stdio.h>

char *ft_strcat(char *dest, char *src)
{
  int j = 0;
  while (dest[j] != '\0')
    j++;
  dest[j] = ' ';
  j = j + 1;
  int i = 0;
  while (src[i] != '\0')
  {
    dest[j] = src[i];
    j++;
    i++;
  }
  dest[j] = '\0';
  return (dest);
}

int main(void)
{
  char src[100] = "";
  char dest[100] = "";
  printf("Enter a string 1 : ");
  scanf("%s", dest);
  printf("Enter a string 2 : ");
  scanf("%s", src);
  printf("this your string : %s\n", ft_strcat(dest, src));
  return (0);
}
