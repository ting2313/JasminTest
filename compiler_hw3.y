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
struct symbol_row{
    int number;
    int scope;
    char name[20];
    char data_type[10];
};
struct symbol_row s_table[50] = {};
int max_index = 0;
int scope = 0;

int lookup_symbol();
void create_symbol_table();
void free_symbol_table();
void insert_symbol();
void dump_symbol();

/* stack functions */
typedef struct{
    int know;   //1:const 0:sth in stack -1:variable
    char value[16];
    char type[16];  //int or float
}element;
element stack[50] = {0};
int top=-1;

void push();
element pop();
char* casting();

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

%type <string> after_value expression type compound_stat declaration_type equal_rhs value
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

                /*maintain symbol table*/

            }else{
                fprintf(file, "\tistore %d\n", max_index);
                max_index++;

                /*maintain symbol table*/
            }
        }else{
            //globol variable
            if(!strcmp($1,"float")){
                fprintf(file,
                    ".field public static %s F=%s\n", $2,$3);
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
    :'=' value {
        $$=$2;
        //element item = pop();
    }
    | ADDASGN value {$$=$2;}
    | SUBASGN value {$$=$2;}
    | MULASGN value {$$=$2;}
    | DIVASGN value {$$=$2;}
    | MODASGN value {$$=$2;}
;

value
    : I_CONST   {
        char temp[10]={0};
        sprintf(temp,"%d",$1);
        $$=strdup(temp);
        push(1,temp,"int");
    }
    | F_CONST   {
        char temp[10]={0};
        sprintf(temp,"%f",$1);
        $$=strdup(temp);
        push(1,temp,"float");
    }
    | '-' value     {
        $$=strdup($2);
        element item = pop();
        sprintf(item.value,"-%s",item.value);
        push(item.know,item.value,item.type);
    }
    | STR_CONST     {$$=strdup($1);}
    | after_value     {

    }
    | LB value RB   {

    }
    | ID {
        //find index
        //push
    }
    | ID LB input_argu RB{

    }
    | T     {$$="1";}
    | F     {$$="0";}
;



;

after_value
    : expression {$$=strdup($1);}
    | comparison {$$="comparison";}
;

postfix
    : INC
    | DEC
;

expression
    :value '+' value {
        element v1 = pop();
        element v2 = pop();
        printf("value+value\n");
        if(v1.know==1) fprintf(file, "\tldc %s\n",v1.value);
        if(v2.know==1) fprintf(file, "\tldc %s\n",v2.value);

        if(!strcmp(casting(v1,v2),"int")){
            fprintf(file, "\tiadd\n");
        }else{
            fprintf(file, "\tfadd\n");
        }
        push(0,"un",casting(v1,v2));
    }
    |value '-' value {
        element v1 = pop();
        element v2 = pop();
        printf("value-value\n");
        if(v1.know==1) fprintf(file, "\tldc %s\n",v1.value);
        if(v2.know==1) fprintf(file, "\tldc %s\n",v2.value);
        if(!strcmp(casting(v1,v2),"int")){
            fprintf(file, "\tisub\n");
        }else{
            fprintf(file, "\tfsub\n");
        }
        push(0,"un",casting(v1,v2));
    }
    |value '*' value {
        element v1 = pop();
        element v2 = pop();
        printf("value*value\n");
        if(v1.know==1) fprintf(file, "\tldc %s\n",v1.value);
        if(v2.know==1) fprintf(file, "\tldc %s\n",v2.value);
        if(!strcmp(casting(v1,v2),"int")){
            fprintf(file, "\timul\n");
        }else{
            fprintf(file, "\tfmul\n");
        }
        push(0,"un",casting(v1,v2));
    }
    |value '/' value {
        element v1 = pop();
        element v2 = pop();
        printf("value/value\n");
        if(v1.know==1) fprintf(file, "\tldc %s\n",v1.value);
        if(v2.know==1) fprintf(file, "\tldc %s\n",v2.value);
        if(!strcmp(casting(v1,v2),"int")){
            fprintf(file, "\tidiv\n");
        }else{
            fprintf(file, "\tfdiv\n");
        }
        push(0,"un",casting(v1,v2));
    }
    |value '%' value {
        element v1 = pop();
        element v2 = pop();
        printf("value mod value\n");
        if(v1.know==1) fprintf(file, "\tldc %s\n",v1.value);
        if(v2.know==1) fprintf(file, "\tldc %s\n",v2.value);
        if(!strcmp(casting(v1,v2),"int")){
            fprintf(file, "\tirem\n");
        }else{
            //error!!!!
        }
        push(0,"un","int");
    }
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

/*stack funtions*/
element pop(){
    if(top==-1){
        printf("pop error!\n");
    }
    return stack[top--];
}

void push(int know,char* value, char* type){
    top++;
    stack[top].know = know;
    sprintf(stack[top].value,"%s",value);
    sprintf(stack[top].type,"%s",type);
    printf("push:index:%d(%s,%s)\n",top,stack[top].value,stack[top].type);
}

char* casting(element v1, element v2){
    if(!strcmp(v1.type,v2.type)){
        return strdup(v1.type);
    }else{
        return "float";
    }
}
