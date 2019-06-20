/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 69 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    double f_val;
    char* string;

#line 152 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
