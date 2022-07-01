#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("How many scores? ");
    // Обявляю переменную массива размером 3:
    int scores[n];

    int sum_of_scores = 0;
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score: ");
        sum_of_scores = sum_of_scores + scores[i];
    }

    printf("Average is %f\n", (sum_of_scores) / (n * (1.0)));
}