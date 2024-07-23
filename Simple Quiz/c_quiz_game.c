#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int score = 0;

  char questions[][100] = {"1. what is C language?:", 
                            "2. who create C language?:",
                            "3. what is the predecessor of C?:"};

  char options[][100] = {"A. programming language .",
                          "B. Scripting language .",
                          "A. Dennis Ritchie .", 
                          "B. Nikola Tesla .",
                          "A. Objective C .", 
                          "B. B ."};

  char answers[3] = {'A', 'A', 'B'};

  int numberQ = sizeof(questions) / sizeof(questions[0]);
  char guess;

  printf("***QUIZ GAME***\n");
  for (int i = 0; i < numberQ; i++)
  {
    printf("#############################\n");
    printf("%s\n", questions[i]);
    printf("#############################\n");
    for (int j = (i * 2); j < (i * 2) + 2; j++)
    {
      printf("%s\n", options[j]);
    }
    printf("your answer : ");
    scanf(" %c", &guess);
    guess = toupper(guess);
    if (guess == answers[i])
    {
      printf("***CORRECT!***\n");
      score++;
    }else
    {
      printf("$$$WRONG!$$$\n");
    }
  }
  printf("\nFINAL SCORE! : %d/%d\n", score, numberQ);
  return 0;
}
