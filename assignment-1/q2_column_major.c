/**
 * Question 2: Given an array arr[1.........10][1.........15] with a base value of 100 
 * and the size of each element is 1 Byte in memory find the address of arr[8][6] 
 * with the help of column-major order
 *
 * Answer:
 * Formula for Column-Major Order:
 * Address(A[i][j]) = Base_Address + W * [(j - Lc) * M + (i - Lr)]
 * 
 * Where:
 * Base_Address = 100
 * W (Word size) = 1 Byte
 * Lr (Lower bound of row) = 1
 * Lc (Lower bound of column) = 1
 * M (Total number of rows) = Upper_bound_row - Lower_bound_row + 1 = 10 - 1 + 1 = 10
 * i = 8
 * j = 6
 *
 * Calculation:
 * Address(A[8][6]) = 100 + 1 * [(6 - 1) * 10 + (8 - 1)]
 *                  = 100 + 1 * [5 * 10 + 7]
 *                  = 100 + 1 * [50 + 7]
 *                  = 100 + 57
 *                  = 157
 *
 * The address of arr[8][6] in column-major order is 157.
 */

#include <stdio.h>

int main() {
    // Verification program for the calculation
    int base_address = 100;
    int w = 1;
    int lr = 1;
    int lc = 1;
    int m = 10;
    int i = 8;
    int j = 6;
    
    int address = base_address + w * ((j - lc) * m + (i - lr));
    printf("The address of arr[8][6] using column-major order is: %d\n", address);
    
    return 0;
}
