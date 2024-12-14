#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct node Node;
Node *newNode(int data);

typedef struct stack Stack;
Stack *stack_create(void);

bool stack_isEmpty(Stack *stack);
int stack_getSize(Stack *stack);
void stack_push(Stack *stack, int data);
int stack_pop(Stack *stack);

void stack_destroy(Stack *stack);

void stack_print(Stack *stack);

#endif
