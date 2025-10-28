/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MOCHIPARSER_MOCHIPARSER_TAB_HPP_INCLUDED
# define YY_YY_MOCHIPARSER_MOCHIPARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    program_token = 258,           /* program_token  */
    main_token = 259,              /* main_token  */
    end_token = 260,               /* end_token  */
    print_token = 261,             /* print_token  */
    while_token = 262,             /* while_token  */
    do_token = 263,                /* do_token  */
    if_token = 264,                /* if_token  */
    else_token = 265,              /* else_token  */
    var_token = 266,               /* var_token  */
    void_token = 267,              /* void_token  */
    semicolon = 268,               /* semicolon  */
    comma = 269,                   /* comma  */
    colon = 270,                   /* colon  */
    string_token = 271,            /* string_token  */
    int_token = 272,               /* int_token  */
    float_token = 273,             /* float_token  */
    l_curly_brace = 274,           /* l_curly_brace  */
    r_curly_brace = 275,           /* r_curly_brace  */
    l_square_bracket = 276,        /* l_square_bracket  */
    r_square_bracket = 277,        /* r_square_bracket  */
    l_parenthesis = 278,           /* l_parenthesis  */
    r_parenthesis = 279,           /* r_parenthesis  */
    plus = 280,                    /* plus  */
    minus = 281,                   /* minus  */
    asterisk = 282,                /* asterisk  */
    slash = 283,                   /* slash  */
    equal_smaller_than = 284,      /* equal_smaller_than  */
    l_angle_bracket = 285,         /* l_angle_bracket  */
    equal_greater_than = 286,      /* equal_greater_than  */
    r_angle_bracket = 287,         /* r_angle_bracket  */
    equal = 288,                   /* equal  */
    assign = 289,                  /* assign  */
    not_equal = 290,               /* not_equal  */
    not_ = 291,                    /* not_  */
    id = 292,                      /* id  */
    int_constant = 293,            /* int_constant  */
    float_constant = 294,          /* float_constant  */
    string_constant = 295          /* string_constant  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "MochiParser/MochiParser.y"

    int i;
    float f;
    char* s;

#line 110 "MochiParser/MochiParser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MOCHIPARSER_MOCHIPARSER_TAB_HPP_INCLUDED  */
