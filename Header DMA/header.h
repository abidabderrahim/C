#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

void func(int *data, int size)
{
  printf("this is your list : ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", data[i]);
  }
  printf("\n");
}

#endif
