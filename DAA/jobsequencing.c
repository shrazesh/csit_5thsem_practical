#include <stdio.h>

struct Job {
    int id;
    int dead;
    int profit;
};

int compare(struct Job arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].profit < arr[j].profit) {
                struct Job temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int findMaxDeadline(struct Job arr[], int n) {
    int maxDeadline = arr[0].dead;
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i].dead > maxDeadline)
            maxDeadline = arr[i].dead;
    }
    return maxDeadline;
}

void jobSequence(struct Job arr[], int n) {
    int maxDeadline = findMaxDeadline(arr, n);
    int slots[maxDeadline];
    int currentWeight = 0;
    int finalValue = 0.0;
    int i, remainingWeight;

    for (i = 0; i < maxDeadline; i++) {
        slots[i] = -1;
    }

    int totalProfit = 0;
    int jobsCount = 0;
    compare(arr, n);

    for (i = 0; i < n; i++) {
    	int j;
        for (j = arr[i].dead - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = arr[i].id;
                totalProfit += arr[i].profit;
                jobsCount++;
                break;
            }
        }
    }

    printf("Number of jobs selected: %d\n", jobsCount);
    printf("Total Profit: %d\n", totalProfit);
    printf("Jobs Selected: ");
    for (i = 0; i < maxDeadline; i++) {
        if (slots[i] != -1) {
            printf("Job %d ", slots[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("\t Job Sequencing Problem \n");

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job arr[n];

    for (i = 0; i < n; i++) {
        printf("Enter Job %d ID, Deadline, and Profit: ", i + 1);
        scanf("%d %d %d", &arr[i].id, &arr[i].dead, &arr[i].profit);
    }

    jobSequence(arr, n);
    printf("\t Shrajesh Shrestha \n");

    return 0;
}

