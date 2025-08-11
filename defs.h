#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Token{
    int token;
    int intvalue;
};

//enum of values token can take
enum{
T_MINUS,
T_PLUS,
T_MULTIPLY,
T_DIVIDE,
T_INTLIT//when token is this the intvalue field holds value of integer we took in via scanner
};

enum{
    A_ADD,A_SUB,A_MUL,A_DIV,A_INTLIT
};

struct ASTNode{
    int op;//operator
    struct ASTNode* left;
    struct ASTNode* right;
    int intvalue;//for INTLIT

};


