/**
 * Question 5: Write a C program to dynamically allocate memory for n integers 
 * using malloc(). Accept the elements from the user and find their sum and average.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *arr;
    int sum = 0;
    float average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory using malloc
    arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; // Calculate sum
    }

    // Calculate average
    average = (float)sum / n;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
