/**
 * Question 8: What is a dangling pointer? Give one situation in which a 
 * dangling pointer may occur.
 *
 * Answer:
 * What is a dangling pointer?
 * A dangling pointer is a pointer that points to a memory location that has already 
 * been freed or deallocated. Accessing or modifying the memory pointed to by a 
 * dangling pointer leads to undefined behavior (often a segmentation fault), as the 
 * memory might have been given back to the operating system or reused for another purpose.
 *
 * Situation where a dangling pointer may occur:
 * 1. Memory Deallocation (using free()):
 *    When a dynamically allocated memory block is freed, the pointer still holds the 
 *    memory address of the freed block unless it is explicitly set to NULL.
 *
 * 2. Function returning a local variable address:
 *    When a function returns the address of a local variable, the local variable goes 
 *    out of scope and is destroyed once the function completes. The returned pointer 
 *    in the caller function becomes a dangling pointer.
 *
 * How to avoid:
 * Always set the pointer to NULL immediately after freeing it (e.g., `ptr = NULL;`).
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Example of a dangling pointer via memory deallocation
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 100;
    
    printf("Value before free: %d\n", *ptr);
    
    // Deallocate the memory
    free(ptr);
    
    // Now 'ptr' is a dangling pointer.
    // Accessing *ptr here is undefined behavior and dangerous.
    // printf("Value after free: %d\n", *ptr); // Un-commenting this is unsafe
    
    // Best practice to avoid dangling pointer:
    ptr = NULL;
    
    if (ptr == NULL) {
        printf("Pointer safely set to NULL after freeing.\n");
    }

    return 0;
}
