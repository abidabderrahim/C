#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *list = calloc(5, sizeof(int));
  if (list == NULL)
    return -1;

  printf("This is the original list : ");
  for (int i = 0; i < 5; i++)
  {
    list[i] = i + 1;
    printf("%d ", list[i]);
  }
  printf("\n");

  int size  = 0;
  printf("Enter Number of New Indexes : ");
  scanf("%d", &size);

  int *new_list = realloc(list, size * sizeof(int));
  if (new_list == NULL)
  {
    free(list);
    return -1;
  }

  for (int j = 0; j < size; j++)
  {
    printf("Enter New index %d : ", j + 6);
    scanf("%d", (new_list + j + 5));
  }

  list = new_list;

  printf("this is your new list : ");
  for (int k = 0; k < (5 + size); k++)
  {
    printf("%d ", list[k]);
  }
  printf("\n");

  free(list);
  return 0;
}
