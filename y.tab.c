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


#line 115 "y.tab.c" /* yacc.c:339  */

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
#line 51 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    double f_val;
    char* string;

#line 253 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 270 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

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
       0,    82,    82,    83,    87,    88,    92,    98,   101,   131,
     136,   141,   145,   155,   158,   161,   166,   167,   168,   172,
     176,   177,   181,   182,   185,   186,   190,   191,   194,   195,
     196,   197,   198,   203,   204,   205,   209,   210,   214,   215,
     219,   220,   221,   222,   223,   224,   229,   232,   233,   234,
     235,   236,   240,   246,   252,   259,   260,   263,   266,   273,
     276,   277,   285,   286,   290,   291,   295,   298,   301,   304,
     307,   314,   315,   316,   317,   318
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
  "declaration", "declaration_type", "func_def", "arguments", "input_argu",
  "compound_stat", "end_stat", "end_semi", "statments", "stat",
  "else_scope", "print_word", "condition", "comparison", "equal_rhs",
  "value", "after_value", "postfix", "expression", "type", YY_NULLPTR
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

#define YYPACT_NINF -96

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-96)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,   -96,   -96,   -96,   -96,   -96,    20,    66,   -16,    -6,
      -7,   -96,   -96,   -96,   111,    -1,    -3,     7,     8,   -96,
     -96,   193,   193,   193,   193,   193,   193,   193,   193,   -96,
     -96,   -96,    18,   -96,    24,   -96,    51,   111,   -96,    78,
     -96,   -96,     6,   -38,    98,   -96,   -28,   193,   193,   -96,
     199,   199,   199,   199,   199,   199,     5,   153,   193,   193,
     193,   193,   193,   193,    49,    37,   -96,   178,    25,   -96,
     193,   193,   193,   193,   193,   -96,   -96,    44,    65,   -96,
     -96,    66,    41,    30,   -96,   -96,    43,    47,   199,    50,
     -96,   199,   199,   199,   199,   199,   199,   193,    53,   147,
     -96,   -96,   -96,    68,   -96,     5,     5,   -96,   -96,   -96,
     -96,    55,    71,    98,    75,    67,    69,   147,    93,   193,
     -96,   -96,    98,   -96,   -96,   -96,   111,   111,   -96,   -96,
       5,   -96,   107,   -96,     3,   -96,    92,   111,   193,   -96,
      95,   101,   111,   107,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    75,    71,    72,    74,    73,     0,     3,     0,     0,
       0,     1,     2,     4,    25,    11,     0,     0,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      53,    55,    58,     6,     0,     7,    21,    25,    63,     0,
      56,    62,     0,     0,    15,     8,     0,    39,    39,    58,
      40,    45,    42,    44,    41,    43,    54,     0,     0,     0,
       0,     0,     0,     0,    18,     0,    26,     0,     0,    24,
       0,     0,     0,     0,     0,    64,    65,     0,    11,     9,
      10,     0,     0,     0,    37,    36,     0,     0,    38,     0,
      57,    46,    47,    48,    49,    50,    51,     0,     0,    18,
      27,    22,    20,     0,    19,    66,    67,    68,    69,    70,
      31,     0,    12,    15,     0,     0,     0,    18,    59,     0,
      16,    23,    15,     5,    13,    30,    25,    25,    17,    32,
      54,    14,    35,    28,     0,    29,     0,    25,    39,    33,
       0,     0,    25,    35,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   132,   -96,   -96,    17,   -96,   -96,   -90,   -95,   -62,
     -96,   -96,   103,   -96,     1,   -96,   -47,   -96,   -96,   -13,
     -96,   -96,   -96,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,    33,    34,    45,     9,    82,    98,    35,
      68,   102,    36,    37,   135,    86,    87,    38,    65,    39,
      40,    77,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      10,    89,    43,    13,   120,    79,    80,    10,    50,    51,
      52,    53,    54,    55,    56,    57,   136,     8,    84,    85,
      11,    58,   128,   124,     8,    59,    60,    61,    62,    63,
      14,    46,   131,    44,    88,    88,    72,    73,    74,   137,
      15,    47,    48,    66,    83,    91,    92,    93,    94,    95,
      96,    99,    64,    78,   103,    67,   100,   105,   106,   107,
     108,   109,   104,   110,   132,   133,    19,    20,    43,    21,
      22,    23,    24,    25,    26,   139,   112,   113,   114,    27,
     143,   111,   115,    28,   117,   116,    99,   121,   118,    97,
     123,   140,    29,    30,   125,    31,    49,    70,    71,    72,
      73,    74,   122,   126,    99,   127,   130,    70,    71,    72,
      73,    74,   129,    83,     1,     2,     3,     4,     5,    75,
      76,   134,    83,    16,    17,    88,   138,    18,    19,    20,
     141,    21,    22,    23,    24,    25,    26,   142,    81,    12,
      69,    27,     0,     0,   144,    28,     1,     2,     3,     4,
       5,     0,     0,     0,    29,    30,     0,    31,    32,     1,
       2,     3,     4,     5,    19,    20,     0,    21,    22,    23,
      24,    25,    26,     0,     0,     0,    70,   119,    72,    73,
      74,    28,    70,    71,    72,    73,    74,    97,    90,     0,
      29,    30,     0,    31,    49,    19,    20,   101,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,    27,     0,
      19,    20,    28,    21,    22,    23,    24,    25,    26,     0,
       0,    29,    30,    27,    31,    49,     0,    28,    70,    71,
      72,    73,    74,     0,     0,     0,    29,    30,     0,    31,
      49
};

static const yytype_int16 yycheck[] =
{
       0,    48,     3,    19,    99,    43,    44,     7,    21,    22,
      23,    24,    25,    26,    27,    28,    13,     0,    46,    47,
       0,     3,   117,   113,     7,     7,     8,     9,    10,    11,
      36,    34,   122,    34,    47,    48,    31,    32,    33,    36,
      47,    34,    34,    19,    44,    58,    59,    60,    61,    62,
      63,    64,    34,    47,    67,     4,    19,    70,    71,    72,
      73,    74,    37,    19,   126,   127,    17,    18,     3,    20,
      21,    22,    23,    24,    25,   137,    35,    47,    35,    30,
     142,    81,    35,    34,    97,    35,    99,    19,    35,    40,
      19,   138,    43,    44,    19,    46,    47,    29,    30,    31,
      32,    33,    47,    36,   117,    36,   119,    29,    30,    31,
      32,    33,    19,   113,    48,    49,    50,    51,    52,    41,
      42,    14,   122,    12,    13,   138,    34,    16,    17,    18,
      35,    20,    21,    22,    23,    24,    25,    36,    40,     7,
      37,    30,    -1,    -1,   143,    34,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    43,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      33,    34,    29,    30,    31,    32,    33,    40,    35,    -1,
      43,    44,    -1,    46,    47,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      17,    18,    34,    20,    21,    22,    23,    24,    25,    -1,
      -1,    43,    44,    30,    46,    47,    -1,    34,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    43,    44,    -1,    46,
      47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,    50,    51,    52,    54,    55,    57,    59,
      76,     0,    54,    19,    36,    47,    12,    13,    16,    17,
      18,    20,    21,    22,    23,    24,    25,    30,    34,    43,
      44,    46,    47,    56,    57,    62,    65,    66,    70,    72,
      73,    75,    76,     3,    34,    58,    34,    34,    34,    47,
      72,    72,    72,    72,    72,    72,    72,    72,     3,     7,
       8,     9,    10,    11,    34,    71,    19,     4,    63,    65,
      29,    30,    31,    32,    33,    41,    42,    74,    47,    43,
      44,    40,    60,    76,    46,    47,    68,    69,    72,    69,
      35,    72,    72,    72,    72,    72,    72,    40,    61,    72,
      19,    19,    64,    72,    37,    72,    72,    72,    72,    72,
      19,    76,    35,    47,    35,    35,    35,    72,    35,    30,
      61,    19,    47,    19,    60,    19,    36,    36,    61,    19,
      72,    60,    62,    62,    14,    67,    13,    36,    34,    62,
      69,    35,    36,    62,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    55,    56,    57,    58,
      58,    58,    59,    60,    60,    60,    61,    61,    61,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    76,    76,    76,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     6,     3,     1,     3,     2,
       2,     0,     5,     3,     4,     0,     2,     3,     0,     3,
       2,     0,     1,     2,     2,     0,     2,     3,     6,     7,
       5,     3,     5,     3,     8,     0,     1,     1,     1,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1
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
#line 88 "compiler_hw3.y" /* yacc.c:1646  */
    {
        //Predeclared function

    }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "compiler_hw3.y" /* yacc.c:1646  */
    {
        //define funciton
    }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "compiler_hw3.y" /* yacc.c:1646  */
    {
        max_index++;

        if(scope){
            //local variable
            max_reg++;
            fprintf(file, "\tldc %s\n",(yyvsp[0].string));
            if(!strcmp((yyvsp[-2].string),"float")){
                fprintf(file, "\tfstore %d\n", max_reg);
                insert_symbol((yyvsp[-1].string),"float",max_reg);
            }else{
                fprintf(file, "\tistore %d\n", max_reg);
                insert_symbol((yyvsp[-1].string),"int",max_reg);
            }
        }else{
            //globol variable
            if(!strcmp((yyvsp[-2].string),"float")){
                fprintf(file,
                    ".field public static %s F=%s\n", (yyvsp[-1].string),(yyvsp[0].string));
                insert_symbol((yyvsp[-1].string),"float",-1);
            }else{
                fprintf(file,
                    ".field public static %s I=%s\n", (yyvsp[-1].string),(yyvsp[0].string));
                insert_symbol((yyvsp[-1].string),"int",-1);
            }
        }
    }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 131 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char temp[10] = {0};
        sprintf(temp, "%d",(yyvsp[0].i_val));
        (yyval.string) = strdup(temp);
    }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 136 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char temp[10] = {0};
        sprintf(temp, "%f",(yyvsp[0].f_val));
        (yyval.string) = strdup(temp);
    }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 141 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string) = "0";}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 145 "compiler_hw3.y" /* yacc.c:1646  */
    {
        //start a function
        fprintf(file,
            ".method public static %s([Ljava/lang/String;)V\n",(yyvsp[-3].string));
        //fprintf(file, "");
        fprintf(file, "\t.limit stack 50\n");
    }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 155 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 158 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 161 "compiler_hw3.y" /* yacc.c:1646  */
    {
    }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 172 "compiler_hw3.y" /* yacc.c:1646  */
    { }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 198 "compiler_hw3.y" /* yacc.c:1646  */
    {
    }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 229 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.string)=(yyvsp[0].string);
    }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 232 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 233 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 234 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 235 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 236 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[0].string);}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 240 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char temp[10]={0};
        sprintf(temp,"%d",(yyvsp[0].i_val));
        (yyval.string)=strdup(temp);
        push(1,temp,"int");
    }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 246 "compiler_hw3.y" /* yacc.c:1646  */
    {
        char temp[10]={0};
        sprintf(temp,"%f",(yyvsp[0].f_val));
        (yyval.string)=strdup(temp);
        push(1,temp,"float");
    }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 252 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.string)=strdup((yyvsp[0].string));
        element item = pop();
        sprintf(item.value,"-%s",item.value);
        // struction??
        push(item.know,item.value,item.type);
    }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 259 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=strdup((yyvsp[0].string));}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 260 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 263 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 266 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.string)=(yyvsp[0].string);
        char temp[10]={0};
        int i=lookup_symbol((yyvsp[0].string));
        sprintf(temp,"%d",i);
        push(-1,temp,s_table[i].type);
    }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 273 "compiler_hw3.y" /* yacc.c:1646  */
    {

    }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 276 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="1";}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 277 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="0";}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 285 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)=strdup((yyvsp[0].string));}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 286 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.string)="comparison";}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 295 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("add");
    }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 298 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("sub");
    }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 301 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("mul");
    }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 304 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("div");
    }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 307 "compiler_hw3.y" /* yacc.c:1646  */
    {
        gencode_exp("rem");
    }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1776 "y.tab.c" /* yacc.c:1646  */
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
#line 321 "compiler_hw3.y" /* yacc.c:1906  */


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
    printf("after dump:scope:%d\n",scope);
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
    printf("push:index:%d(%s,%s)\n",top,stack[top].value,stack[top].type);
}

char* casting(element v1, element v2){
    if(!strcmp(v1.type,v2.type)){
        return strdup(v1.type);
    }else{
        return "float";
    }
}
