#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
  int i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

int main(void)
{
  char src[100] = "";
  char dest[100] = "";
  printf("Enter string : ");
  scanf("%s", src);
  printf("your string copyed to new stting : %s\n", ft_strcpy(dest, src));
  return 0;
}
