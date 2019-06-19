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
typedef struct{
    int reg;    //register,-1:globol
    int scope;
    char name[20];
    char type[10];
}symbol_row;
symbol_row s_table[128] = {};
int max_reg = -1;
int max_index = -1;
int scope = 0;

int lookup_symbol();
void insert_symbol();
void dump_symbol();

/* stack functions */
typedef struct{
    int know;   //1:const 0:sth in stack -1:variable
    char value[16]; //k=1:const val ; k=-1:s_index
    char type[16];  //int or float
}element;
element stack[50] = {0};
int top=-1;

void push();
element pop();
char* casting();

/* code generation functions, just an example! */
void gencode_function();
void gencode_exp();

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

%type <string> declaration_type after_value expression type compound_stat equal_rhs value
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
    | type ID LB arguments RB SEMICOLON {
        //Predeclared function

    }
    | func_def LCB func_compound{
        //define funciton
    }
;

func_compound
    : compound_stat

declaration
    : type ID declaration_type{
        max_index++;

        if(scope){
            //local variable
            max_reg++;
            fprintf(file, "\tldc %s\n",$3);
            if(!strcmp($1,"float")){
                fprintf(file, "\tfstore %d\n", max_reg);
                insert_symbol($2,"float",max_reg);
            }else{
                fprintf(file, "\tistore %d\n", max_reg);
                insert_symbol($2,"int",max_reg);
            }
        }else{
            //globol variable
            if(!strcmp($1,"float")){
                fprintf(file,
                    ".field public static %s F=%s\n", $2,$3);
                insert_symbol($2,"float",-1);
            }else{
                fprintf(file,
                    ".field public static %s I=%s\n", $2,$3);
                insert_symbol($2,"int",-1);
            }
        }
    }
;

declaration_type    //string:the number of answer;
    : '=' I_CONST{
        char temp[10] = {0};
        sprintf(temp, "%d",$2);
        $$ = strdup(temp);
    }
    | '=' F_CONST{
        char temp[10] = {0};
        sprintf(temp, "%f",$2);
        $$ = strdup(temp);
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
        // struction??
        push(item.know,item.value,item.type);
    }
    | STR_CONST     {$$=strdup($1);}
    | after_value     {

    }
    | LB value RB   {

    }
    | ID {
        $$=$1;
        char temp[10]={0};
        int i=lookup_symbol($1);
        sprintf(temp,"%d",i);
        push(-1,temp,s_table[i].type);
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
        gencode_exp("add");
    }
    |value '-' value {
        gencode_exp("sub");
    }
    |value '*' value {
        gencode_exp("mul");
    }
    |value '/' value {
        gencode_exp("div");
    }
    |value '%' value {
        gencode_exp("rem");
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
void insert_symbol(char* name,char* type,int reg) {
    s_table[max_index].reg = reg;
    s_table[max_index].scope = scope;
    sprintf(s_table[max_index].name, "%s",name);
    sprintf(s_table[max_index].type, "%s",type);
    printf("insert:%s,%d\n",s_table[max_index].name,
        s_table[max_index].reg);
}

int lookup_symbol(char* name) {
    /*reture the index in symbol table*/
    if(max_index==-1)   return -1;
    for(int i=0;i<=max_index;i++){
        if(!strcmp(s_table[i].name,name)){
            printf("lookup:%s,%d\n",
                s_table[i].name,i);
            return i;
        }
    }
}

void dump_symbol() {
    if(max_index==-1)   return;
    for(int i=max_index;i>=0;i--){
        if(s_table[i].scope==(scope-1)){
            if(s_table[i].reg!=-1){
                max_reg--;
            }
            max_index--;
        }
    }
}

/* code generation functions */
void gencode_function() {}
void gencode_exp(char* op){
    element v1 = pop();
    element v2 = pop();

    if(v1.know==1) fprintf(file, "\tldc %s\n",v1.value);
    else if(v1.know==-1){   //value is variable
        int i = atoi(v1.value);
        if(s_table[i].reg==-1){   //globol
            if(!strcmp(v2.type,"int")){
                fprintf(file,
                    "\tgetstatic compiler_hw3/%s I\n",
                    s_table[i].name);
            }else{
                fprintf(file,
                    "\tgetstatic compiler_hw3/%s F\n",
                    s_table[i].name);
            }
        }else{  //local
            if(!strcmp(v1.type,"int")){
                fprintf(file, "\tiload %d\n",s_table[i].reg);
            }else{
                fprintf(file, "\tfload %d\n",s_table[i].reg);
            }
        }
    }

    if(v2.know==1) fprintf(file, "\tldc %s\n",v2.value);
    else if(v2.know==-1){   //value is variable
        int i = atoi(v2.value);
        if(s_table[i].reg==-1){   //globol
            if(!strcmp(v2.type,"int")){
                fprintf(file,
                    "\tgetstatic compiler_hw3/%s I\n",
                    s_table[i].name);
            }else{
                fprintf(file,
                    "\tgetstatic compiler_hw3/%s F\n",
                    s_table[i].name);
            }
        }else{  //local
            if(!strcmp(v2.type,"int")){
                fprintf(file, "\tiload %d\n",s_table[i].reg);
            }else{
                fprintf(file, "\tfload %d\n",s_table[i].reg);
            }
        }
    }

    if(!strcmp(casting(v1,v2),"int")){
        fprintf(file, "\ti%s\n",op);
    }else{
        fprintf(file, "\tf%s\n",op);
    }

    push(0,"un",casting(v1,v2));
}

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
}

char* casting(element v1, element v2){
    if(!strcmp(v1.type,v2.type)){
        return strdup(v1.type);
    }else{
        return "float";
    }
}
