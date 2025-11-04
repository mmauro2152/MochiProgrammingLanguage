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
/* "%code requires" blocks.  */
#line 1 "MochiParser/MochiParser.y"

    #include <string>

#line 53 "MochiParser/MochiParser.tab.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    invalid_character = 258,       /* invalid_character  */
    program_token = 259,           /* program_token  */
    main_token = 260,              /* main_token  */
    end_token = 261,               /* end_token  */
    print_token = 262,             /* print_token  */
    while_token = 263,             /* while_token  */
    do_token = 264,                /* do_token  */
    if_token = 265,                /* if_token  */
    else_token = 266,              /* else_token  */
    var_token = 267,               /* var_token  */
    void_token = 268,              /* void_token  */
    semicolon = 269,               /* semicolon  */
    comma = 270,                   /* comma  */
    colon = 271,                   /* colon  */
    string_token = 272,            /* string_token  */
    int_token = 273,               /* int_token  */
    float_token = 274,             /* float_token  */
    l_curly_brace = 275,           /* l_curly_brace  */
    r_curly_brace = 276,           /* r_curly_brace  */
    l_square_bracket = 277,        /* l_square_bracket  */
    r_square_bracket = 278,        /* r_square_bracket  */
    l_parenthesis = 279,           /* l_parenthesis  */
    r_parenthesis = 280,           /* r_parenthesis  */
    plus = 281,                    /* plus  */
    minus = 282,                   /* minus  */
    asterisk = 283,                /* asterisk  */
    slash = 284,                   /* slash  */
    equal_smaller_than = 285,      /* equal_smaller_than  */
    l_angle_bracket = 286,         /* l_angle_bracket  */
    equal_greater_than = 287,      /* equal_greater_than  */
    r_angle_bracket = 288,         /* r_angle_bracket  */
    equal = 289,                   /* equal  */
    assign = 290,                  /* assign  */
    not_equal = 291,               /* not_equal  */
    not_ = 292,                    /* not_  */
    id = 293,                      /* id  */
    int_constant = 294,            /* int_constant  */
    float_constant = 295,          /* float_constant  */
    string_constant = 296          /* string_constant  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "MochiParser/MochiParser.y"

    int i;
    float f;
    char* s;

#line 117 "MochiParser/MochiParser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MOCHIPARSER_MOCHIPARSER_TAB_HPP_INCLUDED  */
