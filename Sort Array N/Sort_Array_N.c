#include <stdio.h>

void ft_sort_integere_table(int *tab, int size)
{
  int flag;
  int i;
  int temp;
  flag = 1;
  while (flag == 1)
  {
    flag = 0;
    i = 0;
    while (i < size - 1)
    {
      if (tab[i] > tab[i + 1])
      {
        temp = tab[i + 1];
        tab[i + 1] = tab[i];
        tab[i] = temp;
        flag = 1;
      }
      i++;
    }
  }
}

int main(void)
{
  int n = 0;
  printf("Enter array size : ");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter Array Number %d : ", i + 1);
    scanf("%d", &arr[i]);
  }
  ft_sort_integere_table(arr, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}
