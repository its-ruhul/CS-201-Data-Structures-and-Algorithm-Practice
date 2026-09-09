/**
 * Question 14: Write a C program to implement a stack using an array 
 * and perform the following operations: Push, Pop, Peek, and Display.
 */

#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push operation to insert element
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d onto stack.\n", value);
    }
}

// Pop operation to remove element
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("Popped %d from stack.\n", stack[top]);
        top--;
    }
}

// Peek operation to see the top element
void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Display operation to print stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    
    display();
    
    peek();
    
    pop();
    display();
    
    return 0;
}
