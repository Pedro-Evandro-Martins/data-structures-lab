#include "core/node.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Node *newNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    exit(1); // TODO - Adequate error handling
  }

  node->data = data;
  node->next = NULL;

  return node;
}
