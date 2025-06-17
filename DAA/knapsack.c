#include <stdio.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
    float ratio;
};

// Function to compare items based on value/weight ratio
int compare(const void *a, const void *b) {
    float ratio1 = ((struct Item *)a)->ratio;
    float ratio2 = ((struct Item *)b)->ratio;
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}

// Function to solve Fractional Knapsack problem
float fractionalKnapsack(int W, struct Item arr[], int n) {
    int currentWeight = 0;    // Current weight in the knapsack
    float finalValue = 0.0;   // Final value of items taken
    int i, remainingWeight;

    // Calculate the value/weight ratio for each item
    for (i = 0; i < n; i++) {
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    // Sort items by value/weight ratio in decreasing order
    qsort(arr, n, sizeof(arr[0]), compare);

    // Loop through all the items
    for (i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((float)remainingWeight / arr[i].weight);
            break; // Knapsack is full
        }
    }
    
    return finalValue;
}

// Driver function
int main() {
    int n, W;
    int i;
    printf("\t Fractioal Knapsack Problem \n");

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    struct Item arr[n];  // Declare array of items

    // Input items' values and weights
    for (i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    // Calling the fractionalKnapsack function to get the maximum value
    float maxValue = fractionalKnapsack(W, arr, n);
    
    // Output the result
    printf("Maximum value in Knapsack = %.2f\n", maxValue);
printf("\t Shrajesh Shrestha \n");
    return 0;
}

