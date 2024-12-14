#include "data_structures/stack.h"
#include "core/errors.h"

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  Node *next;
};
Node *newNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    handleError(ERR_MEMORY_ALLOCATION, "stack_newNode");
    return NULL;
  }

  node->data = data;
  node->next = NULL;

  return node;
}

struct stack {
  Node *top;
  int size;
};
Stack *stack_create(void) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (stack == NULL) {
    handleError(ERR_MEMORY_ALLOCATION, "stack_crete");
    return NULL;
  }

  stack->top = NULL;
  stack->size = 0;

  return stack;
}

bool stack_isEmpty(Stack *stack) { return (stack->size == 0); }

int stack_getSize(Stack *stack) { return stack->size; }

void stack_push(Stack *stack, int data) {
  Node *node = newNode(data);
  if (node == NULL) {
    handleError(ERR_STACK_PUSH_FAILED, "stack_push");
    return;
  }

  node->next = stack->top;
  stack->top = node;
  stack->size++;
}

int stack_pop(Stack *stack) {
  if (stack_isEmpty(stack)) {
    handleError(ERR_STACK_POP_FAILED, "stack_pop");
    return -1;
  }

  Node *aux = stack->top;
  stack->top = aux->next;
  stack->size--;

  int data = aux->data;

  free(aux);

  return data;
}

void stack_destroy(Stack *stack) {
  while (!stack_isEmpty(stack)) {
    stack_pop(stack);
  }

  free(stack);
}

void stack_print(Stack *stack) {
  fprintf(stdout, "top -> [");

  Node *aux = stack->top;
  while (aux != NULL) {
    fprintf(stdout, "%d", aux->data);
    if (aux->next != NULL) {
      fprintf(stdout, ", ");
    }
    aux = aux->next;
  }

  fprintf(stdout, "]\n");
}
