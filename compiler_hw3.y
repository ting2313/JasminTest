/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
extern int yylex();
extern char *yytext; // Get current token from lex
extern char buf[256]; // Get current code line from lex

FILE *file; // To generate .j file for Jasmin

void yyerror(char *s);

/* symbol table functions */
int lookup_symbol();
void create_symbol_table();
void free_symbol_table();
void insert_symbol();
void dump_symbol();

struct symbol_row{
    int number;
    int scope;
    char name[20];
    char data_type[10];
};
struct symbol_row s_table[50] = {};
int max_index = 0;
int scope = 0;
/* code generation functions, just an example! */
void gencode_function();

%}

%union {
    int i_val;
    double f_val;
    char* string;
}

/* Token without return */
%left '=' RETURN TRUE FALSE
%left ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%left PRINT
%left IF ELSE FOR WHILE T F
%left SEMICOLON
%left EQ NE LT LTE MT MTE AND OR NOT
%left '+' '-'
%left '*' '/' '%'
%left LB RB LCB RCB LSB RSB COMMA
%left INC DEC

%left <i_val> I_CONST
%left <f_val> F_CONST
%left <i_val> B_CONST
%left <string> STR_CONST ID VOID INT FLOAT STRING BOOL

%type <string> type compound_stat function_call declaration_type equal_rhs value
/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : external_stat program
    |
;

external_stat
    : declaration SEMICOLON
    | func_def LCB func_compound{

    }
;

func_compound
    : compound_stat

declaration
    : type ID declaration_type{
        if(scope){
            //local variable
            fprintf(file, "\tldc %s\n",$3);
            if(!strcmp($1,"float")){
                fprintf(file, "\tfstore %d\n", max_index);
                max_index++;
            }else{
                fprintf(file, "\tistore %d\n", max_index);
                max_index++;
            }
        }else{
            //globol variable
            if(!strcmp($1,"float")){
                fprintf(file,
                    ".field public static %s F=0\n", $2);
            }else{
                fprintf(file,
                    ".field public static %s I=%s\n", $2,$3);
            }
        }
    }
;

declaration_type    //string:the number of answer;
    : equal_rhs{
        $$ = $1;
    }
    | LB arguments RB   {

    }
    | {$$ = "0";}    //declaring without init value
;

func_def
    : type ID LB arguments RB{
        //start a function
        fprintf(file,
            ".method public static %s([Ljava/lang/String;)V\n",$2);
        //fprintf(file, "");
        fprintf(file, "\t.limit stack 50\n");
    }
;

arguments
    : type ID arguments{

    }
    | COMMA type ID arguments{

    }
    |   {
    }
;

input_argu
    : value input_argu
    | COMMA value input_argu
    |
;

compound_stat
    : statments end_stat RCB    { }
;

end_stat
    : RETURN end_semi
    |
;

end_semi
    : SEMICOLON
    | value SEMICOLON

statments
    : stat statments
    |
;

stat
    : declaration SEMICOLON
    | ID equal_rhs SEMICOLON{
    }
    | WHILE LB condition RB LCB compound_stat
    | IF LB condition RB LCB compound_stat else_scope
    | PRINT LB print_word RB SEMICOLON
    | value postfix SEMICOLON
    | ID LB input_argu RB SEMICOLON{
    }
;

else_scope
    : ELSE LCB compound_stat
    | ELSE IF  LB condition RB LCB compound_stat else_scope
    |
;

print_word
    : ID
    | STR_CONST
;

condition
    : value
    |
;

comparison
    : EQ value
    | MT value
    | LT value
    | MTE value
    | LTE value
    | NE value
;


equal_rhs
    :'=' value {$$=$2;}
    | ADDASGN value {$$=$2;}
    | SUBASGN value {$$=$2;}
    | MULASGN value {$$=$2;}
    | DIVASGN value {$$=$2;}
    | MODASGN value {$$=$2;}
;

value
    : I_CONST   {char temp[10]={0};sprintf(temp,"%d",$1);$$=temp;}
    | F_CONST   {}
    | '-' value     {}
    | STR_CONST     {$$=$1;}
    | value after_value     {}
    | LB value RB   {}
    | ID function_call{
    }
    | T     {$$="1";}
    | F     {$$="0";}
;

function_call
    : LB input_argu RB{
        $$ = "funciton";
    }
    | {
        $$ = "ID";
    }
;

after_value
    : expression
    | comparison
;

postfix
    : INC
    | DEC
;

expression
    : '+' value
    | '-' value
    | '*' value
    | '/' value
    | '%' value
;

/* actions can be taken when meet the token or rule */
type
    : INT
    | FLOAT
    | BOOL
    | STRING
    | VOID
;

%%

/* C code section */

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;

    file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");

    yyparse();
    printf("\nTotal lines: %d \n",yylineno);

    fprintf(file, "\treturn\n"
                  ".end method\n");

    fclose(file);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n| Unmatched token: %s", yytext);
    printf("\n|-----------------------------------------------|\n");
    exit(-1);
}

/* stmbol table functions */
void create_symbol() {}
void insert_symbol() {}
int lookup_symbol() {}
void dump_symbol() {}

/* code generation functions */
void gencode_function() {}
