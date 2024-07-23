#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    int i = 1;
    while (i < argc)
    {
      int j = 0;
      while (argv[i][j])
      {
        write(1, &argv[i][j], 1);
        j++;
      }
      write (1, " ", 1);
      i++;
    }
    write(1, "\n", 1);
  }
  return (0);
}
