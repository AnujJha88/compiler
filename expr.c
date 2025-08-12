//expression handling file
#include "defs.h"
#include "data.h"
#include "decl.h"
// what this does is it sees if the parsed thing is a primary expression
// and then we return a node representing that and so if we have an intlit
// thing we can in the next token and return the leaf with the int value and
// otherwise what we do is we throw a syntax error
static struct ASTNode*  primary(void){
    struct ASTNode* node;
    switch(Token.token){
        case T_INTLIT:
            node=makeleaf(A_INTLIT,Token.intvalue);
            scan(&Token);
            return node;
        default:
        fprintf(stderr,"syntax error on line: %d \n",Line);
        exit(1);
    }

}

int convert_token_to_AST_op(int token){
    switch(token){
        case T_PLUS:
            return A_ADD;
        case T_MINUS:
        return A_SUB;
        case T_MULTIPLY:
        return A_MUL;
        case T_DIVIDE:
        return A_DIV;

            default:
        fprintf(stderr,"unknown token on line %d \n",Line);
        exit(1);

    }
}

// now we make the function that creates the actual tree
//right now we have mo heirarchy between the operators
struct ASTNode* binary_exp(){
    struct ASTNode *left,*right,*node;
        int nodetype;

        left=primary();
        if(Token.token ==T_EOF)return left;
        nodetype=convert_token_to_AST_op(Token.token);// convert the token to an AST
        // Node and then make it like the root of this subtree and then attach to
        // the main root if any and yada yada
        scan(&Token);
        right=binary_exp();//so we leave the right node to be made
        //recursively and we make each left subtree from every node 1 deep only
        node=makeASTNode(nodetype,left,right,0);//this is not really having intvalues its having the operator so we do this
        return node;
}
