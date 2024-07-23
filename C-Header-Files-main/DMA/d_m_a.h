#ifndef D_M_A_H
#define D_M_A_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char *text)
{
  char *str = malloc(sizeof(char) * strlen(text) + 1);
  if (str == NULL)
  {
    printf("Unable to Allocte Space .");
    return ;
  }
  strcpy(str, text);
  printf("%s", str);
  free(str);
}

#endif
