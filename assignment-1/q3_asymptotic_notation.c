/**
 * Question 3: Discuss the asymptotic notation with example.
 *
 * Answer:
 * Asymptotic notations are mathematical tools used to describe the running time or 
 * space complexity of an algorithm in terms of the input size (n). They help in 
 * analyzing the efficiency of algorithms by focusing on the highest order term and 
 * ignoring constants and lower-order terms.
 *
 * The three main types of asymptotic notations are:
 *
 * 1. Big-O Notation (O):
 *    - Describes the upper bound or worst-case scenario of an algorithm.
 *    - It guarantees that the function will not grow faster than the specified rate.
 *    - Example: If f(n) = 3n^2 + 5n + 2, then f(n) is O(n^2).
 *      A simple loop running 'n' times has a time complexity of O(n).
 *
 * 2. Omega Notation (Ω):
 *    - Describes the lower bound or best-case scenario of an algorithm.
 *    - It guarantees that the function will grow at least as fast as the specified rate.
 *    - Example: If f(n) = 3n^2 + 5n + 2, then f(n) is Ω(n^2) or even Ω(n).
 *      Finding an element in an array where the element is at the first index 
 *      takes Ω(1) time.
 *
 * 3. Theta Notation (Θ):
 *    - Describes the tight bound or average-case scenario.
 *    - It bounds the function from both above and below.
 *    - Example: If f(n) = 3n^2 + 5n + 2, then f(n) is Θ(n^2) because the growth 
 *      rate is exactly quadratic.
 */

#include <stdio.h>

int main() {
    printf("Asymptotic Notations:\n");
    printf("1. Big-O (O) - Upper Bound (Worst Case)\n");
    printf("2. Omega (Ω) - Lower Bound (Best Case)\n");
    printf("3. Theta (Θ) - Tight Bound (Average/Exact Case)\n");
    
    return 0;
}
