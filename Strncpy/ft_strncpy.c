#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
  unsigned int i = 0;
  while (src[i] != '\0' && i < n)
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
  int n = 0;
  printf("Enter a string : ");
  scanf("%s", src);
  printf("Enter number of characters you want to copy : ");
  scanf("%d", &n);
  printf("your copy string is : %s\n", ft_strncpy(dest, src, n));
  return 0;
}
