#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    int i = argc - 1;
    while (i > 0)
    {
      int j = 0;
      while (argv[i][j] != '\0')
      {
        write(1, &argv[i][j], 1);
        j++;
      }
      write(1, " ", 1);
      i--;
    }
    write(1, "\n", 1);
  }
  return (0);
}
