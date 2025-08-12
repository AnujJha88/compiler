#include "defs.h"
#include "data.h"

struct ASTNode* makeASTNode(int op, struct ASTNode* left, struct ASTNode*  right, int intvalue){
    struct ASTNode *node=(struct ASTNode*)malloc(sizeof(struct ASTNode)); // making new node in heap
        if(!node){
        fprintf(stderr,"Unable to make node \n");
            exit(1);
        }

        node->op=op;
        node->left=left;
        node->right=right;
        node->intvalue=intvalue;
        return node;

}

// now we can use it to make our life easier by making some helper functions

struct ASTNode *makeleaf(int op, int intvalue){
    return makeASTNode(op,NULL,NULL,intvalue);
}

struct ASTNode *makeunary(int op, struct ASTNode* child,int intvalue){
    return makeASTNode(op,child,NULL,intvalue);
}
