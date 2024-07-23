#include <stdio.h>

int ft_strcmp(char *a1, char *a2)
{
  int i = 0;
  while(a1[i] == a2[i] && (a1[i] != '\0' || a2[i] != '\0'))
    i++;
  return (a1[i] - a2[i]);
}

int main(void)
{
  char s1[100] = "";
  char s2[100] = "";
  printf("Enter string 1 : ");
  scanf("%s", s1);
  printf("Enter string 2 : ");
  scanf("%s", s2);
  printf("if 0 the string is equal : %d\n", ft_strcmp(s1, s2));
  return 0;
}
