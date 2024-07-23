#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    int i = 0;
    while (argv[0][i] != '\0')
    {
      write (1, &argv[0][i], 1);
      i++;
    }
    write(1, "\n", 1);
  }
  return (0);
}
