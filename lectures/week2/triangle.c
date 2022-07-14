#include <cs50.h>
#include <stdio.h>

// Declare functions:
float user_input_side_of_triangle(int counter_of_sides);
float sum_of_two_sides(float x, float y);
bool sum_is_greater(float sum_of_two_sides, float side_three);
int valid_triangle(bool side_one, bool side_two, bool side_three);

int main(void)
{
    // Counter for name of sides:
    int counter_of_sides = 1;

    // Prompting user for input side 1:
    int a = user_input_side_of_triangle(counter_of_sides);

    // Name side is now 1+1 = 2:
    counter_of_sides++;

    // Prompting user for input side 2:
    int b = user_input_side_of_triangle(counter_of_sides);

    // Name side is now 2+1 = 3:
    counter_of_sides++;
    int c = user_input_side_of_triangle(counter_of_sides);

    // Calculating sum of two sides:
    float sum_a_b = sum_of_two_sides(a, b);
    float sum_a_c = sum_of_two_sides(a, c);
    float sum_b_c = sum_of_two_sides(b, c);

    // Is sum of two sides is greater then third?
    bool ab_greater_then_c = sum_is_greater(sum_a_b, c);
    bool ac_greater_then_b = sum_is_greater(sum_a_c, b);
    bool bc_greater_then_a = sum_is_greater(sum_b_c, a);

    // Is triangle valid?
    valid_triangle(ab_greater_then_c, ac_greater_then_b, bc_greater_then_a);
}

// Functions:

// Prompting user for input one side of triangle:
float user_input_side_of_triangle(int counter_of_sides)
{
    int x;
    // A triangle may only have sides with positive length
    do
    {
        x = get_float("Type in length of side %i of triangle: ", counter_of_sides);
    } while (x < 0);

    return x;
}

// Calculating sum of two sides:
float sum_of_two_sides(float x, float y)
{
    float z = x + y;
    return z;
}

// Is sum of two sides is greater then third?
bool sum_is_greater(float sum_of_two_sides, float side_three)
{
    if (sum_of_two_sides > side_three)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Is triangle valid?
int valid_triangle(bool side_one, bool side_two, bool side_three)
{
    // A triangle is a valid triangle, If and only If, the sum of any two sides of a triangle is greater than the third side.For Example, let A, B and C are three sides of a triangle.Then, A + B > C, B + C > A and C + A > B.
    if (side_one && side_two && side_three)
    {
        return printf("Triangle is valid!\n");
    }
    else
    {
        return printf("Triangle is invalid!\n");
    }
}
