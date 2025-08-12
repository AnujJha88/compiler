// lexer, parser and then some semantic analysis
//then convert into a lower level language
#include<stdio.h>
#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include <errno.h>
#include "decl.h"


static void init() {
  Line = 1;
  Putback = '\n';
}

static void usage(char *prog){
    fprintf(stderr,"usafe: %s infile \n",prog);
}
// char *tokstr[] = { "-", "+", "*", "/", "intlit" };

// static void scanfile(){

//     struct Token t;
//     while(scan(&t)){
//         printf("Token %s",tokstr[t.token]);
//         if(t.token==T_INTLIT)printf(", value %d", t.intvalue);
//         printf("\n");
//     }
// }

void main(int argc,char* argv[]){
    struct ASTNode* n;

    if (argc != 2)
        usage(argv[0]);

    init();

   if ((Infile = fopen(argv[1], "r")) == NULL) {
    // if file aint there or sonmthing it'll exit
    fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
    exit(1);
   }
    scan(&Token);
    n=binary_exp();
    printf("%d \n",interpretAST(n));
    exit(0);
}
