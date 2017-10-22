#include <stdio.h>
#include "include/logic.h"

int main(int argc, char const *argv[]) {

  char x[100] = "p+q";
  infix_to_postfix(x);
  printf("%s\n", x );
  // node *tmp1;
  // tmp1 = postfix_to_tree("rpq+>",5);
  // printf("%c %c\n", tmp1->value,tmp1->left->value);
  //
  // char string[30];
  // int i;
  // for(i=0;i<30;i++){
  //   string[i]='\0';
  // }
  // int n = tree_to_infix(string,tmp1);
  // printf("%s\n",string );

  return 0;
}
