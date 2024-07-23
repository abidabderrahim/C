#include <stdio.h>

int ft_strncmp(char *a1, char *a2, unsigned int n)
{
  unsigned int i = 0;
  int cmp;
  while((a1[i] != '\0' || a2[i] != '\0') && i < n)
  {
    cmp = a1[i] - a2[i];
    if (cmp != 0)
    {
      break;
    }
    i++;
  }
  return (cmp);
}

int main(void)
{
  char s1[100] = "";
  char s2[100] = "";
  int n = 0;
  printf("Enter string 1 : ");
  scanf("%s", s1);
  printf("Enter string 2 : ");
  scanf("%s", s2);
  printf("Enter number of point comp : ");
  scanf("%d", &n);
  printf("if 0 the strings are equals : %d\n", ft_strncmp(s1, s2, n));
  return 0;
}
