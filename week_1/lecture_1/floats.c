# include <cs50.h>
# include <stdio.h>

int main(void)
{
  double x = get_double("float x:");
  double y = get_double("float y:");

  printf("x / y = %.50f\n", x / y);
}