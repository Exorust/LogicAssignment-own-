#include "include/logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stack_initialize(stack **input, int size) {
  stack *tmp;
  tmp = (stack*)malloc(sizeof(stack));
  tmp->index=-1;
  tmp->max_capacity = size;
  tmp->arr = (char*)malloc(size*sizeof(char));
  *input = tmp;
}

int is_full(stack *stk) {
  if ( stk->index == stk->max_capacity-1 )
    return 1;
  else
    return 0;
}

int is_empty(stack *stk) {
  if ( stk->index == -1 )
    return 1;
  else
    return 0;
}

char view(stack *stk) {
  return (stk->arr)[stk->index];
}

char pop(stack *stk) {
  char c = (stk->arr)[stk->index];
  (stk->index)--;
  return c;
}

void push(stack *stk, char c) {
  if ( is_full(stk) )
        return;
  (stk->index)++;
  (stk->arr)[stk->index] = c;
}
