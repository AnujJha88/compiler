#include "defs.h"
#include "data.h"
#include "decl.h"

static char *ASTop[]={"+","-","*","/"};


int interpretAST(struct ASTNode* root){
    int leftval,rightval;

    if(root->left) leftval=interpretAST(root->left);
    if(root->right) rightval=interpretAST(root->right);
    if(root->op ==A_INTLIT) printf("int %d \n",root->intvalue);
    else printf("%d %s %d \n",leftval,ASTop[root->op],rightval);
    //now for base case
    switch(root->op){
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
         fprintf(stderr,"Invalid operator %d \n",root->op);
         exit(1);
    }
}
