// Conditionals without break
#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int x = get_int("Prompt: ");
  switch (x)
  {
  case 5:
    printf("Five!\n");
  case 4:
    printf("Four!\n");
  case 3:
    printf("Three!\n");
  case 2:
    printf("Two!\n");
  case 1:
    printf("One!\n");
  default:
    printf("Blast-off\n");
  }
}