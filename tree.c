#include<stdio.h>
#include <stdlib.h>
#include "include/logic.h"

node* node_constructor() {
  node *tmp = (node*)malloc(3*sizeof(node));
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
