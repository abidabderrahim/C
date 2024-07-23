#include <stdio.h>
#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
  int i = 0;
  while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}
void ft_swap(char **s1, char **s2)
{
  char *temp;
  temp = *s1;
  *s1 = *s2;
  *s2 = temp;
}
int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    int i = 1;
    while (i < argc - 1)
    {
      if (ft_strcmp(argv[i], argv[i + 1]) > 1)
      {
        ft_swap(&argv[i], &argv[i + 1]);
      }
      i++;
    }
    int k = 1;
    while (k < argc)
    {
      int v = 0;
      while (argv[k][v] != '\0')
      {
        write(1, &argv[k][v], 1);
        v++;
      }
      write(1, "\n", 1);
      k++;
    }
  }
  return (0);
}
