/**
 * Question 4: What is a sparse matrix? Why is storing a sparse matrix using a normal 
 * two-dimensional array inefficient? Explain the 3-tuple representation of a sparse matrix.
 *
 * Answer:
 * 1. What is a sparse matrix?
 *    A sparse matrix is a matrix in which the majority of its elements are zero. 
 *    For example, a 100x100 matrix with only 50 non-zero elements is a sparse matrix.
 *
 * 2. Why is normal 2D array representation inefficient?
 *    - Space Wastage: A normal 2D array allocates memory for all elements, including 
 *      the zeros. If 90% of the matrix is zeros, we are wasting 90% of our memory.
 *    - Time Complexity: Traversing the matrix to perform operations (like addition 
 *      or multiplication) will require checking all elements (even the zero ones), 
 *      leading to unnecessary computations.
 *
 * 3. 3-Tuple Representation:
 *    To overcome the inefficiencies, sparse matrices are stored using a 3-tuple 
 *    (or triplet) representation. Instead of storing the zeros, we only store the 
 *    non-zero elements along with their row and column indices.
 *
 *    The 3-tuple format consists of three columns:
 *    - Row: The row index of the non-zero element.
 *    - Column: The column index of the non-zero element.
 *    - Value: The actual non-zero value.
 *
 *    Typically, the first row of this representation stores:
 *    [Total Rows of Original Matrix, Total Columns of Original Matrix, Total Non-Zero Values]
 *
 *    Example:
 *    Original Matrix:
 *    0 0 3
 *    0 4 0
 *    5 0 0
 *
 *    3-Tuple Representation:
 *    Row | Col | Value
 *    -----------------
 *     3  |  3  |   3   <- Meta data (3 rows, 3 cols, 3 non-zero elements)
 *     0  |  2  |   3   <- Element at (0,2) is 3
 *     1  |  1  |   4   <- Element at (1,1) is 4
 *     2  |  0  |   5   <- Element at (2,0) is 5
 */

#include <stdio.h>

int main() {
    printf("A sparse matrix is efficiently stored using a 3-tuple (Row, Column, Value) representation.\n");
    return 0;
}
