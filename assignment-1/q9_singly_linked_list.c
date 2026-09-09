/**
 * Question 9: Write a C program to perform the following operations on a singly linked list: 
 * - Insertion at beginning 
 * - Insertion at end 
 * - Deletion from beginning 
 * - Deletion from end 
 * - Display of the list
 */

#include <stdio.h>
#include <stdlib.h>

// Definition of a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insertion at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    newNode->next = *head_ref;
    *head_ref = newNode;
    printf("Inserted %d at beginning.\n", new_data);
}

// Insertion at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        printf("Inserted %d at end.\n", new_data);
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    printf("Inserted %d at end.\n", new_data);
}

// Deletion from the beginning
void deleteFromBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// Deletion from the end
void deleteFromEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    // If there is only one node
    if ((*head_ref)->next == NULL) {
        printf("Deleted %d from end.\n", (*head_ref)->data);
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    struct Node* second_last = *head_ref;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    printf("Deleted %d from end.\n", second_last->next->data);
    free(second_last->next);
    second_last->next = NULL;
}

// Display the list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("List elements: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    displayList(head);

    deleteFromBeginning(&head);
    displayList(head);

    deleteFromEnd(&head);
    displayList(head);

    return 0;
}
