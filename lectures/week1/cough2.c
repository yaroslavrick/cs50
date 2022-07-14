#include <stdio.h>

void cough(void);

int main(void)
{
  for (int i = 0; i < 3; i++)
  {
    cough();
  }

}

// void - пустой
void cough(void)
{
  printf("cough\n");
}
