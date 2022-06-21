// do
// {

// }
// while (boolean-expr);

#include <cs50.h>
#include <stdio.h>
// unistd.h - подключаю функцию sleep
#include <unistd.h>

int main(void)
{
  int x;
  do
  {
    x = get_int("Type in number bigger then 1\n");
  } while (x < 1);
  printf("x is %x\n", x);
}