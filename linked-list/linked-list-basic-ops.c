#include <stdio.h>   // For standard I/O functions like printf()
#include <stdlib.h>  // For dynamic memory allocation functions (malloc, free) and exit()

/*
 * ==========================================
 *  STRUCT NODE DEFINITION (Self-Referential)
 * ==========================================
 * A linked list node consists of two parts:
 * 1. Data: The actual value stored in the node (here, an integer).
 * 2. Next Pointer: A pointer storing the memory address of the next 'struct Node' in the list.
 *
 * POINTER CONCEPT:
 * 'struct Node* next' is a pointer variable. It does NOT contain node data itself;
 * it only holds the memory address (a reference) pointing to where the next Node lives in RAM.
 * For the last node in the chain, this pointer points to NULL (meaning "nothing comes next").
 */
struct Node {
  int data;           // Holds the integer payload/value
  struct Node* next;  // Pointer to the next Node (holds memory address of another struct Node)
};

/*
 * ==========================================
 *  FUNCTION: createNode
 * ==========================================
 * Creates a new node dynamically on the Heap memory.
 *
 * POINTER CONCEPTS:
 * 1. Return type 'struct Node*':
 *    The function returns the memory address (pointer) of the newly allocated node.
 * 2. malloc(sizeof(struct Node)):
 *    Requests bytes from the OS Heap equal to the size of struct Node.
 *    malloc() returns a generic pointer (void*), which is explicitly typecast to (struct Node*).
 * 3. 'newNode' is a local pointer variable on the Stack that holds the Heap address returned by malloc.
 * 4. Arrow Operator '->':
 *    'newNode->data' is syntactic sugar for '(*newNode).data'.
 *    It first dereferences the pointer (*newNode) to access the actual struct in memory,
 *    and then accesses its 'data' field.
 */
struct Node* createNode(int data) {

  // Dynamically allocate memory on the heap for a single struct Node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // Check if heap memory allocation was successful (malloc returns NULL on failure)
  if (newNode == NULL) {
    printf("ERROR: Memory allocation of New Node Failed.\n");
    exit(1); // Terminate program with error code 1
  }

  // Initialize the node's fields:
  newNode->data = data;  // Assign the passed data value to the node
  newNode->next = NULL;  // Initialize next pointer to NULL because it does not point to any node yet

  // Return the memory address of this new node to the caller
  return newNode;
}

/*
 * ==========================================
 *  FUNCTION: insertAtEnd
 * ==========================================
 * Inserts a new node at the tail (end) of the linked list.
 *
 * POINTER CONCEPTS - WHY DOUBLE POINTER (struct Node** head_ref)?
 * 1. In C, all function arguments are passed BY VALUE (a copy is passed).
 * 2. If we passed 'struct Node* head' (single pointer) and modified 'head' inside the function
 *    when the list is empty (head = newNode), only the local copy inside insertAtEnd would change!
 *    The original 'head' pointer in main() would remain unchanged (NULL).
 * 3. To modify the actual 'head' pointer in main(), we must pass its memory address (&head).
 *    A pointer to a pointer is represented with two asterisks: 'struct Node**'.
 *
 * DEREFERENCING '*head_ref':
 * - 'head_ref' holds the address of the head pointer (&head in main).
 * - '*head_ref' accesses the value stored at that address, which is the actual pointer to the first node.
 */
void insertAtEnd(struct Node** head_ref, int new_data) {

  // Step 1: Create the new node in heap memory
  struct Node* newNode = createNode(new_data);

  // Step 2: Check if the linked list is currently empty.
  // '*head_ref' gives the actual value of 'head' from main().
  if (*head_ref == NULL) {
    // If the list is empty, make the new node the first (head) node.
    // This directly updates 'head' in main()!
    *head_ref = newNode;
    return;
  }

  // Step 3: If list is not empty, traverse to the last node.
  // We use a temporary pointer 'temp' so we don't alter '*head_ref' (the head of the list).
  // 'temp' starts at the first node (*head_ref).
  struct Node* temp = *head_ref;

  // Keep advancing 'temp' until 'temp->next' is NULL (which indicates the last node)
  while (temp->next != NULL) {
    temp = temp->next; // Move 'temp' pointer to point to the next node in the list
  }

  // Step 4: Link the last node to the new node.
  // Update the 'next' pointer of the current last node from NULL to the address of 'newNode'.
  temp->next = newNode;
  return;
}

/*
 * ==========================================
 *  FUNCTION: printList
 * ==========================================
 * Traverses and prints each element of the linked list.
 *
 * POINTER CONCEPTS:
 * 1. We only need a single pointer 'struct Node* node' because we are only reading the list,
 *    not modifying the caller's 'head' pointer.
 * 2. 'node' is a local copy of the pointer passed from caller. Changing 'node = node->next'
 *    here only moves our local pointer variable and does NOT affect 'head' in main().
 */
void printList(struct Node* node) {

  // Traverse through each node until we hit the end of the list (NULL)
  while (node != NULL) {
    printf("%d -> ", node->data); // Access and print current node's data
    node = node->next;             // Advance pointer to the next node's memory address
  }
  printf("NULL\n"); // Print NULL to represent the end of the chain

  return;
}

/*
 * ==========================================
 *  FUNCTION: freeList
 * ==========================================
 * Deallocates all dynamically allocated heap memory occupied by the nodes.
 *
 * POINTER CONCEPTS & MEMORY MANAGEMENT:
 * 1. Why do we need 'temp'?
 *    If we do 'free(head); head = head->next;', we would be reading memory (head->next)
 *    AFTER it has been freed! This is a "Use-After-Free" bug and causes undefined behavior.
 * 2. Correct order:
 *    - Save current node's address in 'temp'.
 *    - Advance 'head' to the next node ('head = head->next').
 *    - Safely free the memory of the previous node ('free(temp)').
 */
void freeList(struct Node* head) {
  
  struct Node* temp; // Temporary pointer to hold reference to the node being freed

  while (head != NULL) {
    temp = head;        // Store current node's address in temp
    head = head->next;  // Advance head pointer to the next node before freeing current one
    free(temp);         // Deallocate heap memory of the node stored in temp
  }
}

/*
 * ==========================================
 *  FUNCTION: main
 * ==========================================
 * Entry point of the program.
 *
 * POINTER CONCEPTS:
 * 1. 'struct Node* head = NULL;'
 *    Declares a pointer variable named 'head' on the Stack. It initially points to NULL,
 *    representing an empty linked list.
 * 2. '&head' (Address-of operator):
 *    Passes the memory address of the 'head' pointer itself to 'insertAtEnd'.
 *    Type of '&head' is 'struct Node**' (pointer to pointer).
 * 3. 'printList(head)':
 *    Passes the value of 'head' (the address of the first node) by value.
 * 4. 'freeList(head)':
 *    Passes 'head' so the function can traverse and free all allocated heap memory,
 *    preventing memory leaks.
 */
int main() {

  // Initialize the head pointer to NULL (list is initially empty)
  struct Node* head = NULL;

  // Insert elements at the end of the list:
  // We pass '&head' (address of head) so insertAtEnd can modify 'head' when necessary.
  insertAtEnd(&head, 10); // List: 10 -> NULL
  insertAtEnd(&head, 20); // List: 10 -> 20 -> NULL
  insertAtEnd(&head, 30); // List: 10 -> 20 -> 30 -> NULL

  // Print the linked list
  printf("The linked list: ");
  printList(head);

  // Free all allocated memory on the heap to prevent memory leaks
  freeList(head);

  return 0;
}