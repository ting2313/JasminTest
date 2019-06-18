/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern void yyerror(char *s);
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
int max_scope;

/* Symbol table function - you can add new function if needed. */
int lookup_symbol();
void create_symbol();
void insert_symbol();
void dump_symbol();
void print_symbol();
void insert_list();

struct row{
    char name[10];
    char entry_type[12]; //fuction, parameter and variable
    char data_type[10]; // a type(int,float,bool,string and void)
    int scope;
    char argu_type[32];
    int define;     // if defined, define = 1; else define = 0
    struct row* next;
};
typedef struct row* rowptr;
int donot_print;
rowptr head,tail,new_func,new_argu, list_head, list_tail;

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char* string;
}

/* Token without return */
%left '=' RETURN
%left ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%left PRINT
%left IF ELSE FOR WHILE T F
%left SEMICOLON
%left EQ NE LT LTE ML MLE AND OR NOT
%left '+' '-'
%left '*' '/' '%'
%left LB RB LCB RCB LSB RSB COMMA
%left INC DEC


/* Token with return, which need to sepcify type */
%left <i_val> I_CONST
%left <f_val> F_CONST
%left <i_val> B_CONST
%left <string> STR_CONST ID VOID INT FLOAT STRING BOOL

/* Nonterminal with return, which need to sepcify type */
%type <string> type compound_stat function_call

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
    | func_def
;

func_def
    : type ID LB arguments RB compound_stat{
        if(!strcmp($6, "pre")) {
            max_scope++;
            donot_print = 1;
            dump_symbol();
        }
        int ID_state = lookup_symbol($2, "function");
        if(ID_state==1){
            // Redeclared
            char mesg[20] = {};
            sprintf(mesg,"Redeclared function %s", $2);
            yyerror(mesg);
        }else if(ID_state==-1){
            // Already Predeclared
        }else{
            // Add
            sprintf(new_func->data_type, "%s", $1);
            sprintf(new_func->entry_type, "function");
            sprintf(new_func->name, "%s", $2);
            if(!strcmp($6, "pre")){
                new_func->define = 0;
            }else{
                new_func->define = 1;
            }
            new_func->scope = 0;
            insert_symbol(new_func);
        }
    }
;

arguments
    : type ID arguments{
        rowptr new = malloc(sizeof(struct row));
        new->next = NULL;
        sprintf(new->name, "%s", $2);
        sprintf(new->data_type, "%s", $1);
        sprintf(new->entry_type, "parameter");
        new->scope = max_scope+1;

        if(!strcmp(new_func->argu_type,"")){
            list_head = list_tail = new;
            sprintf(new_func->argu_type, "%s", $1);
        }else{
            list_tail->next = new;
            list_tail = new;
            char temp[32] = {};
            strcpy(temp, new_func->argu_type);
            sprintf(new_func->argu_type, "%s%s", $1, temp);
        }

        insert_list();
    }
    | COMMA type ID arguments{
        rowptr new = malloc(sizeof(struct row));
        new->next = NULL;
        sprintf(new->name, "%s", $3);
        sprintf(new->data_type, "%s", $2);
        sprintf(new->entry_type, "parameter");
        new->scope = max_scope+1;

        if(!strcmp(new_func->argu_type,"")){
            list_head = list_tail = new;
            sprintf(new_func->argu_type, ", %s", $2);
        }else{
            list_tail->next = new;
            list_tail = new;
            char temp[32] = {};
            strcpy(temp, new_func->argu_type);
            sprintf(new_func->argu_type, ", %s%s", $2, temp);
        }
    }
    |   {
        bzero(new_func->argu_type, sizeof(new_func->argu_type));
        break;
    }
;

input_argu
    : value input_argu
    | COMMA value input_argu
    |
;

compound_stat
    : LCB statments end_stat RCB {
        $$ = "def";
    }
    | SEMICOLON {
        $$ = "pre";
    }
;

end_stat
    : RETURN value SEMICOLON
    |
;

statments
    : stat statments
    |
;

stat
    : declaration SEMICOLON
    | ID equal_rhs SEMICOLON{
        if(!lookup_symbol($1, "variable")&&
            !lookup_symbol($1, "parameter")){
                char mesg[20] = {};
                sprintf(mesg,"Undeclared variable %s", $1);
                yyerror(mesg);
        }
    }
    | WHILE LB condition RB compound_stat
    | IF LB condition RB compound_stat else_scope
    | PRINT LB print_word RB SEMICOLON
    | value postfix SEMICOLON
    | ID LB input_argu RB SEMICOLON{
        if(!lookup_symbol($1, "function")){
                char mesg[20] = {};
                sprintf(mesg,"Undeclared function %s", $1);
                yyerror(mesg);
        }
    }
;

else_scope
    : ELSE compound_stat
    | ELSE IF  LB condition RB compound_stat else_scope
    |
;

print_word
    : ID{
        if(!lookup_symbol($1, "variable")&&
            !lookup_symbol($1, "parameter")){
                char mesg[20] = {};
                sprintf(mesg,"Undeclared variable %s", $1);
                yyerror(mesg);
        }
    }
    | STR_CONST
;

condition
    : value
    |
;

comparison
    : EQ value
    | ML value
    | LT value
    | MLE value
    | LTE value
    | NE value
;

declaration
    : type ID equal_rhs{
        if(lookup_symbol($2, "variable")){
                char mesg[20] = {};
                sprintf(mesg,"Redeclared variable %s", $2);
                yyerror(mesg);
        }else{
            sprintf(new_argu->name,"%s", $2);
            sprintf(new_argu->data_type, "%s", $1);
            sprintf(new_argu->entry_type, "variable");
            bzero(new_argu->argu_type, sizeof(new_argu->argu_type));
            new_argu->scope = max_scope;
            insert_symbol(new_argu);
        }
    }
;

equal_rhs
    :'=' value
    | ADDASGN value
    | SUBASGN value
    | MULASGN value
    | DIVASGN value
    | MODASGN value
    |
;

value
    : I_CONST
    | F_CONST
    | '-' value
    | STR_CONST
    | value after_value
    | LB value RB
    | ID function_call{
        if(!strcmp($2, "ID")){
            if(!lookup_symbol($1, "variable")&&
                !lookup_symbol($1, "parameter")){
                    char mesg[20] = {};
                    sprintf(mesg,"Undeclared variable %s", $1);
                    yyerror(mesg);
            }
        }else{
            if(!lookup_symbol($1, "function")){
                    char mesg[20] = {};
                    sprintf(mesg,"Undeclared function %s", $1);
                    yyerror(mesg);
            }
        }
    }
    | T
    | F
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
int main(int argc, char** argv)
{
    yylineno = 0;
    donot_print = 0;
    printf("%d: ", yylineno+1);
    create_symbol();
    yyparse();
	printf("\nTotal lines: %d \n",yylineno);
    free(new_func);
    free(new_argu);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno+1, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol() {
    new_func = malloc(sizeof(struct row));
    new_argu = malloc(sizeof(struct row));
    head = tail = list_tail = list_head = NULL;
    max_scope = 0;
}

void insert_symbol(rowptr new){
    rowptr add = malloc(sizeof(struct row)); //the memory address of new
    sprintf(add->name,"%s",new->name);
    sprintf(add->entry_type,"%s",new->entry_type);
    sprintf(add->data_type,"%s",new->data_type);
    sprintf(add->argu_type,"%s",new->argu_type);
    add->scope = new->scope;
    add->next = NULL;
    if(head==NULL){
        head = tail = add;
    }else{
        tail->next = add;
        tail = add;
    }
    bzero(new, sizeof(new));
}

void insert_list(){
    rowptr target, pro;
    pro = target = list_head;
    while(1){
        while(pro->next){
            pro = pro->next;
            if(pro==tail){
                break;
            }
            target = pro;
        }
        if(head==NULL){
            head = tail = target;
            target->next = NULL;
        }else{
            tail->next = target;
            tail = target;
            tail->next = NULL;
        }
        pro = target = list_head;
        if(target->next==NULL)    break;
    }
    list_tail = list_head = NULL;
}

/*1: in table  0:not in table  -1:in table but not define*/
int lookup_symbol(char* name, char* type) {
    if(head==NULL)  return 0;
    rowptr point = head;
    while(point!=NULL){
        if(!strcmp(point->entry_type, type)){
            if(!strcmp(point->name, name)){
                if(point->define){
                    return 1;
                }else{
                    point->define = 1;
                    return -1;
                }
            }
        }
        point = point->next;
    }
    return 0;
}

void dump_symbol() {

    if(head==NULL) {
        //printf("Table is empty.\n");
        return;  //no need to dump
    }
    else if(tail->scope != max_scope){
        //printf("The scope %d is empty.\n",max_scope);
        max_scope--;
        return;
    }
    int flag_print = donot_print;
    donot_print = 0;
    if(!flag_print){
        printf("\n\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
            "Index", "Name", "Kind", "Type", "Scope", "Attribute");
    }
    rowptr print = head;
    rowptr pre = print;
    int index = 0;
    int flag = 0;
    if(head->scope==max_scope){
        head = NULL;
    }
    /*find the row of the biggest scope*/
    while(1){
        char compare[32] = {};
        if(print->scope==max_scope){
            if(flag==1){
                tail->next = NULL;
                flag = -1;
            }else if (flag==0){
                tail = NULL;
            }
            if(!flag_print){
                printf("%-10d%-10s%-12s%-10s%-10d%s\n",
                    index, print->name, print->entry_type,\
                    print->data_type, print->scope, print->argu_type);
            }
            print = print->next;
            free(pre);
            pre = print;
            index++;
            if(print==NULL) break;
        }else{
            tail = print;
            pre = print = print->next;
            flag = 1;
            continue;
        }
    }
    if(max_scope>0) max_scope--;
}

void print_symbol(){
    if(head==NULL){
        return;
    }

    printf("\n\n----------PRINT ALL----------\n");
    printf("%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
        "Index", "Name", "Kind", "Type", "Scope", "Attribute");
    rowptr print = head;
    int index = 0;
    /*find the row of the biggest scope*/
    while(1){
        printf("%-10d%-10s%-12s%-10s%-10d%-10s\n",
            index, print->name, print->entry_type,\
            print->data_type, print->scope, print->argu_type);
        print = print->next;
        index++;
        if(print==NULL) break;
    }
}
