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
