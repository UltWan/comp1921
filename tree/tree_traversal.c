#include <stdio.h>
#include <stdlib.h>
#include "tree_structures.h"

/* -------------------------------------------
           POSTORDER TRAVERSAL
 ------------------------------------------- */

void postorder(Node *node)
{
  if( node != NULL )
  {
    postorder(node->left);
    postorder(node->right);
    printf(" %d\n",(node->data_pointer)->integer_data);
  }
}

/* -------------------------------------------
          PREORDER TRAVERSAL
 ------------------------------------------- */

void preorder(Node *node)
{
  if( node != NULL )
  {
    printf(" %d\n",(node->data_pointer)->integer_data);
    preorder(node->left);
    preorder(node->right);
  }
}

/* -------------------------------------------
          INORDER TRAVERAL
 ------------------------------------------- */

void inorder(Node *node)
{
  if( node != NULL )
  {
    inorder(node->left);
    printf(" %d\n",(node->data_pointer)->integer_data);
    inorder(node->right);
  }
}
