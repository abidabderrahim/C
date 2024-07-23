#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
  int i;
  char *p;
  i = 0;
  while (src[i] != '\0')
    i++;
  int size = i;
  p = (char *)malloc(sizeof(char) * size);
  if (p == 0)
    return (p);
  i = 0;
  while (src[i] != '\0')
  {
    p[i] = src[i];
    i++;
  }
  p[i] = '\0';
  return (p);
}

int main(void)
{
  char src[] = "";
  printf("Enter a string : ");
  scanf("%s", src);
  char *dest = ft_strdup(src);
  printf("hear your string duplicate in dest : %s \n", dest);
  return (0);
}
