#include <stdio.h>
#include <stdlib.h>

/* -------------------------------------------
        NODAL DATA STRUCTURE
 ------------------------------------------- */

typedef struct tree_data
{
  int integer_data;
  double real_data; 
} Data;

/* -------------------------------------------
        TREE NODE STRUCTURE
 ------------------------------------------- */

typedef struct tree_node
{
  struct tree_data *data_pointer;
  struct tree_node *left;
  struct tree_node *right;
} Node;

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
