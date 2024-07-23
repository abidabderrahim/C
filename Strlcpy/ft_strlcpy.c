#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
  unsigned int i;
  unsigned int j;
  i = 0;
  while (dest[i] != '\0')
    i++;
  j = 0;
  while (src[j] != '\0' && j < size)
  {
    dest[i++] = src[j++];
  }
  dest[i] = '\0';
  return (j);
}

int main(void)
{
  char src[] = "";
  char dest[] = "hello ";
  printf("%s\n", dest);
  printf("fill the string : ");
  scanf("%s", src);
  printf("this is the new lenght add %d\n", ft_strlcpy(dest, src, 5));
  printf("and this is new string : %s\n", dest);
  return (0);
}
