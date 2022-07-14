#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("How many scores? ");
    // Объявляю переменную массива размером n:
    int scores[n];

    int sum_of_scores = 0;
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score: ");
        sum_of_scores = sum_of_scores + scores[i];
    }

    printf("Average is %f\n", (sum_of_scores) / (n * (1.0)));
}