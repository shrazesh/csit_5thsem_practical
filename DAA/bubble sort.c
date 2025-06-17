#include <stdio.h> 

void bubble_sort(int arr[], int n) { 

int i,j; 

    for (i = 0; i < n - 1; i++) { 

        int swapped = 0; 

        for (j = 0; j < n - i - 1; j++) { 

            if (arr[j] > arr[j + 1]) { 

                int temp = arr[j]; 

                arr[j] = arr[j + 1]; 

                arr[j + 1] = temp; 

                swapped = 1; 

            	} 

        	} 

        if (!swapped) break; 

    } 

} 

void print_array(int arr[], int n) { 

int i; 

    for (i = 0; i < n; i++) 

        printf("%d ", arr[i]); 

    printf("\n"); 

} 

int main() { 

    int arr[] = {5, 12, 7, 35, 22, 42, 23}; 
    printf("\t Bubble sort \n");
    printf("given array : 5, 12, 7, 35, 22, 42, 23 \n");

    int n = sizeof(arr) / sizeof(arr[0]); 

    bubble_sort(arr, n); 

    printf("Sorted array: "); 

    print_array(arr, n); 
    printf("\t Shrajesh Shrestha \n");

    return 0; 

}	 
