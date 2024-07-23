#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  int hour, minute, second;
  hour = 0;
  minute = 0;
  second = 0;
  while (1)
  {
    system("clear"); // clear the screen .
    printf("%02d : %02d : %02d", hour, minute, second);
    fflush(stdout); // clear the output buffer of gcc .
    second ++;
    if (second == 60)
    {
      minute += 1;
      second = 0;
    }
    if (minute == 60)
    {
      hour += 1;
      minute = 0;
    }
    if (hour == 24)
    {
      hour  = 0;
      minute = 0;
      second = 0;
    }
    sleep(1);
  }
  return (0);
}
