// data structure definition
struct qnode
    {
    // node data
    int level;
    double xy[2];
    struct qnode *child[4];
    struct node *nextLeaf;
    };

// data type definition
typedef struct qnode Node;

struct quadtreeGrid
    {
    Node *leafHead;
    Node *nextLeaf;
    int maxLevel;
    } Quadtree;
