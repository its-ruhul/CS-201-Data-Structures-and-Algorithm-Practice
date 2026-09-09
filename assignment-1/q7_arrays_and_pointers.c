/**
 * Question 7: Explain the relationship between arrays and pointers. 
 * How can array elements be accessed using pointer arithmetic?
 *
 * Answer:
 * Relationship between arrays and pointers:
 * In C, arrays and pointers are closely related. The name of an array acts as a 
 * constant pointer to the first element of the array. That means if you have an 
 * array `int arr[5];`, the name `arr` represents the memory address `&arr[0]`.
 * However, unlike a regular pointer, you cannot reassign an array name to point 
 * to another memory location (i.e., `arr = another_ptr` is invalid).
 *
 * Accessing array elements using pointer arithmetic:
 * Since an array's elements are stored in contiguous memory locations, we can use 
 * pointer arithmetic to navigate through the array. 
 * 
 * If `ptr` points to the first element of an array of type `T`, then `ptr + i` 
 * points to the i-th element of that array. The compiler automatically scales 
 * the addition by `sizeof(T)`.
 *
 * Examples:
 * - `arr[i]` is exactly equivalent to `*(arr + i)`.
 * - `&arr[i]` is exactly equivalent to `(arr + i)`.
 */

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ptr points to the first element of arr

    printf("Accessing array elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        // Accessing value using *(ptr + i)
        // Accessing address using (ptr + i)
        printf("Element %d: Value = %d, Address = %p\n", i, *(ptr + i), (void*)(ptr + i));
    }

    return 0;
}
