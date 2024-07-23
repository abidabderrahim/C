#include "calculator.h"

int main()
{
  float n1, n2;
  char op;

  printf("Enter Number 1 : ");
  scanf("%f", &n1);

  printf("Enter Number 2 : ");
  scanf("%f", &n2);

  printf("Enter Operator (+ - * / %%) : ");
  scanf(" %c", &op);

  func(n1, n2, op);

  return 0;
}
