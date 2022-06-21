#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int x = get_int("Prompt: ");
  switch (x)
  {
  case 1:
    printf("one\n");
    break;
  case 2:
    printf("two\n");
    break;
  case 3:
    printf("three\n");
    break;
  default:
    printf("Sorry!\n");
  }
}
