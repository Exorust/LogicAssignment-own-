#include "include/logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_symbol(char input) {
  if (input == '~')
    return 1;
  else if(input == '+')
    return 1;
  else if(input == '*')
    return 1;
  else if(input == '>')
    return 1;
  else
    return 0;
}

void infix_to_postfix(char *input_string) {
  stack *stk;
  int size = 100,i;
  char* output_string = (char*)malloc(size*(sizeof(char)));
  for(i=0;i<size;i++){
    output_string[i]="\0";
  }
  int final_index = -1, init_index = 0;
  int str_length = strlen(input_string);

  stack_initialize(&stk,size);

  for (init_index = 0; init_index < str_length ;init_index++ ) {
    char element = input_string[init_index];

    if (!is_symbol(element)) {
      final_index++;
      output_string[final_index] = element;
      printf("***%c\n", element );
      fflush(stdout);
    }

    else if (element == '(') {
      char ch = '(';
      push(stk,ch);
    }

    else if (element == ')') {
      while(view(stk) != '(') {
        output_string[final_index] = pop(stk);
        final_index++;
      }
      pop(stk);
    }

    else if( is_symbol(element) ) {
      push(stk,element);
      printf("%c\n", view(stk));
    }
  }

  while(!is_empty(stk)) {
    char element = view(stk);
    if ( (element != '(') && (element != ')') ) {
      final_index++;
      output_string[final_index] = element;
    }
    pop(stk);
  }

  strcpy(input_string,output_string);
  printf("%s\n", output_string);
}

// node* node_constructor() {
//   node *tmp = (node*)malloc(3*sizeof(node));
//   tmp->left = NULL;
//   tmp->right = NULL;
//   return tmp;
// }



void add2tree(char *string, node *tree_node, int *count) {
  char element = string[*count];

  if ( is_symbol(element) ) {
    tree_node->value = element;
    tree_node->right = node_constructor();
    tree_node->left  = node_constructor();

    (*count)--;

    add2tree(string, tree_node->right, count);
    add2tree(string, tree_node->left,  count);
  }
  else {
    tree_node->value = element;
    (*count)--;
    return;
  }

}



node* postfix_to_tree(char *string, int string_len) {
  node *start = node_constructor();
  int *count = (int*)malloc(sizeof(int));
  *count = string_len - 1;
  add2tree(string,start,count);
  return start;
}

void tree2string(char *string, node *tree_node, int *count) {
  char element = tree_node->value;
  if( is_symbol(element) ) {

    string[*count]='(';
    (*count)++;

    tree2string(string,tree_node->left,count);

    string[*count]=tree_node->value;
    (*count)++;

    tree2string(string,tree_node->right,count);

    string[*count]=')';
    (*count)++;
    return;
  }
  else {

    string[*count]=tree_node->value;
    (*count)++;
    return;
  }
}

int tree_to_infix(char* string, node *start) {
  int *count = (int*)malloc(sizeof(int));
  *count = 0;
  tree2string(string,start,count);
  return *count;
}
