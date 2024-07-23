#include "ft_mini_printf.h"

int main(void)
{
  ft_mini_printf("hello %s\n", "abid");
  int count = ft_mini_printf("I am  %s\n", "abderrahim abid");
  ft_mini_printf("count of characters is %d\n", count);
  return (0);
}
