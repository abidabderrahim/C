#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char menu()
{
  printf("\n1 --- storing \n");
  printf("2 --- display \n");
  printf("3 --- number of words\n");
  printf("4 --- reverse\n");
  printf("0 --- exit\n");
  return (getchar());
}

char *storing()
{
  char array[80];
  char *type = NULL;
  printf("\ntype : ");
  fgets(array, 80, stdin);
  type = malloc(strlen(array) + 1);
  strcpy(type , array);
  return type;
}
void display(char array[])
{
  puts("\n");
  puts(array);
}

void reverse(char *type)
{
  int counter1, counter2;
  char character;
  for (counter1 = 0,counter2 = strlen(type); counter1 < counter2/2; counter1++)
  {
    character = type[counter1];
    type[counter1] = type[counter2 - counter1 - 1];
    type[counter2 - counter1 - 1] = character;
  }
}
int words(char *array)
{
  int counter1, counter2;
  int words = 0;
  for (counter1 = 0, counter2 = strlen(array); counter1 < counter2; counter1++)
  if ((array[counter1 + 1] == ' ' || array[counter1 + 1] == '\0') && array[counter1] != ' ')
  words++;
  return words;
}

int main(void)
{
  char choice;
  char *type = "";
  while((choice = menu()) != '0')
  {
    getchar();
    switch(choice)
    {
      case '1' : type = storing(); break;
      case '2' : display(type); break;
      case '3' : printf("\nnumber of words = %d\n", words(type)); break;
      case '4' : reverse(type); break;
      default : printf("try more time .");
    }
    printf("\n return to the menu \n");
  }
}

