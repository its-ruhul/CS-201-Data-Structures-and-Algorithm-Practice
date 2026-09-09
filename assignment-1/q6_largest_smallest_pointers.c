/**
 * Question 6: Write a C program using pointers to find the largest and smallest 
 * elements in an array.
 */

#include <stdio.h>

// Function to find the largest and smallest elements using pointers
void findLargestSmallest(int *arr, int size, int *largest, int *smallest) {
    *largest = *arr;      // Initialize largest with the first element
    *smallest = *arr;     // Initialize smallest with the first element

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > *largest) {
            *largest = *(arr + i);
        }
        if (*(arr + i) < *smallest) {
            *smallest = *(arr + i);
        }
    }
}

int main() {
    int n;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int largest, smallest;
    
    // Pass the addresses of largest and smallest to the function
    findLargestSmallest(arr, n, &largest, &smallest);
    
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
    
    return 0;
}
