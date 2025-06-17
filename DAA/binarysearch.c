#include <stdio.h> 

int binary_search(int arr[], int n, int target) { 

    int left = 0, right = n - 1; 

    while (left <= right) { 

        int mid = left + (right - left) / 2; 

        if (arr[mid] == target) 

            return mid;  

        else if (arr[mid] < target) 

            left = mid + 1; 

        else 

            right = mid - 1; 

    } 

    return -1;  

} 

int main() { 

    int arr[] = {1, 5, 9, 20, 29, 38, 47, 55, 67}; 
    printf("\ Binary Search \n");
    printf("given array : 1, 5, 9, 20, 29, 38, 47, 55, 67 \n");

    int n = sizeof(arr) / sizeof(arr[0]); 

    int target,i; 

    printf("Enter the number to be searched: "); 

scanf("%d",&target); 

    int result = binary_search(arr, n, target); 

    if (result != -1) 

        printf("Element found at index %d\n", result); 

    else 

        printf("Element not found\n"); 
        printf("\t Shrajesh Shrestha \n");

    return 0;
}
