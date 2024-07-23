#include <stdio.h>

#define TRUE 1
#define FALSE 0

int days_number_in_month[] = {0,31,28,31,30,31,30,31,30,31,31,30,31,30,31};
char *months[] = 
{
  " ",
  "\n\n\nJanuary",
  "\n\n\nFebruary",
  "\n\n\nMarch",
  "\n\n\nApril",
  "\n\n\nMay",
  "\n\n\nJune",
  "\n\n\nJuly",
  "\n\n\nAugust",
  "\n\n\nSeptember",
  "\n\n\nOctober",
  "\n\n\nNovember",
  "\n\n\nDecember"
};

int print_year(void)
{
  int year;
  printf("enter the the year: ");
  scanf("%d", &year);
  return year;
}

int determine_year(int year)
{
  if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
  {
    days_number_in_month[2] = 29;
    return (1);
  }else
  {
    days_number_in_month[2] = 28;
    return (0);
  }
}

int determine_day(int year)
{
  int day_print;
  int d1, d2, d3;
  d1 = (year - 1.)/4.0;
  d2 = (year - 1.)/100.;
  d3 = (year - 1.)/400.;
  day_print = (year + d1 - d2 + d3) % 7;
  return day_print;
}

void calendar(int year, int day_print)
{
  int month, day;
  for (month = 1; month <= 12; month++)
  {
    printf("%s", months[month]);
    printf("\n\n Sun Mon Tue Wed Thu Fri Sat\n");
    for (day = 1; day <= 1 + day_print * 5; day ++)
    {
      printf(" ");
    }
    for (day = 1; day <= days_number_in_month[month]; day++)
    {
      printf("%2d", day);
      if ((day + day_print) % 7 > 0)
        printf("   ");
      else 
        printf("\n ");
    }
    day_print = (day_print + days_number_in_month[month]) % 7;
  }
}

int main (void)
{
  int year, day_print, year_print;
  year = print_year();
  day_print = determine_day(year);
  determine_year(year);
  calendar(year, day_print);
  printf("\n");
}

