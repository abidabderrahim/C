#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
  int i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int main(void)
{
  char str[] = "";
  printf("Enter a string : ");
  scanf("%s", str);
  int i = ft_strlen(str);
  printf("string lenght is : %d\n", i);
  return 0;
}
