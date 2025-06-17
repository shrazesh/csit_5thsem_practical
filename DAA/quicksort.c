#include <stdio.h> 

void swap(int *a, int *b)  

{ 

    int temp = *a; 

    *a = *b; 

    *b = temp; 

} 

int partition(int arr[], int low, int high)  

{ 

int i,j; 

    int pivot = arr[high];   

    i = (low - 1); 

    for (j = low; j < high; j++) { 

        if (arr[j] < pivot) { 

            i++; 

            swap(&arr[i], &arr[j]); 

        } 

    } 

    swap(&arr[i + 1], &arr[high]); 

    return (i + 1); 

} 

void quick_sort(int arr[], int low, int high)  

{ 

    if (low < high) { 

        int pi = partition(arr, low, high); 

        quick_sort(arr, low, pi - 1); 

        quick_sort(arr, pi + 1, high); 

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

    int arr[] = {13, 7, 48, 22, 11, 5, 36, 19}; 
    printf("\t Quick Sort \n");
    printf("given array : 13, 7, 48, 22, 11, 5, 36, 19\n");

    int n = sizeof(arr) / sizeof(arr[0]); 

    quick_sort(arr, 0, n - 1); 

    printf("Sorted array: "); 

    print_array(arr, n); 
    printf("\t Shrajesh Shrestha \n");

    return 0; 

} 
