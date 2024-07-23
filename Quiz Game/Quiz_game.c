#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show_record()
{
  system("clear");
  char name;
  FILE *f;
  f=fopen("score.txt", "r");
  if (f==NULL)
  {
    perror("Error whit file open proccess.\n");
    exit(EXIT_FAILURE);
  }
  while ((name=fgetc(f) != EOF))
  printf("%c", name);
  getchar();
}

void reset_score()
{
  system("clear");
  float sc;
  char nm[20];
  FILE *f;
  f=fopen("score.txt", "w");
  sc=0;
  fprintf(f,"%s,%.2f", nm, sc);
  fclose(f);
}

void help()
{
  system("clear");
    printf("\n=-=-=-=-=-=-=-=-=-= Welcom To Quiz Game =-=-=-=-=-=-=-=-=-=");
    printf("\n\n |hear are some tips you might wanna know before playing!|");
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n");
    printf("\n >> there are 2 rounds in this Quiz game : ");
    printf("\n\t 1 : WARMUP Round .");
    printf("\n\t 2 : CHALLENGE Round .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> in warmup round will be asked 6 questions to test you .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> for all , you are allow to play if you give at lest 2");
    printf("\n    right answer , other whise you can't process furtheer");
    printf("\n    to the challenge .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> your game starts with challenge round in this round  ");
    printf("\n    you will be asked total of 23 questions each right   ");
    printf("\n    answer will awarded $100.000 !!! , by this way you   ");
    printf("\n    can up to ONE MILLION cash prize!!!!! .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> you will be given 4 options and you have to press A , B ");
    printf("\n    , C , D for the right options .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >>you will be asked questions continously , till right ");
    printf("\n   answer are given .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> no negative marking for wrong answers !");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\n Press Enter key for back to the menu !");
}

void edit_score(float score, char pn[20])
{
  system("clear");
  float sc;
  char nm[20];
  FILE *f;
  f=fopen("score.txt", "w");
  fscanf(f, "%s%f", nm, &sc);
  if (score >= sc)
  {
    sc=score;
    fclose(f);
    f=fopen("score.txt", "w");
    fprintf(f,"%s\n%.2f", pn, sc);
    fclose(f);
  }
}

int main()
{
  int counter, r, s, count, i , j;
  float score;
  char choice;
  char player_name[20];
  time_t t;

  time(&t);
  printf("=-=-=-=-=-=-= Your Name Pleas =-=-=-=-=-=-=\n\t\t   ");
  fgets(player_name, 20, stdin);
mainhome:
  printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
  printf("\n\t Welcom To Quize Game %s ", player_name);
  printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("\n => Press S to start the game !");
  printf("\n => Press V to view the highest score !");
  printf("\n => Press R to reset score !");
  printf("\n => Press H for help !");
  printf("\n => Press Q to quit the game !");
  printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

  for (i = 0; i < 60; i++)
  {
    printf("=");
  }
  printf("\nCurrent date and time : %s", ctime(&t));
  for (i = 0; i < 60; i++)
  {
    printf("=");
  }
  printf("\n\n");
  choice = toupper(getchar());
  getchar();
  if (choice == 'S')
  {
    system("clear");
    printf("\n=-=-=-=-=-=-=-=-=-= Welcom To Quiz Game =-=-=-=-=-=-=-=-=-=");
    printf("\n\n |hear are some tips you might wanna know before playing!|");
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n");
    printf("\n >> there are 2 rounds in this Quiz game : ");
    printf("\n\t 1 : WARMUP Round .");
    printf("\n\t 2 : CHALLENGE Round .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> in warmup round will be asked 6 questions to test you .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> for all , you are allow to play if you give at lest 2");
    printf("\n    right answer , other whise you can't process furtheer");
    printf("\n    to the challenge .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> your game starts with challenge round in this round  ");
    printf("\n    you will be asked total of 23 questions each right   ");
    printf("\n    answer will awarded $100.000 !!! , by this way you   ");
    printf("\n    can up to ONE MILLION cash prize!!!!! .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> you will be given 4 options and you have to press A , B ");
    printf("\n    , C , D for the right options .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >>you will be asked questions continously , till right ");
    printf("\n   answer are given .");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n >> no negative marking for wrong answers !");
    printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n\n\n Press Y To Start The Game !\n");
    printf("\n Press any Other Key To Return To The Main Menu !\n");

    if (toupper(getchar()) == 'Y')
    {
      goto home;
    }
    else
    {
      system("clear");
      goto mainhome;
    }
  }
  if (choice == 'H')
  {
    help();
    getchar();
    system("clear");
    goto mainhome;
  }else if (choice == 'V')
  {
    show_record();
    goto mainhome;
  }else if (choice == 'R')
  {
    reset_score();
    getchar();
    goto mainhome;
  }else if (choice == 'Q')
  {
    system("clear");
    printf("\n\n=-=-=-=-=-=-=-=-= Tanks For playing =-=-=-=-=-=-=-=-=-=\n\n");
    exit(1);
  }else
  {
    printf("Please You Have to Choose Some Options !");
    system("clear");
    goto mainhome;
  }

home:
  system("clear");
  count=0;
  for (i = 1; i <= 6; i++)
  {
    getchar();
    system("clear");
    s = i;
    switch(s)
    {
      case 1:
        printf("\n\nWhat is Tunisia ?");
        printf("\n\nA.Car   B.Disease\n\nC.Country   D.Animal\n\n");
        if (toupper(getchar()) == 'C')
        {
          printf("\n\nCorrect !!!");
          getchar();
          count++;
          break;
        }else
        {
          printf("\n\nWrong !!! Tunisia is Country !\n");
          getchar();
          break;
        }
      case 2:
        printf("\n\n\nWhere is Tunisia ?");
        printf("\n\nA.America     B.Asia\n\nC.Africa    D.Europe\n\n");
        if (toupper(getchar()) == 'C')
        {
          printf("\n\nCorrect !!!");
          getchar();
          count++;
          break;
        }else
        {
          printf("\n\nWrong !!! Tunisia in Africa !\n");
          getchar();
          break;
        }
      case 3:
        printf("\n\n\nWhat is the Currency of Tunisia ?");
        printf("\n\nA.Dollar   B.Dinar\n\nC.Franc   D.Euro\n\n");
        if (toupper(getchar()) == 'B')
        {
          printf("\n\nCorrect !!!");
          getchar();
          count++;
          break;
        }else
        {
          printf("\n\nWrong !!! Tunisia Currency is Dinar !\n");
          getchar();
          break;
        }
      case 4:
        printf("\n\n\nWhat is the Capital of Tunisia ?");
        printf("\n\nA.Mahres   B.Tunis\n\nC.Sousse   D.Gafsa\n\n");
        if (toupper(getchar()) == 'B')
        {
          printf("\n\nCorrect !!!");
          getchar();
          count++;
          break;
        }else
        {
          printf("\n\nWrong Capital of Tunisia is Tunis !\n");
          getchar();
          break;
        }
      case 5:
        printf("\n\n\nWhat is the language of Tunisia ?");
        printf("\n\nA.Fransh   B.Arabic\n\nC.English   D.Bambara\n\n");
        if (toupper(getchar()) == 'B')
        {
          printf("\n\nCorrect !!!");
          getchar();
          count++;
          break;
        }else
        {
          printf("\n\nWrong language of Tunisia is Arabic");
          getchar();
          break;
        }
      case 6:
        printf("\n\n\nWhat is the religon of Tunisia ?");
        printf("\n\nA.Christianity   B.Hiduism\n\nC.Buddhism   D.Islam\n\n");
        if (toupper(getchar()) == 'D')
        {
          printf("\n\nCorrect !!!");
          getchar();
          count++;
          break;
        }else
        {
          printf("\n\nWrong religon of Tunisia is Islam");
          getchar();
          break;
        }
    }
  }
  printf("\nthe number of corect answer = %d", count);
  if (count >= 2)
  {
    goto quiz;
  }else
  {
    system("clear");
    printf("\n\nSory You Are Not Eligible to Play Game");
    getchar();
    goto mainhome;
  }
quiz:
  system("clear");
  printf("\n\n\t=-= Congratulation %s You Are Eligible To Play =-=", player_name);
  printf("\n\n\n\n\t Press P to Start the Game ! \n");
  if (toupper(getchar()) == 'P')
  {
    goto game;
  }else 
  {
    goto mainhome;
  }

game:
  system("clear");
  count = 0;
  for (i = 1; i <= 10; i++)
  {
    getchar();
    system("clear");
    r = i;
    switch(r)
    {
      case 1:
        printf("\n\nHow many contries are in Africa ?");
        printf("\n\nA.13   B.14\n\nC.54   D.53\n");
        if (toupper(getchar()) == 'C')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer is C\n");
          getchar();
          goto score;
          break;
        }
      case 2:
        printf("\n\nStudy of Earthquake is called ... ?");
        printf("\n\nA.Seimology   B.Cosmology\n\nC.Orology   D.Etimology\n");
        if(toupper(getchar()) == 'A')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer is A\n");
          getchar();
          goto score;
          break;
        }
      case 3:
        printf("\n\nWhere is evrest mount ?");
        printf("\n\nA.Algeria   B.Mali\n\nC.China   D.Brazil\n");
        if(toupper(getchar()) == 'C')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer is C\n");
          getchar();
          goto score;
          break;
        }
      case 4:
        printf("\n\nthe laws of electrimagentic induction were given by ?");
        printf("\n\nA.Faraday   B.Tesla\n\nC.Maxwel   D.Coulomb\n");
        if (toupper(getchar()) == 'A')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer is A\n");
          getchar();
          goto score;
          break;
        }
      case 5:
        printf("\n\nIn what unit is electric power measured ?");
        printf("\n\nA.Coulomb   B.Watt\n\nC.Power   D.Units \n");
        if (toupper(getchar()) == 'B')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer is B\n");
          getchar();
          goto score;
          break;
        }
      case 6:
        printf("\n\nWhich element is found in Vitamin B12?");
        printf("\n\nA.Zinc   B.Cobalt\n\nC.Calcium   D.Iron\n");
        if(toupper(getchar()) == 'B')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer is B\n");
          getchar();
          goto score;
          break;
        }
      case 7:
        printf("\n\nWhich is the slowest animal ?");
        printf("\n\nA.Tutle   B.Three-toed-sloth\n\nC.Worm   D.Snail\n");
        if(toupper(getchar()) == 'B')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer is B\n");
          getchar();
          goto score;
          break;
        }
      case 8:
        printf("\n\nWhat is the capital of Denemark ?");
        printf("\n\nA.copenhagen   B.Helsinki\n\nC.Ajax   D.Galatasary\n");
        if (toupper(getchar()) == 'A')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer is A\n");
          getchar();
          goto score;
          break;
        }
      case 9:
        printf("\n\nWhich is the lognest River in the Word ?");
        printf("\n\nA.Nile   B.Koshi\n\nC.Ganga   D.Amazon\n");
        if (toupper(getchar()) == 'A')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer is A\n");
          getchar();
          goto score;
          break;
        }
      case 10:
        printf("\n\nwhat is the color of blackbox in aeroplanes?");
        printf("\n\nA.White   B.Black\n\nC.Orange   D.Red\n");
        if(toupper(getchar()) == 'C')
        {
          printf("\n\nCorrect !!!");
          count++;
          getchar();
          break;
        }else
        {
          printf("\n\nWrong answer C\n");
          getchar();
          goto score;
          break;
        }
    }
  }
score:
  system("clear");
  score=(float)counter*100000;
  if (score>0.00 && score<1000000)
  {
    printf("\n\n\n=-=-=-= CONGRATULATION =-=-=-=");
    printf("\n\n You Won $%.2f", score);
    goto go;
  }
  else if (score <= 1000000.00)
  {
    printf("\n\n\n=-=-=-= CONGRATULATION =-=-=-=");
    printf("\n\n You Won $%.2f", score);
    printf("\n\n THANK YOU \n\n");
  }else
  {
    printf("\n\n=-=-=-= SORRY YOU DIDN'T WIN =-=-=-=\n\n");
    printf("\n\n THANKS FOR YOUR TIME .\n");
    goto go;
  }

go:
  puts("\n\nPress Y if you wnat to play next game : ");
  puts("\n\nPress any Key for go main menum \n");
  if (toupper(getchar()) == 'Y')
  {
    goto home;
  }else
  {
    edit_score(score, player_name);
    goto mainhome;
  }
}











