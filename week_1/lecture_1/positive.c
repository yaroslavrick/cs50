# include <cs50.h>
# include <stdio.h>

int get_positive_int(string_prompt);

int main(void)
{
  int i = get_positive_int("Positive integer: ");
  printf("%i\n", i);
}

int get_positive_int(string_prompt)
{
  // вне вигурных скобок {} необьявленные заранее переменные не видны
  // поэтому я обьявляю переменную n заранее, пустой
  int n;
  // Робити наступне поки менше за 1
  // do {something} while (сondition)
  do 
  {
    n = get_int(prompt);
  }
  while (n < 1);
  return n;
}