// COMP 1921 Code Review
// Ryan Wan, Monday 27th February 2017

#include "stdbool.h"
#include "structs.h"


//functions to call on in other c files
Node *makeNode( double x, double y, int level );

void makeChildren( Node *parent );

void destroyNode( Node *node );

void growTree( Node *node );

void writeNode ( FILE *fp, Node *node );

void writeTree( Node *head );

void printOut( FILE *fp, Node *node );

double dataFunction( double x, double y, int choice );

bool indicator( Node *node, double tolerance, int choice );

void searchTree( Node *node );
