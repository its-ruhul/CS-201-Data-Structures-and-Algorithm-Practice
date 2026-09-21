#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* createNode(int data){

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  if(newNode == NULL){
    printf("ERROR: Stack Overflow\n");
    exit(1);
  }

  newNode -> data = data;
  newNode -> next = NULL;

  printf("Added element: %d\n", data);

  return newNode;
}

void push(struct Node** head, int data){

  struct Node* newNode = createNode(data);

  if(*head == NULL){
    *head = newNode;
    return;
  }

  struct Node* temp = *head;

  while(temp -> next != NULL){
    temp = temp -> next;
  }

  temp -> next = newNode;

  return;
}

void pop(struct Node** head){

  if(*head == NULL){
    printf("ERROR: Stack underflow\n");
    return;
  }

  struct Node* temp = *head;

  if(temp -> next == NULL){
    printf("Popped: %d\n", temp -> data);
    free(temp);
    *head = NULL;
    return;
  }

  while(temp -> next -> next != NULL){
    temp = temp -> next;
  }

  printf("Popped: %d\n", temp -> next -> data);
  free(temp -> next);
  temp -> next = NULL;

  return;
}

void peek(struct Node** head){

  if(*head == NULL){
    printf("ERROR: Stack underflow\n");
    return;
  }

  struct Node* temp = *head;

  while(temp -> next != NULL){
    temp = temp -> next;
  }

  printf("Peek: %d\n", temp -> data);

  return;
}

void printStack(struct Node** head){

  if(*head == NULL){
    printf("ERROR: Stack underflow\n");
    return;
  }

  struct Node* temp = *head;

  printf("Stack: ");

  while(temp -> next != NULL){
    printf("%d ", temp -> data);
    temp = temp -> next;
  }

  printf("%d \n", temp -> data);

  return;
} 

int main() {

  struct Node* head = NULL;

  push(&head, 10);
  push(&head, 20);

  peek(&head);
  printStack(&head);

  pop(&head);
  printStack(&head);

  return 0;
}