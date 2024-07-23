#ifndef ARG_C_V_H
#define ARG_C_V_H

#include <stdio.h>

void func(int argc, char *argv[])
{
  if (argc > 1)
  {
    int i = 1;
    printf("this is your arguments : ");
    while(i < argc)
    {
      printf("%s ", argv[i]);
      i++;
    }
    printf("\n");
  }
}

#endif
