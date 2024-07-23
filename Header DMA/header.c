#include "header.h"

int main()
{
  int size = 0;
  printf("Enter Size of List : ");
  scanf("%d", &size);

  int *data = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++)
  {
    printf("Enter Number Index %d : ", i + 1);
    scanf("%d", &data[i]);
  }

  func(data, size);

  free(data);
  return 0;
}
