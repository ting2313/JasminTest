/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

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


#line 133 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    RETURN = 258,
    TRUE = 259,
    FALSE = 260,
    ADDASGN = 261,
    SUBASGN = 262,
    MULASGN = 263,
    DIVASGN = 264,
    MODASGN = 265,
    PRINT = 266,
    IF = 267,
    ELSE = 268,
    FOR = 269,
    WHILE = 270,
    T = 271,
    F = 272,
    SEMICOLON = 273,
    EQ = 274,
    NE = 275,
    LT = 276,
    LTE = 277,
    MT = 278,
    MTE = 279,
    AND = 280,
    OR = 281,
    NOT = 282,
    LB = 283,
    RB = 284,
    LCB = 285,
    RCB = 286,
    LSB = 287,
    RSB = 288,
    COMMA = 289,
    INC = 290,
    DEC = 291,
    I_CONST = 292,
    F_CONST = 293,
    B_CONST = 294,
    STR_CONST = 295,
    ID = 296,
    VOID = 297,
    INT = 298,
    FLOAT = 299,
    STRING = 300,
    BOOL = 301
  };
#endif
/* Tokens.  */
#define RETURN 258
#define TRUE 259
#define FALSE 260
#define ADDASGN 261
#define SUBASGN 262
#define MULASGN 263
#define DIVASGN 264
#define MODASGN 265
#define PRINT 266
#define IF 267
#define ELSE 268
#define FOR 269
#define WHILE 270
#define T 271
#define F 272
#define SEMICOLON 273
#define EQ 274
#define NE 275
#define LT 276
#define LTE 277
#define MT 278
#define MTE 279
#define AND 280
#define OR 281
#define NOT 282
#define LB 283
#define RB 284
#define LCB 285
#define RCB 286
#define LSB 287
#define RSB 288
#define COMMA 289
#define INC 290
#define DEC 291
#define I_CONST 292
#define F_CONST 293
#define B_CONST 294
#define STR_CONST 295
#define ID 296
#define VOID 297
#define INT 298
#define FLOAT 299
#define STRING 300
#define BOOL 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 69 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;

#line 271 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 288 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
       2,     2,    31,    29,     2,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   101,   105,   106,   110,   116,   119,   150,
     159,   165,   209,   243,   251,   259,   271,   274,   280,   285,
     288,   294,   298,   310,   311,   315,   316,   332,   333,   334,
     335,   336,   351,   358,   359,   360,   364,   387,   391,   395,
     402,   403,   407,   410,   411,   412,   413,   414,   419,   422,
     425,   426,   427,   428,   432,   439,   445,   446,   449,   452,
     459,   478,   479,   483,   484,   488,   489,   493,   496,   499,
     502,   505,   512,   513,   514,   515,   516
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "RETURN", "TRUE", "FALSE",
  "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "PRINT", "IF",
  "ELSE", "FOR", "WHILE", "T", "F", "SEMICOLON", "EQ", "NE", "LT", "LTE",
  "MT", "MTE", "AND", "OR", "NOT", "'+'", "'-'", "'*'", "'/'", "'%'", "LB",
  "RB", "LCB", "RCB", "LSB", "RSB", "COMMA", "INC", "DEC", "I_CONST",
  "F_CONST", "B_CONST", "STR_CONST", "ID", "VOID", "INT", "FLOAT",
  "STRING", "BOOL", "$accept", "program", "external_stat", "func_compound",
  "declaration", "declaration_type", "func_def", "arguments", "argu",
  "input_argu", "compound_stat", "end_stat", "end_semi", "statments",
  "stat", "else_scope", "print_word", "condition", "comparison",
  "equal_rhs", "value", "after_value", "postfix", "expression", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,    43,
      45,    42,    47,    37,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301
};
# endif

#define YYPACT_NINF -70

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-70)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     162,   -70,   -70,   -70,   -70,   -70,     4,   162,   -13,   -28,
     -23,   -70,   -70,   -70,    37,    -1,    -9,    18,    22,   -70,
     -70,    81,   -70,   -70,   -70,     2,   -70,    44,   -70,    61,
      37,   -70,   116,   -70,   -70,    17,    81,    60,   -70,   -27,
      81,    81,    33,   144,    81,    81,    81,    81,    81,    81,
      57,    49,   -70,    88,    32,   -70,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,   -70,   -70,    51,
      70,   175,   -70,    41,   -70,    31,   -70,   -70,   -70,   -70,
      47,    55,   175,    58,    81,   -70,   175,   175,   175,   175,
     175,   175,    75,    78,   130,   -70,   -70,   -70,   161,   -70,
     186,   186,   186,   186,   186,   186,    27,    27,   -70,   -70,
     -70,   -70,    77,    39,    95,    80,    82,    85,   -70,    98,
      81,   -70,   -70,   162,   -70,    37,    37,   -70,   -70,   -70,
     -70,   107,   -70,    21,   -70,    92,    37,    81,   -70,    94,
      97,    37,   107,   -70
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    76,    72,    73,    75,    74,     0,     3,     0,     0,
       0,     1,     2,     4,    24,    10,     0,     0,     0,    61,
      62,     0,    54,    55,    56,    59,     6,     0,     7,    20,
      24,    64,     0,    57,    63,     0,     0,     0,     8,     0,
      41,    41,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     0,
      10,     9,    12,     0,    14,     0,    38,    39,    37,    36,
       0,     0,    40,     0,     0,    58,    48,    49,    50,    51,
      52,    53,     0,     0,    17,    26,    21,    19,     0,    18,
      42,    47,    44,    46,    43,    45,    67,    68,    69,    70,
      71,    30,    11,    15,     0,     0,     0,     0,    32,    60,
       0,    22,     5,     0,    29,    24,    24,    60,    31,    16,
      13,    35,    27,     0,    28,     0,    24,    41,    33,     0,
       0,    24,    35,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   123,   -70,   -70,    14,   -70,   -70,    19,   -70,   -69,
     -64,   -70,   -70,   113,   -70,    29,   -70,   -40,   -70,   -70,
     -18,   -70,   -70,   -70,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    26,    27,    38,     9,    73,    74,    93,
      28,    54,    97,    29,    30,   134,    80,    81,    31,    51,
      32,    33,    69,    34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,    83,    36,    43,    11,    44,    13,    10,    14,    45,
      46,    47,    48,    49,     8,   117,    76,    77,    71,    78,
      79,     8,    82,    82,    15,    39,    86,    87,    88,    89,
      90,    91,    94,    37,   135,    98,    50,    75,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    16,
      17,   129,    40,    18,    19,    20,    41,   136,    64,    65,
      66,   131,   132,    52,    70,    53,    94,    84,    95,    99,
     111,    21,   138,    36,    19,    20,   112,   142,   113,   123,
      22,    23,   114,    24,    25,     1,     2,     3,     4,     5,
     115,    21,    92,   116,   118,    72,   122,   139,    19,    20,
      22,    23,    94,    24,    42,    19,    20,    96,     1,     2,
       3,     4,     5,   119,   124,    21,   125,   128,   126,    82,
     127,   133,    21,    75,    22,    23,   137,    24,    42,   140,
      12,    22,    23,   141,    24,    42,    56,    57,    58,    59,
      60,    61,   130,    55,     0,    62,    63,    64,    65,    66,
      56,    57,    58,    59,    60,    61,     0,    67,    68,    62,
      63,    64,    65,    66,    56,    57,    58,    59,    60,    61,
     120,   143,     0,    62,    63,    64,    65,    66,     0,    85,
     121,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      62,    63,    64,    65,    66,    56,    57,    58,    59,    60,
      61,     0,     0,     0,    62,    63,    64,    65,    66,     0,
       1,     2,     3,     4,     5,    62,    63,    64,    65,    66
};

static const yytype_int16 yycheck[] =
{
       0,    41,     3,    21,     0,     3,    19,     7,    36,     7,
       8,     9,    10,    11,     0,    84,    43,    44,    36,    46,
      47,     7,    40,    41,    47,    34,    44,    45,    46,    47,
      48,    49,    50,    34,    13,    53,    34,    37,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    12,
      13,   120,    34,    16,    17,    18,    34,    36,    31,    32,
      33,   125,   126,    19,    47,     4,    84,    34,    19,    37,
      19,    34,   136,     3,    17,    18,    35,   141,    47,    40,
      43,    44,    35,    46,    47,    48,    49,    50,    51,    52,
      35,    34,    35,    35,    19,    35,    19,   137,    17,    18,
      43,    44,   120,    46,    47,    17,    18,    19,    48,    49,
      50,    51,    52,    35,    19,    34,    36,    19,    36,   137,
      35,    14,    34,   123,    43,    44,    34,    46,    47,    35,
       7,    43,    44,    36,    46,    47,    20,    21,    22,    23,
      24,    25,   123,    30,    -1,    29,    30,    31,    32,    33,
      20,    21,    22,    23,    24,    25,    -1,    41,    42,    29,
      30,    31,    32,    33,    20,    21,    22,    23,    24,    25,
      40,   142,    -1,    29,    30,    31,    32,    33,    -1,    35,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      48,    49,    50,    51,    52,    29,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,    50,    51,    52,    54,    55,    57,    59,
      77,     0,    54,    19,    36,    47,    12,    13,    16,    17,
      18,    34,    43,    44,    46,    47,    56,    57,    63,    66,
      67,    71,    73,    74,    76,    77,     3,    34,    58,    34,
      34,    34,    47,    73,     3,     7,     8,     9,    10,    11,
      34,    72,    19,     4,    64,    66,    20,    21,    22,    23,
      24,    25,    29,    30,    31,    32,    33,    41,    42,    75,
      47,    73,    35,    60,    61,    77,    43,    44,    46,    47,
      69,    70,    73,    70,    34,    35,    73,    73,    73,    73,
      73,    73,    35,    62,    73,    19,    19,    65,    73,    37,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    19,    35,    47,    35,    35,    35,    62,    19,    35,
      40,    19,    19,    40,    19,    36,    36,    35,    19,    62,
      60,    63,    63,    14,    68,    13,    36,    34,    63,    70,
      35,    36,    63,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    55,    56,    57,    58,
      58,    59,    59,    60,    60,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     6,     3,     1,     3,     2,
       0,     5,     4,     4,     1,     2,     3,     1,     3,     2,
       0,     1,     2,     2,     0,     2,     3,     6,     7,     5,
       3,     5,     4,     3,     8,     0,     1,     1,     1,     1,
       1,     0,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     3,     1,
       4,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 106 "compiler_hw3.y" /* yacc.c:1646  */
    {
        //Predeclared function

    }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 110 "compiler_hw3.y" /* yacc.c:1646  */
    {
        //define funciton
    }
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 119 "compiler_hw3.y" /* yacc.c:1646  */
    {
        max_index++;
        if(scope){
            //local variable
            max_reg++;
            if(!strcmp((yyvsp[0].string),"0")){
                fprintf(file, "\tldc 0\n");
            }
            if(!strcmp((yyvsp[-2].string),"float")){
                fprintf(file, "\tfstore %d\n", max_reg);
                insert_symbol((yyvsp[-1].string),"float",max_reg,scope);
            }else{
                fprintf(file, "\tistore %d\n", max_reg);
                insert_symbol((yyvsp[-1].string),"int",max_reg,scope);
            }
        }else{
            //globol variable
            if(!strcmp((yyvsp[-2].string),"float")){
                fprintf(file,
                    ".field public static %s F=%s\n", (yyvsp[-1].string),(yyvsp[0].string));
                insert_symbol((yyvsp[-1].string),"float",-1,scope);
            }else{
                fprintf(file,
                    ".field public static %s I=%s\n", (yyvsp[-1].string),(yyvsp[0].string));
                insert_symbol((yyvsp[-1].string),"int",-1,scope);
            }
        }
    }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 150 "compiler_hw3.y" /* yacc.c:1646  */
    {
        element rhs = pop();
        if(scope){
            gencode_push(rhs);
        }
        char temp[10] = {0};
        sprintf(temp, "%s",(yyvsp[0].string));
        (yyval.string) = strdup(temp);
    }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 159 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.string) = "0";
    }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "compiler_hw3.y" /* yacc.c:1646  */
    {
        print_stable();
        int r[max_reg+1];
        for(int i=0;i<=max_reg;i++){
            r[i] = s_table[max_index-i].reg;
        }
        int j=0;
        for(int i=max_reg;i>=0;i--){
            s_table[max_index-j].reg=r[max_reg-j];
            j++;
        }
        print_stable();

        func_row new;
        max_f++;
        sprintf(new.name,"%s",(yyvsp[-3].string));
        sprintf(new.a_type,"%s",(yyvsp[-1].string));

        char temp[10]={0};
        sprintf(temp,"%s",(yyvsp[-4].string));
        (yyval.string)=strdup(temp);
        //start a function
        fprintf(file,
            ".method public static %s",(yyvsp[-3].string));
        if(!strcmp((yyvsp[-3].string),"main")){
            fprintf(file,
                "([Ljava/lang/String;)V\n");
        }else{
            fprintf(file,"(%s)",(yyvsp[-1].string));
            if(!strcmp((yyvsp[-4].string),"void")){
                fprintf(file, "V\n");
                sprintf(new.type,"V");
            }else if(!strcmp((yyvsp[-4].string),"int")){
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
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 209 "compiler_hw3.y" /* yacc.c:1646  */
    {
        func_row new;
        max_f++;
        char temp[10]={0};
        sprintf(temp,"%s",(yyvsp[-3].string));
        (yyval.string)=strdup(temp);
        fprintf(file,
            ".method public static %s",(yyvsp[-2].string));
        if(!strcmp((yyvsp[-2].string),"main")){
            fprintf(file,
                "([Ljava/lang/String;)V\n");
        }else{
            fprintf(file,"()");
            if(!strcmp((yyvsp[-3].string),"void")){
                fprintf(file, "V\n");
                sprintf(new.type,"V");
            }else if(!strcmp((yyvsp[-3].string),"int")){
                fprintf(file, "I\n");
                sprintf(new.type,"I");
            }else{
                fprintf(file, "F\n");
                sprintf(new.type,"F");
            }
        }
        fprintf(file, ".limit stack 50\n");
        fprintf(file, ".limit locals 50\n");

        sprintf(new.name,"%s",(yyvsp[-2].string));
        sprintf(new.a_type," ");
        f_table[max_f] = new;
    }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 243 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char temp[10]={0};
        sprintf(temp,"%c%s",gencode_atype((yyvsp[-3].string)),(yyvsp[0].string));
        (yyval.string)=strdup(temp);
        max_reg++;
        max_index++;
        insert_symbol((yyvsp[-2].string),(yyvsp[-3].string),max_reg,scope+1);
    }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 251 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char temp[10] = {0};
        sprintf(temp,"%s",(yyvsp[0].string));
        (yyval.string)=strdup(temp);
    }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 259 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char temp[10] = {0};
        sprintf(temp,"%c",gencode_atype((yyvsp[-1].string)));
        (yyval.string)=strdup(temp);
        max_reg=-1;
        max_reg++;
        max_index++;
        insert_symbol((yyvsp[0].string),(yyvsp[-1].string),max_reg,scope+1);
    }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 271 "compiler_hw3.y" /* yacc.c:1646  */
    {
        count_p++;
    }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 274 "compiler_hw3.y" /* yacc.c:1646  */
    {
        count_p = 1;
    }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 280 "compiler_hw3.y" /* yacc.c:1646  */
    {
    }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 285 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 288 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 294 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file, "\treturn\n");
        fprintf(file, ".end method\n");
    }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 298 "compiler_hw3.y" /* yacc.c:1646  */
    {
        element rv = pop();
        gencode_push(rv);
        if(!strcmp(rv.type,"int")){
            fprintf(file, "\tireturn\n");
        }else if(!strcmp(rv.type,"float")){
            fprintf(file, "\tfreturn\n");
        }
        fprintf(file, ".end method\n");
    }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 316 "compiler_hw3.y" /* yacc.c:1646  */
    {
        int i = lookup_symbol((yyvsp[-2].string));
        if(strcmp((yyvsp[-1].string),"no")){
            gencode_assign(i,(yyvsp[-1].string));
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
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 336 "compiler_hw3.y" /* yacc.c:1646  */
    {
        int i = lookup_func((yyvsp[-4].string));
        element p[count_p];
        printf("count_p:%d\n",count_p);
        for(int j=count_p-1;j>=0;j--){
            p[j] = pop();
        }
        for(int j=0;j<count_p;j++){
            gencode_push(p[j]);
        }

        fprintf(file,
            "\tinvokestatic compiler_hw3/%s(%s)V\n",
            (yyvsp[-4].string),f_table[i].a_type);
    }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 351 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file,
            "\tinvokestatic compiler_hw3/%s()V\n",(yyvsp[-3].string));
    }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 364 "compiler_hw3.y" /* yacc.c:1646  */
    {
        int i = lookup_symbol((yyvsp[0].string));
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
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 387 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file,"\tldc \"%s\"\n",(yyvsp[0].string));
        gencode_print("string");
    }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 391 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file,"\tldc %d\n",(yyvsp[0].i_val));
        gencode_print("int");
    }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 395 "compiler_hw3.y" /* yacc.c:1646  */
    {
        fprintf(file,"\tldc %f\n",(yyvsp[0].f_val));
        gencode_print("float");
    }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 407 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 419 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.string)="no";
    }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 422 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.string)="add";
    }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 425 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="sub";}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 426 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="mul";}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 427 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="div";}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 428 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="rem";}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 432 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char temp[10]={0};
        sprintf(temp,"%d",(yyvsp[0].i_val));
        (yyval.string)=strdup(temp);
        printf("push I_CONST:%s\n",temp);
        push(1,temp,"int");
    }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 439 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char temp[10]={0};
        sprintf(temp,"%f",(yyvsp[0].f_val));
        (yyval.string)=strdup(temp);
        push(1,temp,"float");
    }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 445 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=strdup((yyvsp[0].string));}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 446 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 449 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 452 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.string)=(yyvsp[0].string);
        char temp[10]={0};
        int i=lookup_symbol((yyvsp[0].string));
        sprintf(temp,"%d",i);
        push(-1,temp,s_table[i].type);
    }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 459 "compiler_hw3.y" /* yacc.c:1646  */
    {
        int i=lookup_func((yyvsp[-3].string));
        element p[count_p];
        printf("count_p:%d\n",count_p);
        for(int j=count_p-1;j>=0;j--){
            p[j] = pop();
        }
        for(int j=0;j<count_p;j++){
            gencode_push(p[j]);
        }
        fprintf(file,
            "\tinvokestatic compiler_hw3/%s(%s)%s\n",
            (yyvsp[-3].string),f_table[i].a_type,f_table[i].type);
        if(!strcmp(f_table[i].type,"I")){
            push(0,"un","int");
        }else{
            push(0,"un","float");
        }
    }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 478 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="1";}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 479 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="0";}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 483 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=strdup((yyvsp[0].string));}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 484 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="comparison";}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 493 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("add",0);
    }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 496 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("sub",0);
    }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 499 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("mul",0);
    }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 502 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("div",0);
    }
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 505 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("rem",0);
    }
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2034 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 519 "compiler_hw3.y" /* yacc.c:1906  */


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
