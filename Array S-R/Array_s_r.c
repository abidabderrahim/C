#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *p;
  int size = 0;

  printf("Enter List Size : ");
  scanf("%d", &size);

  p = malloc(size * sizeof(int));
  
  if (p == NULL)
  {
    printf("Memory Allocation Failed\n");
    return -1;
  }

  for (int i = 0; i < size; i++)
  {
    printf("Fill Index %d : ", i + 1);
    scanf("%d", (p + i));
  }

  printf("This is your lits : ");
  for (int j = 0; j < size; j++)
  {
    printf("%d ", *(p + j));
  }
  printf("\n");
  return 0;
}
