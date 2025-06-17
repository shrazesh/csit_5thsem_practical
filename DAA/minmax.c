#include <stdio.h> 

void find_min_max(int arr[], int n, int *min, int *max)  

{ 

int i; 

    *min = *max = arr[0]; 

    for (i = 1; i < n; i++) { 

        if (arr[i] < *min) 

            *min = arr[i]; 

        if (arr[i] > *max) 

            *max = arr[i]; 

    } 

} 

int main()  

{ 

    int arr[] = {7, 15, 35, 6, 22, 18, 55, 4, 39}; 
    printf("\ Min-Max Algorithm \n");
    printf("given array : 7, 15, 35, 6, 22, 18, 55, 4, 39 \n");

    int n = sizeof(arr) / sizeof(arr[0]); 

    int min, max; 

    find_min_max(arr, n, &min, &max); 

    printf("Minimum: %d, Maximum: %d\n", min, max); 
    printf("\t Shrajesh Shrestha \n");

    return 0; 

} 
