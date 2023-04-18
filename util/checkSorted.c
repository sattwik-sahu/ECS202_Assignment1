#include <stdio.h>

/**
 * @brief Checks if the given array is sorted in ascending or descending order.
 *
 * @param x The array to check if sorted
 * @return int
 */
int checkSorted(int *x, int size)
{
    int reverse = x[1] < x[0];
    for (int i = 2; i < size; i++)
    {
        if (reverse == (x[i] > x[i - 1]))
        {
            return 0;
        }
    }
    return 1;
}

// int main(int argc, char const *argv[])
// {
//     double x[] = {1, 2, -5};
//     printf("%d\n", checkSorted(x, 3));
//     return 0;
// }
