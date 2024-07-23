#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  const int MIN = 1;
  const int MAX = 100;
  int guess;
  int guesses;
  int answer;
  srand(time(0));
  answer = (rand() % MAX) + MIN; // 1 to 100 .
  do{
    printf("Enter your guess: ");
    scanf("%d", &guess);
    if (guess > answer)
      printf("to height < .\n");
    else if (guess < answer)
      printf("to low > .\n");
    else
      printf("\ncorrect!\n");
    guesses++;
  }while(guess != answer);
  printf("\n**************\n");
  printf("answer: %d\n", answer);
  printf("guesses : %d\n", guesses);
  printf("***************\n");
  return (0);
}
