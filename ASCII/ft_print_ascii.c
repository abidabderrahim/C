#include <stdio.h>

int main(void)
{
  char i;
  for (i = 33; i <= '~'; i++)
  {
      printf("char %c decimal %d hex %x \n", i, i, i);
  }
  return 0;
}

