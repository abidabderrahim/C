#include <stdio.h>

char *ft_strncat(char *dest, char *src, int nb)
{
  int i = 0;
  while (dest[i] != '\0')
    i++;
  dest[i] = ' ';
  i = i + 1;
  int j = 0;
  while (src[j] != '\0' && j < nb)
  {
    dest[i] = src[j];
    i++;
    j++;
  }
  dest[i] = '\0';
  return (dest);
}

int main(void)
{
  char src[100] = "";
  char dest[100] = "";
  int n = 0;
  printf("Enter string 1 : ");
  scanf("%s", dest);
  printf("Enter string 2 : ");
  scanf("%s", src);
  printf("Enter number of concate characters : ");
  scanf("%d", &n);
  printf("your string is : %s\n", ft_strncat(dest, src, n));
  return (0);
}
