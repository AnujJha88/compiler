#include "data.h"
#include "defs.h"

int LineNumber = 1;
int Putback = 0;
// FILE *Infile = NULL; // need to figure this out
static int next(void){
  int c;
  if(Putback){
    c=Putback;
    Putback=0;
    return c;

  }
    c=fgetc(Infile);

    if('\n'==c){
        LineNumber++;
    }
    return c;
}


static void putback(int c){
    Putback=c;
}

static int skip(void){
    int c;
    c=next();
    while(c==' ' || c=='\t' || c=='\n'|| c=='\r'|| c=='\f'){
        c=next();
    }
    return c;
}


int scan(struct Token *t){
    int c;
    c=skip();
    switch(c){
        case  EOF:
            return 0;
        case '+':
            t->token = T_PLUS;
            break;
        case '-':
            t->token = T_MINUS;
            break;
        case '*':
            t->token = T_MULTIPLY;
            break;
        case '/':
            t->token = T_DIVIDE;
            break;
        default:

        if(isdigit(c)){
            t->intvalue=scanint(c);
            t->token=T_INTLIT;
            break;
        }
        printf("Unrecognised character %c on line %d \n",c,LineNumber);
    }
    return(1);
}


static scanint(int c){
    
}