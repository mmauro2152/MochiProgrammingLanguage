/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "src/MochiParser/MochiParser.y"

#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include "../FuncDir.hpp"
#include "../QuadManager.hpp"
#include "../SemanticCube.hpp"

void yyerror(const char* errorMsg) {
    std::cout << errorMsg << std::endl;
};
extern int yylex(void);


FuncDir funcDir;
std::string globalScope;
std::string currScope;
std::queue<char*> idQueue;
vartype currType;
int semanticErrors = 0;

QuadManager quadManager;


#line 97 "src/MochiParser/MochiParser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "MochiParser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_invalid_character = 3,          /* invalid_character  */
  YYSYMBOL_program_token = 4,              /* program_token  */
  YYSYMBOL_main_token = 5,                 /* main_token  */
  YYSYMBOL_end_token = 6,                  /* end_token  */
  YYSYMBOL_print_token = 7,                /* print_token  */
  YYSYMBOL_while_token = 8,                /* while_token  */
  YYSYMBOL_do_token = 9,                   /* do_token  */
  YYSYMBOL_if_token = 10,                  /* if_token  */
  YYSYMBOL_else_token = 11,                /* else_token  */
  YYSYMBOL_var_token = 12,                 /* var_token  */
  YYSYMBOL_void_token = 13,                /* void_token  */
  YYSYMBOL_semicolon = 14,                 /* semicolon  */
  YYSYMBOL_comma = 15,                     /* comma  */
  YYSYMBOL_colon = 16,                     /* colon  */
  YYSYMBOL_string_token = 17,              /* string_token  */
  YYSYMBOL_int_token = 18,                 /* int_token  */
  YYSYMBOL_float_token = 19,               /* float_token  */
  YYSYMBOL_l_curly_brace = 20,             /* l_curly_brace  */
  YYSYMBOL_r_curly_brace = 21,             /* r_curly_brace  */
  YYSYMBOL_l_square_bracket = 22,          /* l_square_bracket  */
  YYSYMBOL_r_square_bracket = 23,          /* r_square_bracket  */
  YYSYMBOL_l_parenthesis = 24,             /* l_parenthesis  */
  YYSYMBOL_r_parenthesis = 25,             /* r_parenthesis  */
  YYSYMBOL_plus = 26,                      /* plus  */
  YYSYMBOL_minus = 27,                     /* minus  */
  YYSYMBOL_asterisk = 28,                  /* asterisk  */
  YYSYMBOL_slash = 29,                     /* slash  */
  YYSYMBOL_equal_smaller_than = 30,        /* equal_smaller_than  */
  YYSYMBOL_l_angle_bracket = 31,           /* l_angle_bracket  */
  YYSYMBOL_equal_greater_than = 32,        /* equal_greater_than  */
  YYSYMBOL_r_angle_bracket = 33,           /* r_angle_bracket  */
  YYSYMBOL_equal = 34,                     /* equal  */
  YYSYMBOL_assign = 35,                    /* assign  */
  YYSYMBOL_not_equal = 36,                 /* not_equal  */
  YYSYMBOL_not_ = 37,                      /* not_  */
  YYSYMBOL_id = 38,                        /* id  */
  YYSYMBOL_int_constant = 39,              /* int_constant  */
  YYSYMBOL_float_constant = 40,            /* float_constant  */
  YYSYMBOL_string_constant = 41,           /* string_constant  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program_declaration = 43,       /* program_declaration  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_opt_funcs = 46,                 /* opt_funcs  */
  YYSYMBOL_opt_funcs_ = 47,                /* opt_funcs_  */
  YYSYMBOL_opt_vars = 48,                  /* opt_vars  */
  YYSYMBOL_vars = 49,                      /* vars  */
  YYSYMBOL_var_loop = 50,                  /* var_loop  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_var_loop_ = 52,                 /* var_loop_  */
  YYSYMBOL_id_loop = 53,                   /* id_loop  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_id_loop_ = 55,                  /* id_loop_  */
  YYSYMBOL_type = 56,                      /* type  */
  YYSYMBOL_func_type = 57,                 /* func_type  */
  YYSYMBOL_funcs = 58,                     /* funcs  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_params = 60,                    /* params  */
  YYSYMBOL_param_loop = 61,                /* param_loop  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_param_loop_ = 63,               /* param_loop_  */
  YYSYMBOL_body = 64,                      /* body  */
  YYSYMBOL_statement_loop = 65,            /* statement_loop  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_assign_statement = 67,          /* assign_statement  */
  YYSYMBOL_68_7 = 68,                      /* $@7  */
  YYSYMBOL_69_8 = 69,                      /* $@8  */
  YYSYMBOL_assign_statement_ = 70,         /* assign_statement_  */
  YYSYMBOL_71_9 = 71,                      /* $@9  */
  YYSYMBOL_72_10 = 72,                     /* $@10  */
  YYSYMBOL_condition_statement = 73,       /* condition_statement  */
  YYSYMBOL_opt_else = 74,                  /* opt_else  */
  YYSYMBOL_cycle_statement = 75,           /* cycle_statement  */
  YYSYMBOL_print_statement = 76,           /* print_statement  */
  YYSYMBOL_print_loop = 77,                /* print_loop  */
  YYSYMBOL_print_loop_ = 78,               /* print_loop_  */
  YYSYMBOL_print_element = 79,             /* print_element  */
  YYSYMBOL_func_call_statement = 80,       /* func_call_statement  */
  YYSYMBOL_opt_expression_loop = 81,       /* opt_expression_loop  */
  YYSYMBOL_expression_loop = 82,           /* expression_loop  */
  YYSYMBOL_expression_loop_ = 83,          /* expression_loop_  */
  YYSYMBOL_expression = 84,                /* expression  */
  YYSYMBOL_exp_ = 85,                      /* exp_  */
  YYSYMBOL_conditional_operator = 86,      /* conditional_operator  */
  YYSYMBOL_exp = 87,                       /* exp  */
  YYSYMBOL_88_11 = 88,                     /* $@11  */
  YYSYMBOL_term_ = 89,                     /* term_  */
  YYSYMBOL_term_operator = 90,             /* term_operator  */
  YYSYMBOL_term = 91,                      /* term  */
  YYSYMBOL_92_12 = 92,                     /* $@12  */
  YYSYMBOL_factor_ = 93,                   /* factor_  */
  YYSYMBOL_factor_operator = 94,           /* factor_operator  */
  YYSYMBOL_factor = 95,                    /* factor  */
  YYSYMBOL_96_13 = 96,                     /* $@13  */
  YYSYMBOL_97_14 = 97,                     /* $@14  */
  YYSYMBOL_opt_operator = 98,              /* opt_operator  */
  YYSYMBOL_factor_element = 99,            /* factor_element  */
  YYSYMBOL_num_constant = 100              /* num_constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    60,    52,    70,    72,    76,    79,    81,
      85,    89,    89,   100,   102,   106,   106,   110,   112,   116,
     117,   118,   122,   123,   127,   127,   136,   138,   142,   142,
     148,   150,   154,   157,   159,   163,   164,   165,   166,   167,
     171,   180,   171,   202,   203,   212,   203,   235,   238,   240,
     244,   248,   252,   255,   257,   261,   262,   266,   269,   271,
     275,   276,   279,   281,   285,   288,   290,   294,   295,   296,
     297,   298,   299,   303,   303,   329,   331,   335,   336,   340,
     340,   366,   368,   372,   373,   377,   377,   390,   390,   421,
     423,   445,   446,   450,   459,   463,   467
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "invalid_character",
  "program_token", "main_token", "end_token", "print_token", "while_token",
  "do_token", "if_token", "else_token", "var_token", "void_token",
  "semicolon", "comma", "colon", "string_token", "int_token",
  "float_token", "l_curly_brace", "r_curly_brace", "l_square_bracket",
  "r_square_bracket", "l_parenthesis", "r_parenthesis", "plus", "minus",
  "asterisk", "slash", "equal_smaller_than", "l_angle_bracket",
  "equal_greater_than", "r_angle_bracket", "equal", "assign", "not_equal",
  "not_", "id", "int_constant", "float_constant", "string_constant",
  "$accept", "program_declaration", "$@1", "$@2", "opt_funcs",
  "opt_funcs_", "opt_vars", "vars", "var_loop", "$@3", "var_loop_",
  "id_loop", "$@4", "id_loop_", "type", "func_type", "funcs", "$@5",
  "params", "param_loop", "$@6", "param_loop_", "body", "statement_loop",
  "statement", "assign_statement", "$@7", "$@8", "assign_statement_",
  "$@9", "$@10", "condition_statement", "opt_else", "cycle_statement",
  "print_statement", "print_loop", "print_loop_", "print_element",
  "func_call_statement", "opt_expression_loop", "expression_loop",
  "expression_loop_", "expression", "exp_", "conditional_operator", "exp",
  "$@11", "term_", "term_operator", "term", "$@12", "factor_",
  "factor_operator", "factor", "$@13", "$@14", "opt_operator",
  "factor_element", "num_constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,   -14,    27,  -103,  -103,    12,    29,     9,     3,  -103,
    -103,  -103,    38,  -103,  -103,  -103,  -103,    58,  -103,    30,
       3,    52,    -5,  -103,  -103,  -103,  -103,     9,  -103,    55,
      56,    54,  -103,  -103,    -2,    73,    42,     9,    57,    59,
      60,    61,    65,    -2,  -103,  -103,  -103,  -103,  -103,  -103,
      66,    62,  -103,  -103,  -103,    -9,    22,    22,    18,    53,
    -103,  -103,    -5,    67,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,    68,    75,  -103,    41,  -103,  -103,    -1,  -103,  -103,
      69,    70,    76,    71,  -103,    76,  -103,  -103,    29,    22,
      78,    -9,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
      22,   -17,     6,  -103,  -103,    88,    56,    18,  -103,    85,
    -103,    26,    86,    56,    77,  -103,  -103,  -103,  -103,  -103,
    -103,    22,  -103,  -103,  -103,    22,    22,    56,    89,  -103,
    -103,    72,    90,  -103,    42,  -103,    80,  -103,  -103,  -103,
      81,    91,    56,    94,    74,  -103,  -103,    96,  -103,  -103,
    -103,  -103,  -103,  -103,    26,  -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     8,     0,     5,     9,
      15,    10,     0,    22,    21,    19,    20,     0,    23,     0,
       5,    17,     0,     3,    24,     7,     6,     0,    16,     0,
       0,     0,    18,    11,    33,     0,    26,    13,     0,     0,
       0,    40,     0,    33,    35,    36,    37,    38,    39,     4,
       0,     0,    27,    14,    12,     0,     0,     0,    58,     0,
      32,    34,     0,     0,    85,    91,    92,    93,    95,    96,
      56,     0,    53,    55,    65,    73,    79,     0,    89,    94,
       0,     0,    62,     0,    59,    62,    41,    28,     8,     0,
       0,     0,    52,    69,    70,    67,    68,    72,    71,    64,
       0,    75,    81,    87,    90,     0,     0,     0,    61,     0,
      60,     0,    30,     0,     0,    51,    54,    66,    77,    78,
      74,     0,    83,    84,    80,     0,     0,     0,    48,    63,
      57,    93,     0,    43,     0,    29,     0,    86,    76,    82,
       0,     0,     0,     0,     0,    42,    31,     0,    88,    50,
      49,    47,    45,    25,     0,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,  -103,  -103,    92,  -103,    23,  -103,    79,  -103,
    -103,    87,  -103,  -103,   -19,  -103,  -103,  -103,  -103,   -21,
    -103,  -103,  -102,    82,  -103,  -103,  -103,  -103,   -39,  -103,
    -103,  -103,  -103,  -103,  -103,    28,  -103,  -103,  -103,  -103,
      10,    33,   -56,  -103,  -103,   -93,  -103,  -103,  -103,    -4,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,    43,  -103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,    30,    17,    26,     8,     9,    11,    37,
      54,    12,    21,    28,    18,    19,    20,    31,    51,    52,
     112,   135,    35,    42,    43,    44,    59,   111,   132,   144,
     154,    45,   143,    46,    47,    71,    92,    72,    48,    83,
      84,   108,    73,    99,   100,    74,   101,   120,   121,    75,
     102,   124,   125,    76,    89,   126,    77,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,    81,    85,    29,   128,    38,    39,   117,    40,   118,
     119,   136,    14,    15,    16,    64,    13,    65,    66,     1,
      14,    15,    16,   103,     3,   141,     6,     4,   138,    67,
      68,    69,    70,   114,   122,   123,    41,    67,    68,    69,
     150,     7,    64,    87,    65,    66,    64,    10,    65,    66,
      64,    85,    65,    66,    22,   133,    67,    68,    69,    82,
      67,    68,    69,    23,   131,    68,    69,    27,    24,    33,
     140,    93,    94,    95,    96,    97,    34,    98,    36,    49,
      50,    55,    62,    56,    57,    58,    60,    63,    86,    88,
      91,   107,   115,    90,   105,   106,   109,   127,   133,   130,
     142,   134,   137,   147,   145,   149,   148,   -44,   151,   152,
     153,   113,    25,   146,    32,   155,    53,   129,   110,   116,
     104,   139,     0,     0,     0,    61
};

static const yytype_int16 yycheck[] =
{
      56,    57,    58,    22,   106,     7,     8,   100,    10,    26,
      27,   113,    17,    18,    19,    24,    13,    26,    27,     4,
      17,    18,    19,    24,    38,   127,    14,     0,   121,    38,
      39,    40,    41,    89,    28,    29,    38,    38,    39,    40,
     142,    12,    24,    62,    26,    27,    24,    38,    26,    27,
      24,   107,    26,    27,    16,   111,    38,    39,    40,    41,
      38,    39,    40,     5,    38,    39,    40,    15,    38,    14,
     126,    30,    31,    32,    33,    34,    20,    36,    24,     6,
      38,    24,    16,    24,    24,    24,    21,    25,    35,    22,
      15,    15,    14,    25,    25,    25,    25,     9,   154,    14,
      11,    15,    25,    23,    14,    14,    25,    35,    14,    35,
      14,    88,    20,   134,    27,   154,    37,   107,    85,    91,
      77,   125,    -1,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    43,    38,     0,    44,    14,    12,    48,    49,
      38,    50,    53,    13,    17,    18,    19,    46,    56,    57,
      58,    54,    16,     5,    38,    46,    47,    15,    55,    56,
      45,    59,    53,    14,    20,    64,    24,    51,     7,     8,
      10,    38,    65,    66,    67,    73,    75,    76,    80,     6,
      38,    60,    61,    50,    52,    24,    24,    24,    24,    68,
      21,    65,    16,    25,    24,    26,    27,    38,    39,    40,
      41,    77,    79,    84,    87,    91,    95,    98,    99,   100,
      84,    84,    41,    81,    82,    84,    35,    56,    22,    96,
      25,    15,    78,    30,    31,    32,    33,    34,    36,    85,
      86,    88,    92,    24,    99,    25,    25,    15,    83,    25,
      83,    69,    62,    48,    84,    14,    77,    87,    26,    27,
      89,    90,    28,    29,    93,    94,    97,     9,    64,    82,
      14,    38,    70,    84,    15,    63,    64,    25,    87,    91,
      84,    64,    11,    74,    71,    14,    61,    23,    25,    14,
      64,    14,    35,    14,    72,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    44,    45,    43,    46,    46,    47,    48,    48,
      49,    51,    50,    52,    52,    54,    53,    55,    55,    56,
      56,    56,    57,    57,    59,    58,    60,    60,    62,    61,
      63,    63,    64,    65,    65,    66,    66,    66,    66,    66,
      68,    69,    67,    70,    71,    72,    70,    73,    74,    74,
      75,    76,    77,    78,    78,    79,    79,    80,    81,    81,
      82,    82,    83,    83,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    88,    87,    89,    89,    90,    90,    92,
      91,    93,    93,    94,    94,    96,    95,    97,    95,    95,
      95,    98,    98,    99,    99,   100,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,    10,     0,     2,     1,     0,     1,
       2,     0,     6,     0,     1,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     0,    11,     0,     1,     0,     5,
       0,     2,     3,     0,     2,     1,     1,     1,     1,     1,
       0,     0,     6,     1,     0,     0,     5,     7,     0,     2,
       7,     5,     2,     0,     2,     1,     1,     5,     0,     1,
       2,     2,     0,     2,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     2,     1,     1,     0,
       3,     0,     2,     1,     1,     0,     4,     0,     5,     1,
       2,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 52 "src/MochiParser/MochiParser.y"
                     { 
        globalScope = (yyvsp[0].s);
        currScope = globalScope;
        funcDir.setGlobalScope(globalScope);
        if (!funcDir.insertFunction(currScope, vartype::void_type)) {
            semanticErrors++;
        }
    }
#line 1306 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 3: /* $@2: %empty  */
#line 60 "src/MochiParser/MochiParser.y"
                                            { currScope = globalScope; }
#line 1312 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 4: /* program_declaration: program_token id $@1 semicolon opt_vars opt_funcs main_token $@2 body end_token  */
#line 60 "src/MochiParser/MochiParser.y"
                                                                                        {
        quadManager.debug();
        //funcDir.printAll();
        if (semanticErrors > 0) {
            std::cerr << "Found " << semanticErrors << " semantic errors" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
#line 1325 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 11: /* $@3: %empty  */
#line 89 "src/MochiParser/MochiParser.y"
                                 {
        while (!idQueue.empty()) {
            if (!funcDir.getFunction(currScope)->localVars.insert(idQueue.front(), currType)) {
                semanticErrors++;
            }
                 
            idQueue.pop();
        }
    }
#line 1339 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 15: /* $@4: %empty  */
#line 106 "src/MochiParser/MochiParser.y"
       { idQueue.push((yyvsp[0].s)); }
#line 1345 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 19: /* type: int_token  */
#line 116 "src/MochiParser/MochiParser.y"
              { currType = vartype::int_type; }
#line 1351 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 20: /* type: float_token  */
#line 117 "src/MochiParser/MochiParser.y"
                  { currType = vartype::float_type; }
#line 1357 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 21: /* type: string_token  */
#line 118 "src/MochiParser/MochiParser.y"
                   { currType = vartype::string_type; }
#line 1363 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 22: /* func_type: void_token  */
#line 122 "src/MochiParser/MochiParser.y"
               { currType = vartype::void_type; }
#line 1369 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 24: /* $@5: %empty  */
#line 127 "src/MochiParser/MochiParser.y"
                 { 
        currScope = (yyvsp[0].s);
        if (!funcDir.insertFunction(currScope, currType)){
            semanticErrors++;
        }
    }
#line 1380 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 28: /* $@6: %empty  */
#line 142 "src/MochiParser/MochiParser.y"
                  { 
        funcDir.addParameter(currScope, (yyvsp[-2].s), currType);
    }
#line 1388 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 40: /* $@7: %empty  */
#line 171 "src/MochiParser/MochiParser.y"
       {
        VarEntry* var = funcDir.getVar(currScope, (yyvsp[0].s));
        if (var == nullptr) {
            semanticErrors++;
        } else {
            operand op = operand(var->type, currScope, (yyvsp[0].s));
            quadManager.operands.push(op);
        }
    }
#line 1402 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 41: /* $@8: %empty  */
#line 180 "src/MochiParser/MochiParser.y"
           { quadManager.operators.push(operatortype::assign); }
#line 1408 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 42: /* assign_statement: id $@7 assign $@8 assign_statement_ semicolon  */
#line 181 "src/MochiParser/MochiParser.y"
                                {
        operand rOperand = quadManager.operands.top();
        quadManager.operands.pop();
        operand lOperand = quadManager.operands.top();
        quadManager.operands.pop();
        operatortype op = quadManager.operators.top();
        quadManager.operators.pop();

        CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
        vartype restype = SemanticCube::resultingType(entry);

        if (restype == vartype::unknown) {
            semanticErrors++;
        }else {
            quad q = quad(op, operand(vartype::none, currScope, "none"), rOperand, lOperand);
            quadManager.push(q);
        }
    }
#line 1431 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 44: /* $@9: %empty  */
#line 203 "src/MochiParser/MochiParser.y"
         {
        VarEntry* var = funcDir.getVar(currScope, (yyvsp[0].s));
        if (var == nullptr) {
            semanticErrors++;
        } else {
            operand op = operand(var->type, currScope, (yyvsp[0].s));
            quadManager.operands.push(op);
        }
    }
#line 1445 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 45: /* $@10: %empty  */
#line 212 "src/MochiParser/MochiParser.y"
           { quadManager.operators.push(operatortype::assign); }
#line 1451 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 46: /* assign_statement_: id $@9 assign $@10 assign_statement_  */
#line 213 "src/MochiParser/MochiParser.y"
                      {
        operand rOperand = quadManager.operands.top();
        quadManager.operands.pop();
        operand lOperand = quadManager.operands.top();
        quadManager.operands.pop();
        operatortype op = quadManager.operators.top();
        quadManager.operators.pop();

        CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
        vartype restype = SemanticCube::resultingType(entry);

        if (restype == vartype::unknown) {
            semanticErrors++;
        }else {
            quad q = quad(op, operand(vartype::none, currScope, "none"), rOperand, lOperand);
            quadManager.push(q);
            quadManager.operands.push(lOperand);
        }
    }
#line 1475 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 73: /* $@11: %empty  */
#line 303 "src/MochiParser/MochiParser.y"
         {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::plus || quadManager.operators.top() == operatortype::minus)) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, lOperand, rOperand, temp);

                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }
#line 1503 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 77: /* term_operator: plus  */
#line 335 "src/MochiParser/MochiParser.y"
         { quadManager.operators.push(operatortype::plus); }
#line 1509 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 78: /* term_operator: minus  */
#line 336 "src/MochiParser/MochiParser.y"
            { quadManager.operators.push(operatortype::minus); }
#line 1515 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 79: /* $@12: %empty  */
#line 340 "src/MochiParser/MochiParser.y"
           {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::asterisk || quadManager.operators.top() == operatortype::slash)) {
            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operand lOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();

            CubeEntry entry = CubeEntry(lOperand.type, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);

            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, lOperand, rOperand, temp);

                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }
#line 1543 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 83: /* factor_operator: asterisk  */
#line 372 "src/MochiParser/MochiParser.y"
             { quadManager.operators.push(operatortype::asterisk); }
#line 1549 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 84: /* factor_operator: slash  */
#line 373 "src/MochiParser/MochiParser.y"
            { quadManager.operators.push(operatortype::slash); }
#line 1555 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 85: /* $@13: %empty  */
#line 377 "src/MochiParser/MochiParser.y"
                  {
        quadManager.operators.push(operatortype::fake_bottom);
    }
#line 1563 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 86: /* factor: l_parenthesis $@13 expression r_parenthesis  */
#line 380 "src/MochiParser/MochiParser.y"
                             {
        if (quadManager.operators.top() != operatortype::fake_bottom) {
            semanticErrors++;
            std::cerr << "Error: Unexpected operator '" << operatortype_string[static_cast<int>(quadManager.operators.top())] << "'" << std::endl;  
        } else {
            // discard fake bottom
            quadManager.operators.pop();
        }
    }
#line 1577 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 87: /* $@14: %empty  */
#line 390 "src/MochiParser/MochiParser.y"
                                 {
        quadManager.operators.push(operatortype::fake_bottom);
    }
#line 1585 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 88: /* factor: opt_operator l_parenthesis $@14 expression r_parenthesis  */
#line 393 "src/MochiParser/MochiParser.y"
                             {
        if (quadManager.operators.top() != operatortype::fake_bottom) {
            semanticErrors++;
            std::cerr << "Error: Unexpected operator '" << operatortype_string[static_cast<int>(quadManager.operators.top())] << "'" << std::endl;  
        } else {
            // discard fake bottom
            quadManager.operators.pop();

            operand rOperand = quadManager.operands.top();
            quadManager.operands.pop();
            operatortype op = quadManager.operators.top();
            quadManager.operators.pop();
    
            CubeEntry entry = CubeEntry(vartype::unknown, rOperand.type, op);
            vartype restype = SemanticCube::resultingType(entry);
    
            if (restype == vartype::unknown) {
                semanticErrors++;
            }else {
                operand temp = quadManager.getTemp(restype);
                quad q = quad(op, operand(vartype::none, currScope, "none"), rOperand, temp);
    
                quadManager.push(q);
                quadManager.operands.push(temp);
            }
        }
    }
#line 1617 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 90: /* factor: opt_operator factor_element  */
#line 423 "src/MochiParser/MochiParser.y"
                                  {
        operand rOperand = quadManager.operands.top();
        quadManager.operands.pop();
        operatortype op = quadManager.operators.top();
        quadManager.operators.pop();

        CubeEntry entry = CubeEntry(vartype::unknown, rOperand.type, op);
        vartype restype = SemanticCube::resultingType(entry);

        if (restype == vartype::unknown) {
            semanticErrors++;
        }else {
            operand temp = quadManager.getTemp(restype);
            quad q = quad(op, operand(vartype::none, currScope, "none"), rOperand, temp);

            quadManager.push(q);
            quadManager.operands.push(temp);
        }
    }
#line 1641 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 91: /* opt_operator: plus  */
#line 445 "src/MochiParser/MochiParser.y"
         { quadManager.operators.push(operatortype::plus); }
#line 1647 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 92: /* opt_operator: minus  */
#line 446 "src/MochiParser/MochiParser.y"
            { quadManager.operators.push(operatortype::minus); }
#line 1653 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 93: /* factor_element: id  */
#line 450 "src/MochiParser/MochiParser.y"
       { 
        VarEntry* var = funcDir.getVar(currScope, (yyvsp[0].s));
        if (var == nullptr) {
            semanticErrors++;
        } else {
            operand op = operand(var->type, currScope, (yyvsp[0].s));
            quadManager.operands.push(op);
        }
    }
#line 1667 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 95: /* num_constant: int_constant  */
#line 463 "src/MochiParser/MochiParser.y"
                 {
        operand op = operand(vartype::int_type, currScope, std::to_string((yyvsp[0].i)));
        quadManager.operands.push(op);
    }
#line 1676 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 96: /* num_constant: float_constant  */
#line 467 "src/MochiParser/MochiParser.y"
                     {
        operand op = operand(vartype::float_type, currScope, std::to_string((yyvsp[0].f)));
        quadManager.operands.push(op);
    }
#line 1685 "src/MochiParser/MochiParser.tab.cpp"
    break;


#line 1689 "src/MochiParser/MochiParser.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 473 "src/MochiParser/MochiParser.y"
