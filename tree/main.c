#include <stdio.h>
#include <stdlib.h>
#include "tree_functions.h"

/* -------------------------------------------
              MAIN
 ------------------------------------------- */

void main(void)
{
  int size = 16;
  int tree_data[16] = {9,5,17,18,7,2,14,6,4,11,1,16,3,10,12,8};
  Node *root;
/*
  root = create_regular_tree(tree_data, 0, size);
*/
  root = create_data_tree(tree_data, size);

  printf(" Postorder traversal\n");
  postorder(root);

  printf(" Preorder traversal\n");
  preorder(root);

  printf(" Inorder traversal\n");
  inorder(root);

  free(root);
}
