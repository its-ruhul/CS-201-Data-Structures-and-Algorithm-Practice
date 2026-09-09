/**
 * Question 10: Define a linked list and their type.
 *
 * Answer:
 * Definition of Linked List:
 * A linked list is a linear data structure consisting of a sequence of elements 
 * called nodes. Unlike arrays, the elements of a linked list are not stored in 
 * contiguous memory locations. Instead, each node contains two parts:
 * 1. Data: The actual value being stored.
 * 2. Pointer/Reference (Next): A reference to the next node in the sequence.
 * 
 * The first node of the list is called the "Head". The last node usually points 
 * to NULL to indicate the end of the list. Linked lists are dynamic in size and 
 * allow for efficient insertion and deletion operations.
 *
 * Types of Linked List:
 * 1. Singly Linked List:
 *    - Each node contains data and a single pointer pointing to the next node.
 *    - Traversal is only possible in one direction (forward).
 *    - Example: [Data | Next] -> [Data | Next] -> NULL
 *
 * 2. Doubly Linked List:
 *    - Each node contains data and two pointers: one pointing to the previous node 
 *      and one pointing to the next node.
 *    - Traversal is possible in both directions (forward and backward).
 *    - Example: NULL <- [Prev | Data | Next] <-> [Prev | Data | Next] -> NULL
 *
 * 3. Circular Linked List:
 *    - Similar to a singly linked list, but the last node's next pointer points 
 *      back to the first node (head) instead of NULL, forming a circle.
 *    - Traversal can go on indefinitely.
 *    - Example: [Data | Next] -> [Data | Next] --(back to head)
 *
 * 4. Doubly Circular Linked List:
 *    - A combination of doubly and circular linked lists. The last node points to 
 *      the first node, and the first node's previous pointer points to the last node.
 */

#include <stdio.h>

int main() {
    printf("Linked Lists and Types Summary:\n");
    printf("1. Singly Linked List\n");
    printf("2. Doubly Linked List\n");
    printf("3. Circular Linked List\n");
    printf("4. Doubly Circular Linked List\n");
    return 0;
}
