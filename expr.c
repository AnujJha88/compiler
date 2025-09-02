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

static int arithop(int tokentype){
    switch(tokentype){
        case T_PLUS:
        return A_ADD;
        case T_MINUS:
        return  A_SUB;
        case T_MULTIPLY:
        return A_MUL;
        case T_DIVIDE:
        return A_DIV;
        default:
            fprintf(stderr,"syntax error on line %d, token %d \n",Line,tokentype);
        exit(1);
    }
}
struct ASTNode* additive_expr();


struct ASTNode* multiplicative_expr(){
    struct ASTNode* left,*right;

    int tokentype;

    left=primary();
    tokentype=Token.token;
    if(tokentype==T_EOF){
        return left;//end of file so no right component
    }
    while((tokentype==T_MULTIPLY)||(tokentype==T_DIVIDE)){
        // fetch next integer
        scan(&Token);
        right=primary();
    // join with the previous left tree to make the new left part
        left=makeASTNode(arithop(tokentype),left,right,0);
        // move on to the next token here
        tokentype=Token.token;
        if(tokentype==T_EOF) break;
    }
    return left;
}


struct ASTNode* additive_expr(){
    // so what we have is either an additive expr with a multiplicative_expr
    // or we have 2 mul expr with a + or - in between
    struct ASTNode *left,*right;
    int tokentype;
    // setup
    tokentype=Token.token;
    left=multiplicative_expr();


    if(tokentype==T_EOF)
        return left;

    while((tokentype==T_PLUS)||(tokentype==T_MINUS)){
        // fetch next integer
scan(&Token);
right=primary();
        left=makeASTNode(arithop(tokentype), left, right, 0);

tokentype=Token.token;
        if(tokentype==T_EOF) break;
    }
    return left;

}
// now we make the function that creates the actual tree
//right now we have mo heirarchy between the operators
struct ASTNode* binary_exp(){
return additive_expr();
}
