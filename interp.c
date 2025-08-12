#include "defs.h"
#include "data.h"
#include "decl.h"

int interpretAST(struct ASTNode* root){
    int leftval,rightval;

    if(root->left) leftval=interpretAST(root->left);
    if(root->right) rightval=interpretAST(root->right);

    //now for base case
    switch(n->op){
        case A_ADD:
        return leftval+rightval;
        case A_SUB:
        return leftval-rightval;
        case A_MUL:
        return leftval*rightval;
        case A_DIV:
        return leftval/rightval;
        case A_INTLIT:
        return root->intvalue;
        default:
         fprintf(stderr,"Invalid operator %d \n",n->op);
         exit(1);
    }
}
