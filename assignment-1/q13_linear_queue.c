/**
 * Question 13: Write a C program to implement a linear queue using an array 
 * and perform the following operations: Enqueue, Dequeue, Peek/Front, and Display.
 */

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Insert element at the rear
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is Full! Overflow condition.\n");
    } else {
        if (front == -1) {
            front = 0; // Initialize front if inserting the first element
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

// Remove element from the front
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty! Underflow condition.\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
        // Optional: Reset queue when empty to reuse space
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// Peek/Front: View the front element
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front Element is: %d\n", queue[front]);
    }
}

// Display the queue elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    peek();
    
    dequeue();
    display();
    
    return 0;
}
