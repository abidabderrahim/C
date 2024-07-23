#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(0)); // current time as srand for random numbers .
  int m = 0;
  int n = 0;
  printf("Enter the max random number : ");
  scanf("%d", &m);
  printf("Enter the count of random numbers : ");
  scanf("%d", &n);
  printf("your %d random number is : ", n);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", rand() % m + 1);
  }
  printf("\n");
  return (0);
}
