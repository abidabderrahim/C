#include <stdio.h>
#include <time.h>

int main(void)
{
  time_t t = 1;
  struct tm* current_time;
  t = time(NULL);
  current_time = localtime(&t);
  printf("%02d : %02d : %02d\n", current_time->tm_hour, 
      current_time->tm_min, current_time->tm_sec);
  return 0;
}
