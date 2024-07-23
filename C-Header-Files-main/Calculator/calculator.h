#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>

void func(float n1, float n2, char op)
{
  switch(op)
  {
    case '+':
      printf("%d + %d = %d\n", (int)n1,(int)n2,((int)n1 + (int)n2));
      break;
    case '-':
      printf("%d - %d = %d\n", (int)n1,(int)n2,((int)n1 - (int)n2));
      break;
    case '*':
      printf("%d * %d = %d\n", (int)n1,(int)n2,((int)n1 * (int)n2));
      break;
    case '/':
      printf("%.2f / %.2f = %.2f\n", n1,n2,(n1 / n2));
      break;
    case '%':
      printf("%d %% %d = %d\n", (int)n1,(int)n2,((int)n1 % (int)n2));
      break;
    default:
      printf(" + - * / %% \n");
  }
}


#endif
