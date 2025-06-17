#include <stdio.h> 

void selection_sort(int arr[], int n)  

{ 

int i,j; 

    for (i = 0; i < n - 1; i++) { 

        int min_idx = i; 

        for (j = i + 1; j < n; j++) { 

            if (arr[j] < arr[min_idx]) { 

                min_idx = j; 

            } 

        } 

        int temp = arr[i]; 

        arr[i] = arr[min_idx]; 

        arr[min_idx] = temp; 

    } 

} 

void print_array(int arr[], int n)  

{ 

int i; 

    	for (i = 0; i < n; i++) 

        		printf("%d ", arr[i]); 

    	printf("\n"); 

} 

 

int main()  

{ 

    int arr[] = {12, 5, 25, 31, 20, 7, 44}; 
    printf("\t Selection  sort \n");
    printf("given array : 12, 5, 25, 31, 20, 7, 44 \n");

    int n = sizeof(arr) / sizeof(arr[0]); 

    selection_sort(arr, n); 

    printf("Sorted array: "); 

    print_array(arr, n); 
    printf("\t Shrajesh Shrestha \n");

    return 0; 

} 

 
