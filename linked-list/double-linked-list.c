#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* createNode(int data) {

  struct Node* node = (struct Node*)malloc(sizeof(struct Node));

  if (node == NULL){
    printf("ERROR: Memory allocation for new node failed!");
    exit(1);
  }

  node -> data = data;
  node -> prev = NULL;
  node -> next = NULL;

  return node;
}

void insertAtEnd(struct Node** head, int data){
  
  //STEP 1: Creats Node
  struct Node* node = createNode(data);

  //STEP 2: Makes head point to node if head doesn't point to any list
  if (*head == NULL){
    *head = node;
    return;
  }

  //STEP 3: Iterates through the loop to reach the last  node.
  struct Node* temp = *head;
  while(temp -> next != NULL){
    temp = temp -> next;
  }

  //STEP 4: Make last node point to new node and new node point to last node
  node -> prev = temp;
  temp -> next = node;

  return;
}

// void insertAtStart(struct Node** head, int data){
  
//   return;
// }

void printfromStart(struct Node** head){

  struct Node* temp = *head;

  printf("Doubled Linked List: ");

  while(temp != NULL){
    printf("%d -> ", temp -> data);
    temp = temp -> next;
  }
  printf("NULL\n");

  return;
}

// void freeNode(struct Node** head){

//   return;
// }

int main() {

  struct Node* head = NULL;
  int data;

  printf("Enter element: ");
  scanf("%d", &data);

  insertAtEnd(&head, data);
  insertAtEnd(&head, data);
  insertAtEnd(&head, data);

  printfromStart(&head);

  return 0;
}