#ifndef LOGIC
#define LOGIC

typedef struct node_t{
  char value;
  struct node_t *left;
  struct node_t *right;
} node;

node* postfix_to_tree(char* ,int);
node* node_constructor();

typedef struct stack_t{
  int index;
  int max_capacity;
  char *arr;
} stack;

#endif
