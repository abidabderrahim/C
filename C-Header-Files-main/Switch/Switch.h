#ifndef SWITCH_H
#define SWITCH_H

#include <stdio.h>

void func(int i)
{
  switch(i)
  {
    case 1:
      printf("/ \n");
      break;
    case 2:
      printf("// \n");
      break;
    case 3:
      printf("/// \n");
      break;
    default:
      printf("the Numbercan be 1 , 2 , 3 \n");
  }
}

#endif
