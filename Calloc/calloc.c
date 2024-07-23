#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i = 0;
  printf("Enter Number of Index : ");
  scanf("%d", &i);

  int *p = (int*)calloc(i, sizeof(i));
  if (p == NULL)
    return -1;

  for (int j = 0; j < i; j++)
  {
    printf("Enter Index %d : ", j + 1);
    scanf("%d", (p + j));
  }
  
  printf("this is your list : ");
  for (int k = 0; k < i; k++)
  {
    printf("%d ", *(p + k));
  }
  
  printf("\n");
  free(p);

  return 0;
}
