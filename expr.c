//expression handling file
#include "defs.h"
#include "data.h"
#include "decl.h"

static struct ASTNode*  primary(void){
    struct ASTNode* node;
    switch(Token.token){
        case T_INTLIT:
            node=makeleaf(A_INTLIT,Token.intvalue);
            scan(&Token);
            return node;
        default:
        fprintf(stderr,"unknown token on line %d \n",Line);
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


