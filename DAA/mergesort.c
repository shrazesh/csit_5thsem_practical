#include <stdio.h> 

void merge(int arr[], int left, int mid, int right)  

{ 

    int n1 = mid - left + 1; 

    int n2 = right - mid; 

    int i, j, k, L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 

        L[i] = arr[left + i]; 

    for (j = 0; j < n2; j++) 

        R[j] = arr[mid + 1 + j]; 

    i = 0, j = 0, k = left; 

    while (i < n1 && j < n2) { 

        if (L[i] <= R[j]) 

            arr[k++] = L[i++]; 

        else 

            arr[k++] = R[j++]; 

    } 

    while (i < n1) 

        arr[k++] = L[i++]; 

    while (j < n2) 

        arr[k++] = R[j++]; 

} 

void merge_sort(int arr[], int left, int right)  

{ 

    if (left < right) { 

        int mid = left + (right - left) / 2; 

        merge_sort(arr, left, mid); 

        merge_sort(arr, mid + 1, right); 

        merge(arr, left, mid, right); 

    } 

} 

void print_array(int arr[], int n)  

{ 

int i; 

    for (i = 0; i < n; i++) 

        printf("%d ", arr[i]); 

    printf("\n"); 

} 

int main() { 

    int arr[] = {4, 22, 13, 5, 54, 32, 60, 25}; 
    printf("\ Merge Sort \n");
    printf("given array : 4, 22, 13, 5, 54, 32, 60, 25\n");

    int n = sizeof(arr) / sizeof(arr[0]); 

    merge_sort(arr, 0, n - 1); 

    printf("Sorted array: "); 

    print_array(arr, n); 
    printf("\t Shrajesh Shrestha \n");

    return 0; 

} 
