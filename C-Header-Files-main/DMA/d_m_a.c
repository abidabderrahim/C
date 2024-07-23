#include "d_m_a.h"

int main()
{
  char text[100] = "";
  printf("Enter Some Text : ");
  fgets(text, 100, stdin);
  func(text);
  return 0;
}
