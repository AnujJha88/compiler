int scan(struct Token* t);
struct ASTNode *makeASTNode(int op, struct ASTNode *left,
			  struct ASTNode *right, int intvalue);
struct ASTNode *makeleaf(int op, int intvalue);
struct ASTNode *makeunary(int op, struct ASTNode *left, int intvalue);
struct ASTNode *binary_exp(void);
int interpretAST(struct ASTNode *n);

