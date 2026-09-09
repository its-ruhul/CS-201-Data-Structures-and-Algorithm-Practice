/**
 * Question 11: What is a circular queue? Explain how it overcomes the limitations 
 * of a linear queue. Write a C program to perform insertion and deletion operations 
 * on a circular queue.
 *
 * Answer:
 * What is a circular queue?
 * A circular queue is an extended version of a linear queue in which the last element 
 * is connected back to the first element to form a circle. It follows the FIFO 
 * (First In First Out) principle. It is also known as a "Ring Buffer".
 *
 * How it overcomes the limitations of a linear queue:
 * In a standard linear queue implemented using an array, once the queue becomes full 
 * (rear reaches the maximum size), we cannot insert new elements even if there is 
 * empty space at the front (due to previous dequeue operations). This leads to 
 * memory wastage. A circular queue solves this by connecting the rear back to the 
 * front. If the rear reaches the end of the array, it wraps around to the beginning 
 * (index 0) provided there is space, thus utilizing the unused spaces efficiently.
 */

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Function to insert an element
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot insert %d\n", element);
        return;
    }
    if (front == -1) { // First element insertion
        front = 0;
        rear = 0;
    } else if (rear == SIZE - 1 && front != 0) { // Wrap around
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = element;
    printf("Inserted %d\n", element);
}

// Function to delete an element
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    int data = queue[front];
    printf("Deleted %d\n", data);
    
    if (front == rear) { // Queue has only one element
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) { // Wrap around
        front = 0;
    } else {
        front++;
    }
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60); // Wraps around
    display();
    enqueue(70); // Full
    return 0;
}
