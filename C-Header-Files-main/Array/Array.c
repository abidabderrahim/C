#include "Array.h"

int main()
{
  int size;
  printf("Enter the Size of Array : ");
  scanf("%d", &size);

  if (size == 0)
  {
    printf("This Is Your List : 0 .\n");
    return -1;
  }

  for (int i = 0; i < size; i++)
  {
    printf("Fill Index %d : ", i + 1);
    scanf("%d", &arr[i]);
  }

  printf("This Is Your List : ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}
