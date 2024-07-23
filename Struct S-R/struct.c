#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[50];
  int age;
}Data;


int main()
{
  char *name = malloc(50 * sizeof(char));
  int *age = malloc(sizeof(int));

  if (name && age == NULL)
    return -1;

  printf("Enter Your Name : ");
  scanf("%s", name);

  printf("Enter Your Age : ");
  scanf("%d", age);

  Data p1;

  strcpy(p1.name,name);
  p1.age = *age;

  printf("this is your name %s \n", p1.name);
  printf("this is your age %d \n", p1.age);

  free(name);
  free(age);
  return 0;
}
