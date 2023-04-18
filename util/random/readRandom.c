#include <stdio.h>
#include <stdlib.h>

/**
 * Gets random numbers from file "random1m.txt"
 *
 * @param maxLines The number of random numbers to get
 * @return int*
 */
int *getRandoms(int maxLines)
{
    FILE *randomFile = fopen("data/random1m.txt", "r");
    int *x = (int *)malloc(maxLines * sizeof(int *));

    for (int i = 0; i < maxLines; i++)
    {
        fscanf(randomFile, "%ld", x + i);
    }

    return x;
}

// int main(int argc, char const *argv[])
// {
//     int nMax = 100;
//     int *x = getRandoms(nMax);
//     for (int i = 0; i < nMax; i++)
//         printf("%4d >>> %d\n", i + 1, x[i]);
//     return 0;
// }
