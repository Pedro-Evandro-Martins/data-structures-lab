#include "core/node.h"
#include "core/errors.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Node *newNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    handleError(ERR_MEMORY_ALLOCATION, "newNode");
    return NULL;
  }

  node->data = data;
  node->next = NULL;

  return node;
}
