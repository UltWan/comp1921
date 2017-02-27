// COMP 1921 Code Review
// Ryan Wan, Monday 27th February 2017

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structs.h"


Node *makeNode( double x, double y, int level )
    {
    int i;

    // allocate the data structure
    Node *node = (Node *)malloc(sizeof(Node));

    // set the node data
    node->level = level;
    node->xy[0] = x;
    node->xy[1] = y;

    // set children to NULL
    for( i=0; i<4; ++i )
    node->child[i] = NULL;
    return node;
    }

void makeChildren( Node *parent )
    {
    // parent data
    double x = parent->xy[0];
    double y = parent->xy[1];
    int level = parent->level;

    // child edge length
    double hChild = pow(2.0,-(level+1));

    if (level == 10)
        {
        printf("Error: Program terminated because maximum level of tree exceeded\n");
        exit (0);
        }

    else
        {
        parent->child[0] = makeNode( x,y, level+1 );
        parent->child[1] = makeNode( x+hChild,y, level+1 );
        parent->child[2] = makeNode( x+hChild,y+hChild, level+1);
        parent->child[3] = makeNode( x,y+hChild, level+1 );
        }
        
    return;
    }

// destroys tree
void destroyNode( Node *node )
    {
    int i;
    if( node->child[0] == NULL )
        free( node );
    else
        {
        for ( i=0; i<4; ++i )
            {
            destroyNode(  node->child[i] );
            }
        }
    return;
    }

// grow every leaf node by one level
void growTree( Node *node )
    {
    int i;
    if( node->child[0] == NULL )
        makeChildren( node );
    else
        {
        for ( i=0; i<4; ++i )
            {
            growTree(  node->child[i] );
            }
        }
    return;
    }
