// COMP 1921 Code Review
// Ryan Wan, Monday 27th February 2017


// data structure definition
struct qnode
    {
    // node data
    int level;
    double xy[2];
    struct qnode *child[4];
    };

// data type definition
typedef struct qnode Node;
