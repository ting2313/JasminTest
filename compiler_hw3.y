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
/*function table*/
typedef struct{
    char name[20];
    char a_type[10];
    char type[10];
}func_row;
func_row f_table[32] = {};
int max_f = -1;
int count_p = 0;
int lookup_func();
void print_func();

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
void print_stable();

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
void print_stack();

/* code generation functions, just an example! */
void gencode_function();
void gencode_print();
element gencode_cast();
void gencode_push();
void gencode_exp();
void gencode_assign();
char gencode_atype();

%}

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
%left EQ NE LT LTE MT MTE AND OR NOT
%left '+' '-'
%left '*' '/' '%'
%left LB RB LCB RCB LSB RSB COMMA
%left INC DEC

%left <i_val> I_CONST
%left <f_val> F_CONST
%left <i_val> B_CONST
%left <string> STR_CONST ID VOID INT FLOAT STRING BOOL

%type <string> postfix func_def argu input_argu arguments declaration_type after_value expression type compound_stat equal_rhs value
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
            if(!strcmp($3,"0")){
                fprintf(file, "\tldc 0\n");
            }
            if(!strcmp($1,"float")){
                fprintf(file, "\tfstore %d\n", max_reg);
                insert_symbol($2,"float",max_reg,scope);
            }else{
                fprintf(file, "\tistore %d\n", max_reg);
                insert_symbol($2,"int",max_reg,scope);
            }
        }else{
            //globol variable
            if(!strcmp($1,"float")){
                fprintf(file,
                    ".field public static %s F=%s\n", $2,$3);
                insert_symbol($2,"float",-1,scope);
            }else{
                fprintf(file,
                    ".field public static %s I=%s\n", $2,$3);
                insert_symbol($2,"int",-1,scope);
            }
        }
    }
;

declaration_type    //string:the number of answer;
    :'=' value{
        element rhs = pop();
        if(scope){
            gencode_push(rhs);
        }
        char temp[10] = {0};
        sprintf(temp, "%s",$2);
        $$ = strdup(temp);
    }
    | {
        $$ = "0";
    }    //declaring without init value
;

func_def
    : type ID LB arguments RB{
        int r[max_reg+1];
        for(int i=0;i<=max_reg;i++){
            r[i] = s_table[max_index-i].reg;
        }
        int j=0;
        for(int i=max_reg;i>=0;i--){
            s_table[max_index-j].reg=r[max_reg-j];
            j++;
        }

        func_row new;
        max_f++;
        sprintf(new.name,"%s",$2);
        sprintf(new.a_type,"%s",$4);

        char temp[10]={0};
        sprintf(temp,"%s",$1);
        $$=strdup(temp);
        //start a function
        fprintf(file,
            ".method public static %s",$2);
        if(!strcmp($2,"main")){
            fprintf(file,
                "([Ljava/lang/String;)V\n");
        }else{
            fprintf(file,"(%s)",$4);
            if(!strcmp($1,"void")){
                fprintf(file, "V\n");
                sprintf(new.type,"V");
            }else if(!strcmp($1,"int")){
                fprintf(file, "I\n");
                sprintf(new.type,"I");
            }else{
                fprintf(file, "F\n");
                sprintf(new.type,"F");
            }
        }
        fprintf(file, ".limit stack 50\n");
        fprintf(file, ".limit locals 50\n");
        f_table[max_f] = new;
    }
    | type ID LB RB{
        func_row new;
        max_f++;
        char temp[10]={0};
        sprintf(temp,"%s",$1);
        $$=strdup(temp);
        fprintf(file,
            ".method public static %s",$2);
        if(!strcmp($2,"main")){
            fprintf(file,
                "([Ljava/lang/String;)V\n");
        }else{
            fprintf(file,"()");
            if(!strcmp($1,"void")){
                fprintf(file, "V\n");
                sprintf(new.type,"V");
            }else if(!strcmp($1,"int")){
                fprintf(file, "I\n");
                sprintf(new.type,"I");
            }else{
                fprintf(file, "F\n");
                sprintf(new.type,"F");
            }
        }
        fprintf(file, ".limit stack 50\n");
        fprintf(file, ".limit locals 50\n");

        sprintf(new.name,"%s",$2);
        sprintf(new.a_type," ");
        f_table[max_f] = new;
    }
;

arguments
    : type ID COMMA arguments {
        char temp[10]={0};
        sprintf(temp,"%c%s",gencode_atype($1),$4);
        $$=strdup(temp);
        max_reg++;
        max_index++;
        insert_symbol($2,$1,max_reg,scope+1);
    }
    | argu {
        char temp[10] = {0};
        sprintf(temp,"%s",$1);
        $$=strdup(temp);
    }
;

argu
    : type ID{
        char temp[10] = {0};
        sprintf(temp,"%c",gencode_atype($1));
        $$=strdup(temp);
        max_reg=-1;
        max_reg++;
        max_index++;
        insert_symbol($2,$1,max_reg,scope+1);
    }
;

input_argu
    : value COMMA input_argu{
        count_p++;
    }
    | value{
        count_p = 1;
    }
;

compound_stat
    : statments end_stat RCB    {
    }
;

end_stat
    : RETURN end_semi{

    }
    |{

    }
;

end_semi
    : SEMICOLON{
        fprintf(file, "\treturn\n");
        fprintf(file, ".end method\n");
    }
    | value SEMICOLON{
        element rv = pop();
        gencode_push(rv);
        if(!strcmp(rv.type,"int")){
            fprintf(file, "\tireturn\n");
        }else if(!strcmp(rv.type,"float")){
            fprintf(file, "\tfreturn\n");
        }
        fprintf(file, ".end method\n");
    }

statments
    : stat statments
    |
;

stat
    : declaration SEMICOLON
    | ID equal_rhs SEMICOLON{
        int i = lookup_symbol($1);
        if(strcmp($2,"no")){
            gencode_assign(i,$2);
        }
        element lhs;
        sprintf(lhs.type,"%s",s_table[i].type);
        element rhs = pop();
        gencode_push(rhs);
        rhs=gencode_cast(rhs,lhs,1);
        if(!strcmp(s_table[i].type,"int")){
            fprintf(file, "\tistore %d\n",s_table[i].reg);
        }else{
            fprintf(file, "\tfstore %d\n",s_table[i].reg);
        }
    }
    | WHILE LB condition RB LCB compound_stat
    | IF LB condition RB LCB compound_stat else_scope
    | PRINT LB print_word RB SEMICOLON
    | value postfix SEMICOLON{
        element v = pop();
        gencode_push(v);
        fprintf(file, "\tldc 1\n");
        fprintf(file, "\t%s\n",$2);
        fprintf(file, "\tistore %d\n", s_table[atoi(v.value)].reg);
    }
    | ID LB input_argu RB SEMICOLON{
        int i = lookup_func($1);
        element p[count_p];
        for(int j=count_p-1;j>=0;j--){
            p[j] = pop();
        }
        for(int j=0;j<count_p;j++){
            gencode_push(p[j]);
        }

        fprintf(file,
            "\tinvokestatic compiler_hw3/%s(%s)V\n",
            $1,f_table[i].a_type);
    }
    | ID LB RB SEMICOLON{
        fprintf(file,
            "\tinvokestatic compiler_hw3/%s()V\n",$1);
    }
;

else_scope
    : ELSE LCB compound_stat
    | ELSE IF LB condition RB LCB compound_stat else_scope
    |
;

print_word
    : ID{
        int i = lookup_symbol($1);
        if(s_table[i].reg==-1){     //static
            if(!strcmp(s_table[i].type,"int")){
                fprintf(file,
                    "\tgetstatic compiler_hw3/%s I\n",
                    s_table[i].name);
            }else{
                fprintf(file,
                    "\tgetstatic compiler_hw3/%s F\n",
                    s_table[i].name);
            }
        }else{
            if(!strcmp(s_table[i].type,"int")){
                fprintf(file,"\tiload %d\n",s_table[i].reg);
            }else if(!strcmp(s_table[i].type,"float")){
                fprintf(file,"\tfload %d\n",s_table[i].reg);
            }else{
                fprintf(file,"\taload %d\n",s_table[i].reg);
            }
        }
        gencode_print(s_table[i].type);
    }
    | STR_CONST{
        fprintf(file,"\tldc \"%s\"\n",$1);
        gencode_print("string");
    }
    | I_CONST{
        fprintf(file,"\tldc %d\n",$1);
        gencode_print("int");
    }
    | F_CONST{
        fprintf(file,"\tldc %f\n",$1);
        gencode_print("float");
    }
;

condition
    : value
    |
;

comparison
    : value EQ value{

    }
    | value MT value
    | value LT value
    | value MTE value
    | value LTE value
    | value NE value
;


equal_rhs
    :'=' value {
        $$="no";
    }
    | ADDASGN value {
        $$="add";
    }
    | SUBASGN value {$$="sub";}
    | MULASGN value {$$="mul";}
    | DIVASGN value {$$="div";}
    | MODASGN value {$$="rem";}
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
        int i=lookup_func($1);
        element p[count_p];
        for(int j=count_p-1;j>=0;j--){
            p[j] = pop();
        }
        for(int j=0;j<count_p;j++){
            gencode_push(p[j]);
        }
        fprintf(file,
            "\tinvokestatic compiler_hw3/%s(%s)%s\n",
            $1,f_table[i].a_type,f_table[i].type);
        if(!strcmp(f_table[i].type,"I")){
            push(0,"un","int");
        }else{
            push(0,"un","float");
        }
    }
    | T     {
        $$="1";
        push(1,"1","int");
    }
    | F     {
        $$="0";
        push(1,"1","int");
    }
;

after_value
    : expression {$$=strdup($1);}
    | comparison {$$="comparison";}
;

postfix
    : INC{
        char temp[10] = {0};
        sprintf(temp,"%s","iadd");
        $$ = strdup(temp);
    }
    | DEC{
        char temp[10] = {0};
        sprintf(temp,"%s","isub");
        $$ = strdup(temp);
    }
;

expression
    :value '+' value {
        gencode_exp("add",0);
    }
    |value '-' value {
        gencode_exp("sub",0);
    }
    |value '*' value {
        gencode_exp("mul",0);
    }
    |value '/' value {
        gencode_exp("div",0);
    }
    |value '%' value {
        gencode_exp("rem",0);
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
    printf("%d: ", yylineno+1);
    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");

    yyparse();
    printf("\nTotal lines: %d \n",yylineno);

    fclose(file);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno+1, buf);
    printf("| %s", s);
    printf("\n| Unmatched token: %s", yytext);
    printf("\n|-----------------------------------------------|\n");
    exit(-1);
}

/* function table */
int lookup_func(char* name) {
    /*reture the index in symbol table*/
    if(max_f==-1)   return -1;
    for(int i=0;i<=max_f;i++){
        if(!strcmp(f_table[i].name,name)){
            return i;
        }
    }
}

void print_func(){
    printf("----func----\n");
    for(int i=0;i<=max_f;i++){
        printf("%d:%s,%s,%s\n",i,f_table[i].name,
            f_table[i].type,f_table[i].a_type);
    }
    printf("----------------\n");
}

/* stmbol table functions */
void insert_symbol(char* name,char* type,int reg,int s) {
    s_table[max_index].reg = reg;
    s_table[max_index].scope = s;
    sprintf(s_table[max_index].name, "%s",name);
    sprintf(s_table[max_index].type, "%s",type);
}

int lookup_symbol(char* name) {
    /*reture the index in symbol table*/
    if(max_index==-1)   return -1;
    for(int i=0;i<=max_index;i++){
        if(!strcmp(s_table[i].name,name)){
            return i;
        }
    }
}

void print_stable(){
    printf("----s_table----\n");
    for(int i=0;i<=max_index;i++){
        printf("%d:%s,%s,%d\n",i,s_table[i].name,s_table[i].type,s_table[i].reg);
    }
    printf("----------------\n");
}

void dump_symbol() {
    if(max_index==-1)   return;
    for(int i=max_index;i>=0;i--){
        if(s_table[i].scope==scope){
            if(s_table[i].reg!=-1){
                max_reg--;
            }
            max_index--;
        }
    }
}

/* code generation functions */
void gencode_function() {}
void gencode_print(char* type){
    fprintf(file,
        "\tgetstatic java/lang/System/out "
        "Ljava/io/PrintStream;\n\tswap\n"
        "\tinvokevirtual "
        "java/io/PrintStream/println"
        );
    if(!strcmp(type,"int")){
        fprintf(file,"(I)V\n");
    }else if(!strcmp(type,"float")){
        fprintf(file,"(F)V\n");
    }else{
        fprintf(file,"(Ljava/lang/String;)V\n");
    }
}

/*return whether should put back item from register 50 */
void gencode_push(element v){

    if(v.know==1) {
        fprintf(file, "\tldc %s\n",v.value);
    }else if(v.know==-1){   //value is variable
        int i = atoi(v.value);
        if(s_table[i].reg==-1){   //globol
            if(!strcmp(v.type,"int")){
                fprintf(file,
                    "\tgetstatic compiler_hw3/%s I\n",
                    s_table[i].name);
            }else{
                fprintf(file,
                    "\tgetstatic compiler_hw3/%s F\n",
                    s_table[i].name);
            }
        }else{  //local
            if(!strcmp(v.type,"int")){
                fprintf(file, "\tiload %d\n",s_table[i].reg);
            }else{
                fprintf(file, "\tfload %d\n",s_table[i].reg);
            }
        }
    }
}

element gencode_cast(element v_cast,element v,int flag){
    //flag=1:assign flag=0:expr
    element ans = v_cast;
    if(strcmp(v_cast.type,v.type)){
        if(!strcmp(v_cast.type,"int")){
            fprintf(file, "\ti2f\n");
            sprintf(ans.type,"float");
        }else{
            if(flag){
                fprintf(file, "\tf2i\n");
                sprintf(ans.type,"int");
            }
        }
    }
    return ans;
}

void gencode_exp(char* op){
    element v1 = pop();
    element v2 = pop();

    gencode_push(v1);
    v1=gencode_cast(v1,v2,0);
    gencode_push(v2);
    v2=gencode_cast(v2,v1,0);

    fprintf(file, "\tswap\n");
    if(!strcmp(v1.type,"int")){
        fprintf(file, "\ti%s\n",op);
    }else{
        fprintf(file, "\tf%s\n",op);
    }
    push(0,"un",strdup(v1.type));
}

void gencode_assign(int lhs,char* op){
    char temp[10]={0};
    sprintf(temp,"%d",lhs);
    push(-1,temp,s_table[lhs].type);
    gencode_exp(op);
}

char gencode_atype(char* type){
    char c;
    if(!strcmp(type, "int")){
        c='I';
    }else{
        c='F';
    }
    return c;
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

void print_stack(){
    printf("----my stack----\n");
    for(int i=0;i<=top;i++){
        printf("%d:%d,%s\n",i,stack[i].know,stack[i].type);
    }
    printf("----------------\n");
}
