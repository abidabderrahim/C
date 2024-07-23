#ifndef LOOP_H
#define LOOP_H

#include <stdio.h>

void func(int n)
{
  printf("Numbers Between 1 and %d : ", n);
  for (int i = 1; i <= n; i++)
  {
    printf("%d ", i);
  }
  printf("\n");
}

#endif
