#ifndef CHECK_ODD_EVEN_H
#define CHECK_ODD_EVEN_H

#include <stdio.h>

void func(int i)
{
  if ((i % 2) == 0)
    printf("%d is even number .\n", i);
  else
    printf("%d is odd number .\n", i);
}

#endif
