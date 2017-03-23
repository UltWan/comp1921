#include <stdio.h>
#include <stdlib.h>
#include "tree_structures.h"

/* -------------------------------------------
          FUNCTION PROTOTYPES
 ------------------------------------------- */

Node *new_node(void);
Node *init_node(int, Node *, Node *);
Node *create_regular_tree(int *, int, int);
Node *create_data_tree(int *, int);
void postorder(Node *);
void preorder(Node *);
void inorder(Node *);
