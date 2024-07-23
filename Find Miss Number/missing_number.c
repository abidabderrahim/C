#include <stdio.h>

int main(void)
{
  int n;
  int s;
  s = 0;
  printf("Enter Number OF List With Missing Number: ");
  scanf("%d", &n);
  for (int i = 1; i < n; i++)
  {
    int a;
    printf("Enter Number %d: ", i);
    scanf("%d", &a);
    s+=a;
  }
  // we use this simple calc for find the missing 
  // number : n * n + 1 / 2 - set of list .
  printf("Missing Number is : %d\n", n*(n+1)/2-s);
  return 0;
}
