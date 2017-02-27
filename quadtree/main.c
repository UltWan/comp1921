// COMP 1921 Code Review
// Ryan Wan, Monday 27th February 2017

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main( int argc, char **argv )
    {

    // create the head node:  level 0
    Node *head = makeNode( 0.0,0.0,0 );

    // split to level 1
    makeChildren( head );

    // split one node to level 2
    makeChildren( head->child[2] );

    // write entire tree to quad.out
    writeTree( head );

    // delete entire tree
    destroyNode( head );

    return 0;
    }
