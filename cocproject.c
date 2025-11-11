#include <stdio.h>
#include <stdlib.h>  // for rand() and srand()
#include <time.h>    // for time()

// Function to roll one die (returns number 1–6)
int roll_one_die() {
    return (rand() % 6) + 1;
}

int main() {
    int count[13] = {0}; // Array for sums 0–12 (we’ll use 2–12 only)
    long total_rolls = 1000000; // 1 million rolls
    int die1, die2, sum;

    srand(time(0)); // seed random number generator

    // Simulation
    for (long i = 0; i < total_rolls; i++) {
        die1 = roll_one_die();
        die2 = roll_one_die();
        sum = die1 + die2;
        count[sum]++; // increment that sum’s count
    }

    // Print results
    printf("Sum\tCount\t\tProbability (%%)\n");
    printf("-----------------------------------\n");

    for (int s = 2; s <= 12; s++) {
        double probability = (double)count[s] / total_rolls * 100;
        printf("%2d\t%8d\t\t%.2f%%\n", s, count[s], probability);
    }

    return 0;
}
