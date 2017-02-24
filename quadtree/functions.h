#include "structs.h"


Node *makeNode( double x, double y, int level );

void makeChildren( Node *parent );

void destroyNode( Node *node );

void growTree( Node *node );

void writeNode ( FILE *fp, Node *node );

void writeTree( Node *head );

void printOut( FILE *fp, Node *node );
