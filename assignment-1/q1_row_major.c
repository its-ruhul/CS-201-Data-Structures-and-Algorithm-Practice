/**
 * Question 1: Given an 2d array, arr[1.........10][1.........15] with base value 100 
 * and the size of each element is 1 Byte in memory. 
 * Find the address of arr[8][6] with the help of row-major order.
 *
 * Answer:
 * Formula for Row-Major Order:
 * Address(A[i][j]) = Base_Address + W * [(i - Lr) * N + (j - Lc)]
 * 
 * Where:
 * Base_Address = 100
 * W (Word size) = 1 Byte
 * Lr (Lower bound of row) = 1
 * Lc (Lower bound of column) = 1
 * N (Total number of columns) = Upper_bound_column - Lower_bound_column + 1 = 15 - 1 + 1 = 15
 * i = 8
 * j = 6
 *
 * Calculation:
 * Address(A[8][6]) = 100 + 1 * [(8 - 1) * 15 + (6 - 1)]
 *                  = 100 + 1 * [7 * 15 + 5]
 *                  = 100 + 1 * [105 + 5]
 *                  = 100 + 110
 *                  = 210
 *
 * The address of arr[8][6] in row-major order is 210.
 */

#include <stdio.h>

int main() {
    // This is a theoretical question, but we can verify the calculation with a simple print statement.
    int base_address = 100;
    int w = 1;
    int lr = 1;
    int lc = 1;
    int n = 15;
    int i = 8;
    int j = 6;
    
    int address = base_address + w * ((i - lr) * n + (j - lc));
    printf("The address of arr[8][6] using row-major order is: %d\n", address);
    
    return 0;
}
