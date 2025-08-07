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

