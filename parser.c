
// Code for chapter 6 on Parsing
// by Collin Gordon
#include <editline/readline.h>
#include <editline/history.h>
#include "mpc.h"

int main(int argc, char** argv)
{
    
    mpc_parser_t *Number = mpc_new("number");
    mpc_parser_t *Operator = mpc_new("operator");
    mpc_parser_t *Expr = mpc_new("expr");
    mpc_parser_t *Lisp = mpc_new("lisp");

    mpca_lang(MPCA_LANG_DEFAULT,
    " \
    number   : /-?[0-9]+/ ; \
    operator : '+' | '-' | '*' | '/' ; \
    expr     :  <number>| '(' <operator> <expr> + ')' ; \
    lisp     : /^/ <operator> <expr>+ /$/ ; \
    ", Number, Operator, Expr, Lisp);

    while(1)
    {
        char *input = readline("lisp> ");
        add_history(input);
        mpc_result_t r;
        if(mpc_parse("<stdin>",input,Lisp,&r))
        {
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        }
        else
        {
           mpc_err_print(r.error);
           mpc_err_delete(r.error); 
        }
    }
    mpc_cleanup(4, Number, Operator, Expr, Lisp);
    return 0;
}