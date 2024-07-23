#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include <stdio.h>

void func(int i, int j)
{
  if (i > j)
    printf("%d > %d\n", i, j);
  else if (i == j)
    printf("%d == %d\n", i, j);
  else
    printf("%d < %d\n", i, j);
}

#endif

