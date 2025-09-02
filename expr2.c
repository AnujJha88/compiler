// PRATT PARSING 

#include "defs.h"
#include "data.h"
#include "decl.h"
// standard headers


static struct ASTNode* primary(){
    struct ASTNode* node;
switch(Token.token){
    case T_INTLIT:
    // this case would need us to make a leaf as the token is an integer and so it should not have any other associations
    node=makeleaf(A_INTLIT,Token.intvalue);
    scan(&Token);
    //neext token?
    return node;

    default:
    fprintf(stderr,"syntax error on line: %d, token %d \n",Line, Token.token);
    exit(1);
}

    return node;

}