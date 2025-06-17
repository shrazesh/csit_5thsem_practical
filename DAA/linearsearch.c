#include <stdio.h> 

 

int main() { 
printf("\t Linear Search \n");
printf("Given array is : {10, 25, 45, 67, 89, 12, 34} \n");

    int arr[] = {10, 25, 45, 67, 89, 12, 34}; 

    int n = sizeof(arr) / sizeof(arr[0]); 

    int target, i, found = 0; 

 

    printf("Enter the number to search: "); 

    scanf("%d", &target); 

 

     

    for (i = 0; i < n; i++) { 

        if (arr[i] == target) { 

            printf("Element found at index %d\n", i); 

            found = 1; 

            break; 

        } 

    } 

 

    if (!found) { 

        printf("Element not found in the array.\n"); 

    } 

 printf("\t Shrajesh Shrestha \n");

    return 0; 

} 
