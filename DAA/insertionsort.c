#include <stdio.h> 

void insertion_sort(int arr[], int n) { 

int i,j; 

    for (i = 1; i < n; i++) { 

       	int key = arr[i]; 

        	int j = i - 1; 

        	while (j >= 0 && arr[j] > key) { 

            	arr[j + 1] = arr[j]; 

            	j--; 

        	} 

       	arr[j + 1] = key; 

    } 

} 

void print_array(int arr[], int n) { 

int i; 

    for (i = 0; i < n; i++) 

        printf("%d ", arr[i]); 

    printf("\n"); 

} 

int main() { 

    int arr[] = {10, 5, 17, 20, 43, 33, 12}; 
    printf("\t Insertion sort \n");
    printf("given array : 10, 5, 17, 20, 43, 33, 12 \n");

    int n = sizeof(arr) / sizeof(arr[0]); 

    insertion_sort(arr, n); 

    printf("Sorted array: "); 

    print_array(arr, n); 
    printf("\t Shrajesh Shrestha \n");

    return 0; 

} 
