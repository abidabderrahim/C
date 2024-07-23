#include <stdio.h>

char *ft_strstr(char *str, char *to_find)
{
  int i;
  int j;
  int k;
  int found;

  i = 0;
  while(str[i] != '\0')
  {
    k = 0;
    j = i;
    found = j;
    while(to_find[k] != '\0')
    {
      if (str[j] != to_find[k])
        found = -1;
      k++;
      j++;
    }
    if (found != -1)
      return (str + found);
    i++;
  }
  return (0);
}

int main(void)
{
  char str[100] = "";
  char to_find[100] = "";
  printf("Enter string : ");
  scanf("%s", str);
  printf("Enter string for serach : ");
  scanf("%s", to_find);
  char *found = ft_strstr(str, to_find);
  if (found != "\0")
    printf("your string start from %s\n", found);
  return 0;
}
