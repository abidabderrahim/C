#include "Struct.h"

int main()
{
  char name[50] = "";
  int age = 0;

  printf("Enter Your Name : ");
  scanf("%s", name);

  printf("Enter Your Age : ");
  scanf("%d", &age);
  
  Data p1;

  p1.age = age;
  strcpy(p1.name,name);
  printf("Your Name is : %s \n", p1.name);
  printf("Your Age is : %d \n", p1.age);

  return 0;
}
