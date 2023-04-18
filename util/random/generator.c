#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double getRandom() {
    return (rand() * 3 % 100000) / 100000.0;
}

int *generateRandints(int low, int high, int n) {
    int *randints = (int *) malloc(n * sizeof(int *));
    printf("randints = %d\n", randints == NULL);
    for (int i = 0; i < n; i++) {
        randints[i] = low + (int)(getRandom() * (high - low));
    }
}

// int main(int argc, char const *argv[])
// {
//     time_t t; 
//     srand((unsigned)time(&t));
//     // srand((unsigned int)**main + (unsigned int)&argc + (unsigned int)time(NULL));
//     // srand(rand() % 100 / 10);
//     // time_t t; 
//     // srand((unsigned)time(&t));
//     // printf("%.7f\n", getRandom());
//     // printf("%.7f\n", getRandom());
//     // printf("%.7f\n", getRandom());
//     // printf("%.7f\n", getRandom());
//     // printf("%.7f\n", getRandom());
//     // printf("%.7f\n", getRandom());
//     // printf("%.7f\n", getRandom());
//     // printf("%.7f\n", getRandom());

//     int n = 5;
//     int *rands = generateRandints(-10, 10, n);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", rands[i]);
//     }
//     printf("\n");
//     return 0;
// }
