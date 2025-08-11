//expression handling file
#include "defs.h"
#include "data.h"
#include "decl.h"

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
