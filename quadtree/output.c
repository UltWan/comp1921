#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structs.h"


void printOut( FILE *fp, Node *node )
{

    // node data
    double x = node->xy[0];
    double y = node->xy[1];
    int level = node->level;
    double h = pow(2.0,-level);

    // print out the corner points
    fprintf(fp, " %g %g\n",x,y);
    fprintf(fp, " %g %g\n",x+h,y);
    fprintf(fp, " %g %g\n",x+h,y+h);
    fprintf(fp, " %g %g\n",x,y+h);
    fprintf(fp, " %g %g\n\n",x,y);

    return;
}


// recursively search for leaf nodes
void writeNode ( FILE *fp, Node *node )
    {
    int i;
    if( node->child[0] == NULL )
        printOut( fp, node );
    else
        {
        for ( i=0; i<4; ++i )
            {
            writeNode( fp, node->child[i] );
            }
        }
    return;
    }


// open a file and prepare to write
void writeTree( Node *head )
    {
    FILE *fp = fopen("quad.out","w");
    writeNode(fp,head);
    fclose(fp);
    return;
    }

