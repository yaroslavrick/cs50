
// for (int i = 0; i < 10; i++)
// {
//
// }

//
// for (start; expr; increment)
// {
//
// }

#include <cs50.h>
#include <stdio.h>
// unistd.h - подключаю функцию sleep
#include <unistd.h>

int main(void)
{
  for (int i = 0; i < 100; i++)
  {
    printf("i is eq to %i\n", i);
    sleep(1);
  }
}