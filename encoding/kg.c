#include <stdio.h>
#include <stdlib.h>

// Structure for an item which stores weight and value of item
struct Item {
    int value;
    int weight;
};

// A utility function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// A comparison function used by qsort
int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio2 = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}

// Greedy function to solve fractional knapsack problem
double fractionalKnapsack(int W, struct Item arr[], int n) {
    // Sort items by value/weight ratio
    qsort(arr, n, sizeof(arr[0]), compare);

    int currentWeight = 0;  // Current weight in knapsack
    double finalValue = 0.0; // Result (value in Knapsack)

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding Item won't overflow, add it completely
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            // If we can't add current Item, add fractional part of it
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break; // Break the loop since knapsack is full
        }
    }
    return finalValue;
}

// Driver program
int main() {
    int n, W;

    // Prompt user to enter the number of items and capacity of knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    // Allocate memory for items
    struct Item *arr = (struct Item *)malloc(n * sizeof(struct Item));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Prompt user to enter weight and value of each item
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &arr[i].weight);
        printf("Value: ");
        scanf("%d", &arr[i].value);
    }

    // Calculate maximum value in knapsack
    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    // Free allocated memory
    free(arr);

    return 0;
}
