#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int top;
  int capacity;
  // POINTER DECLARATION: 'int *array' means 'array' stores the memory address of an integer
  // (the first element of the dynamically allocated array).
  int *array;
};

// POINTER RETURN TYPE: 'struct Stack*' means this function returns a pointer 
// (memory address) to a struct Stack allocated in heap memory.
struct Stack* createStack(int capacity) {

  // POINTER DECLARATION & CAST:
  // 'struct Stack* stack' declares a pointer variable to hold the address of the struct.
  // '(struct Stack*)' typecasts the generic void* returned by malloc to a struct Stack pointer.
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

  // '->' (ARROW OPERATOR): Dereferences the 'stack' pointer and accesses its members (equivalent to (*stack).capacity).
  stack -> capacity = capacity;
  stack -> top = -1;
  // POINTER CAST: '(int*)' typecasts the void* returned by malloc into an int pointer and assigns it to 'stack->array'.
  stack -> array = (int*)malloc(sizeof(int) * stack -> capacity);

  // Returns the memory address (pointer) of the allocated Stack.
  return stack;
}

// POINTER PARAMETER: 'struct Stack* stack' receives the memory address of the stack,
// allowing modifications made here to affect the original stack.
void push_back(struct Stack* stack, int elm){

  if (stack -> top == stack -> capacity - 1){
    printf("ERROR: Stack overflow\n");
    return;
  }
  
  stack -> top++;
  // 'stack->array[...]' accesses the memory offset from pointer 'array' (equivalent to *(stack->array + index)).
  stack -> array[stack -> top] = elm;
}

// POINTER PARAMETER: 'struct Stack* stack' takes the address of the stack to modify its 'top' index.
void pop_back(struct Stack* stack){

  if (stack -> top == -1){
    printf("ERROR: Stack underflow\n");
    return;
  }

  stack -> top--;
}

// POINTER PARAMETER: 'struct Stack* stack' takes the address of the stack to read its data without copying the struct.
void print_stack(struct Stack* stack){

  printf("Stack: ");
  for(int i = 0; i <= stack -> top; i++){
    // 'stack->array[i]' accesses the i-th element from the base pointer address.
    printf("%d ", stack -> array[i]);
  }
  printf("\n");
}

void main() {

  int capacity;
  printf("Enter the capacity of the Stack: ");
  scanf("%d", &capacity);

  // POINTER VARIABLE: 'struct Stack* stack' stores the memory address returned by createStack.
  struct Stack* stack = createStack(capacity);

  // Passing the pointer 'stack' (memory address) to functions.
  push_back(stack, 20);
  push_back(stack, 30);
  push_back(stack, 40);

  print_stack(stack);

  pop_back(stack);

  print_stack(stack);
  
}