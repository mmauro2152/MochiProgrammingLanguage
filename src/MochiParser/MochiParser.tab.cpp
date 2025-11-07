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
  YYSYMBOL_bool_token = 20,                /* bool_token  */
  YYSYMBOL_l_curly_brace = 21,             /* l_curly_brace  */
  YYSYMBOL_r_curly_brace = 22,             /* r_curly_brace  */
  YYSYMBOL_l_square_bracket = 23,          /* l_square_bracket  */
  YYSYMBOL_r_square_bracket = 24,          /* r_square_bracket  */
  YYSYMBOL_l_parenthesis = 25,             /* l_parenthesis  */
  YYSYMBOL_r_parenthesis = 26,             /* r_parenthesis  */
  YYSYMBOL_plus = 27,                      /* plus  */
  YYSYMBOL_minus = 28,                     /* minus  */
  YYSYMBOL_asterisk = 29,                  /* asterisk  */
  YYSYMBOL_slash = 30,                     /* slash  */
  YYSYMBOL_equal_smaller_than = 31,        /* equal_smaller_than  */
  YYSYMBOL_l_angle_bracket = 32,           /* l_angle_bracket  */
  YYSYMBOL_equal_greater_than = 33,        /* equal_greater_than  */
  YYSYMBOL_r_angle_bracket = 34,           /* r_angle_bracket  */
  YYSYMBOL_equal = 35,                     /* equal  */
  YYSYMBOL_assign = 36,                    /* assign  */
  YYSYMBOL_not_equal = 37,                 /* not_equal  */
  YYSYMBOL_not_ = 38,                      /* not_  */
  YYSYMBOL_and_ = 39,                      /* and_  */
  YYSYMBOL_or_ = 40,                       /* or_  */
  YYSYMBOL_id = 41,                        /* id  */
  YYSYMBOL_int_constant = 42,              /* int_constant  */
  YYSYMBOL_float_constant = 43,            /* float_constant  */
  YYSYMBOL_string_constant = 44,           /* string_constant  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program_declaration = 46,       /* program_declaration  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_opt_funcs = 49,                 /* opt_funcs  */
  YYSYMBOL_opt_funcs_ = 50,                /* opt_funcs_  */
  YYSYMBOL_opt_vars = 51,                  /* opt_vars  */
  YYSYMBOL_vars = 52,                      /* vars  */
  YYSYMBOL_var_loop = 53,                  /* var_loop  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_var_loop_ = 55,                 /* var_loop_  */
  YYSYMBOL_id_loop = 56,                   /* id_loop  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_id_loop_ = 58,                  /* id_loop_  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_func_type = 60,                 /* func_type  */
  YYSYMBOL_funcs = 61,                     /* funcs  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_params = 63,                    /* params  */
  YYSYMBOL_param_loop = 64,                /* param_loop  */
  YYSYMBOL_65_6 = 65,                      /* $@6  */
  YYSYMBOL_param_loop_ = 66,               /* param_loop_  */
  YYSYMBOL_body = 67,                      /* body  */
  YYSYMBOL_statement_loop = 68,            /* statement_loop  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_assign_statement = 70,          /* assign_statement  */
  YYSYMBOL_71_7 = 71,                      /* $@7  */
  YYSYMBOL_72_8 = 72,                      /* $@8  */
  YYSYMBOL_assign_statement_ = 73,         /* assign_statement_  */
  YYSYMBOL_74_9 = 74,                      /* $@9  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_condition_statement = 76,       /* condition_statement  */
  YYSYMBOL_opt_else = 77,                  /* opt_else  */
  YYSYMBOL_cycle_statement = 78,           /* cycle_statement  */
  YYSYMBOL_print_statement = 79,           /* print_statement  */
  YYSYMBOL_print_loop = 80,                /* print_loop  */
  YYSYMBOL_print_loop_ = 81,               /* print_loop_  */
  YYSYMBOL_print_element = 82,             /* print_element  */
  YYSYMBOL_func_call_statement = 83,       /* func_call_statement  */
  YYSYMBOL_opt_expression_loop = 84,       /* opt_expression_loop  */
  YYSYMBOL_expression_loop = 85,           /* expression_loop  */
  YYSYMBOL_expression_loop_ = 86,          /* expression_loop_  */
  YYSYMBOL_expression = 87,                /* expression  */
  YYSYMBOL_88_11 = 88,                     /* $@11  */
  YYSYMBOL_or_exp_ = 89,                   /* or_exp_  */
  YYSYMBOL_90_12 = 90,                     /* $@12  */
  YYSYMBOL_or_exp = 91,                    /* or_exp  */
  YYSYMBOL_92_13 = 92,                     /* $@13  */
  YYSYMBOL_and_exp_ = 93,                  /* and_exp_  */
  YYSYMBOL_94_14 = 94,                     /* $@14  */
  YYSYMBOL_and_exp = 95,                   /* and_exp  */
  YYSYMBOL_96_15 = 96,                     /* $@15  */
  YYSYMBOL_eq_oper = 97,                   /* eq_oper  */
  YYSYMBOL_eq_exp_ = 98,                   /* eq_exp_  */
  YYSYMBOL_eq_exp = 99,                    /* eq_exp  */
  YYSYMBOL_100_16 = 100,                   /* $@16  */
  YYSYMBOL_rel_exp_ = 101,                 /* rel_exp_  */
  YYSYMBOL_rel_oper = 102,                 /* rel_oper  */
  YYSYMBOL_rel_exp = 103,                  /* rel_exp  */
  YYSYMBOL_104_17 = 104,                   /* $@17  */
  YYSYMBOL_term_ = 105,                    /* term_  */
  YYSYMBOL_term_operator = 106,            /* term_operator  */
  YYSYMBOL_term = 107,                     /* term  */
  YYSYMBOL_108_18 = 108,                   /* $@18  */
  YYSYMBOL_factor_ = 109,                  /* factor_  */
  YYSYMBOL_factor_operator = 110,          /* factor_operator  */
  YYSYMBOL_factor = 111,                   /* factor  */
  YYSYMBOL_112_19 = 112,                   /* $@19  */
  YYSYMBOL_113_20 = 113,                   /* $@20  */
  YYSYMBOL_opt_operator = 114,             /* opt_operator  */
  YYSYMBOL_factor_element = 115,           /* factor_element  */
  YYSYMBOL_num_constant = 116              /* num_constant  */
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
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    60,    52,    70,    72,    76,    79,    81,
      85,    89,    89,   100,   102,   106,   106,   110,   112,   116,
     117,   118,   119,   123,   124,   128,   128,   137,   139,   143,
     143,   149,   151,   155,   158,   160,   164,   165,   166,   167,
     168,   172,   181,   172,   205,   206,   215,   206,   240,   243,
     245,   249,   253,   257,   260,   262,   266,   267,   271,   274,
     276,   280,   281,   284,   286,   290,   290,   316,   318,   318,
     322,   322,   348,   350,   350,   354,   354,   381,   382,   385,
     387,   391,   391,   417,   419,   423,   424,   425,   426,   430,
     430,   456,   458,   462,   463,   467,   467,   493,   495,   499,
     500,   504,   504,   517,   517,   548,   550,   572,   573,   574,
     578,   587,   591,   595
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
  "float_token", "bool_token", "l_curly_brace", "r_curly_brace",
  "l_square_bracket", "r_square_bracket", "l_parenthesis", "r_parenthesis",
  "plus", "minus", "asterisk", "slash", "equal_smaller_than",
  "l_angle_bracket", "equal_greater_than", "r_angle_bracket", "equal",
  "assign", "not_equal", "not_", "and_", "or_", "id", "int_constant",
  "float_constant", "string_constant", "$accept", "program_declaration",
  "$@1", "$@2", "opt_funcs", "opt_funcs_", "opt_vars", "vars", "var_loop",
  "$@3", "var_loop_", "id_loop", "$@4", "id_loop_", "type", "func_type",
  "funcs", "$@5", "params", "param_loop", "$@6", "param_loop_", "body",
  "statement_loop", "statement", "assign_statement", "$@7", "$@8",
  "assign_statement_", "$@9", "$@10", "condition_statement", "opt_else",
  "cycle_statement", "print_statement", "print_loop", "print_loop_",
  "print_element", "func_call_statement", "opt_expression_loop",
  "expression_loop", "expression_loop_", "expression", "$@11", "or_exp_",
  "$@12", "or_exp", "$@13", "and_exp_", "$@14", "and_exp", "$@15",
  "eq_oper", "eq_exp_", "eq_exp", "$@16", "rel_exp_", "rel_oper",
  "rel_exp", "$@17", "term_", "term_operator", "term", "$@18", "factor_",
  "factor_operator", "factor", "$@19", "$@20", "opt_operator",
  "factor_element", "num_constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,     0,    19,  -104,  -104,    26,    30,     3,    52,  -104,
    -104,  -104,    33,  -104,  -104,  -104,  -104,  -104,    41,  -104,
       9,    52,    37,    56,  -104,  -104,  -104,  -104,     3,  -104,
      40,    32,    31,  -104,  -104,    -2,    54,    18,     3,    43,
      63,    64,    65,    57,    -2,  -104,  -104,  -104,  -104,  -104,
    -104,    62,    66,  -104,  -104,  -104,   -18,    20,    20,   -11,
      55,  -104,  -104,    56,    70,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,    68,    81,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,    -7,  -104,  -104,    71,    72,    84,    74,  -104,
      84,  -104,  -104,    30,    20,    87,   -18,  -104,    67,    69,
     -22,    53,    -6,    -1,  -104,  -104,    93,    32,   -11,  -104,
      89,  -104,    39,    90,    32,    78,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,    20,  -104,  -104,  -104,  -104,  -104,
    -104,    20,  -104,  -104,  -104,    20,  -104,  -104,  -104,    20,
      20,    32,    95,  -104,  -104,    73,    96,  -104,    18,  -104,
      88,  -104,    20,    20,  -104,  -104,  -104,  -104,    85,    99,
      32,   100,    79,  -104,  -104,   102,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,    39,  -104
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     8,     0,     5,     9,
      15,    10,     0,    23,    21,    19,    20,    22,     0,    24,
       0,     5,    17,     0,     3,    25,     7,     6,     0,    16,
       0,     0,     0,    18,    11,    34,     0,    27,    13,     0,
       0,     0,    41,     0,    34,    36,    37,    38,    39,    40,
       4,     0,     0,    28,    14,    12,     0,     0,     0,    59,
       0,    33,    35,     0,     0,   101,   107,   108,   109,   110,
     112,   113,    57,     0,    54,    56,    65,    70,    75,    81,
      89,    95,     0,   105,   111,     0,     0,    63,     0,    60,
      63,    42,    29,     8,     0,     0,     0,    53,    67,    72,
      79,    83,    91,    97,   103,   106,     0,     0,     0,    62,
       0,    61,     0,    31,     0,     0,    52,    55,    68,    66,
      73,    71,    77,    78,     0,    76,    87,    88,    85,    86,
      82,     0,    93,    94,    90,     0,    99,   100,    96,     0,
       0,     0,    49,    64,    58,   110,     0,    44,     0,    30,
       0,   102,     0,     0,    80,    84,    92,    98,     0,     0,
       0,     0,     0,    43,    32,     0,    69,    74,   104,    51,
      50,    48,    46,    26,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -104,  -104,  -104,  -104,    97,  -104,    27,  -104,    83,  -104,
    -104,    91,  -104,  -104,   -20,  -104,  -104,  -104,  -104,   -26,
    -104,  -104,  -103,    80,  -104,  -104,  -104,  -104,   -51,  -104,
    -104,  -104,  -104,  -104,  -104,    29,  -104,  -104,  -104,  -104,
      21,    36,   -57,  -104,  -104,  -104,   -25,  -104,  -104,  -104,
       6,  -104,  -104,  -104,    -4,  -104,  -104,  -104,    -3,  -104,
    -104,  -104,    -8,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
      51,  -104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,    31,    18,    27,     8,     9,    11,    38,
      55,    12,    22,    29,    19,    20,    21,    32,    52,    53,
     113,   149,    36,    43,    44,    45,    60,   112,   146,   162,
     174,    46,   161,    47,    48,    73,    97,    74,    49,    88,
      89,   109,    75,    98,   119,   152,    76,    99,   121,   153,
      77,   100,   124,   125,    78,   101,   130,   131,    79,   102,
     134,   135,    80,   103,   138,   139,    81,    94,   140,    82,
      83,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,    86,    90,    30,   142,    39,    40,    65,    41,    66,
      67,   150,     1,   122,    65,   123,    66,    67,   104,     4,
      68,   132,   133,    69,    70,    71,    72,    68,   136,   137,
      69,    70,    71,    87,    69,    70,    71,   115,   159,    42,
       6,     3,     7,    92,    10,    65,    24,    66,    67,    23,
      25,    90,    28,    35,    34,   147,    37,   170,    68,    51,
      50,    69,    70,    71,    65,    13,    66,    67,    56,    14,
      15,    16,    17,    14,    15,    16,    17,    68,    63,    61,
     145,    70,    71,   158,   126,   127,   128,   129,    57,    58,
      59,    91,    64,    93,    95,   166,    96,   106,   107,   108,
     110,   116,   141,   144,   151,   148,   160,   118,   120,   -45,
     163,   168,   165,   169,   171,   172,   173,   147,    26,    33,
     114,    54,   164,   175,    62,   117,   111,   155,   167,   143,
     154,   157,   156,   105
};

static const yytype_uint8 yycheck[] =
{
      57,    58,    59,    23,   107,     7,     8,    25,    10,    27,
      28,   114,     4,    35,    25,    37,    27,    28,    25,     0,
      38,    27,    28,    41,    42,    43,    44,    38,    29,    30,
      41,    42,    43,    44,    41,    42,    43,    94,   141,    41,
      14,    41,    12,    63,    41,    25,     5,    27,    28,    16,
      41,   108,    15,    21,    14,   112,    25,   160,    38,    41,
       6,    41,    42,    43,    25,    13,    27,    28,    25,    17,
      18,    19,    20,    17,    18,    19,    20,    38,    16,    22,
      41,    42,    43,   140,    31,    32,    33,    34,    25,    25,
      25,    36,    26,    23,    26,   152,    15,    26,    26,    15,
      26,    14,     9,    14,    26,    15,    11,    40,    39,    36,
      14,    26,    24,    14,    14,    36,    14,   174,    21,    28,
      93,    38,   148,   174,    44,    96,    90,   131,   153,   108,
     124,   139,   135,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    46,    41,     0,    47,    14,    12,    51,    52,
      41,    53,    56,    13,    17,    18,    19,    20,    49,    59,
      60,    61,    57,    16,     5,    41,    49,    50,    15,    58,
      59,    48,    62,    56,    14,    21,    67,    25,    54,     7,
       8,    10,    41,    68,    69,    70,    76,    78,    79,    83,
       6,    41,    63,    64,    53,    55,    25,    25,    25,    25,
      71,    22,    68,    16,    26,    25,    27,    28,    38,    41,
      42,    43,    44,    80,    82,    87,    91,    95,    99,   103,
     107,   111,   114,   115,   116,    87,    87,    44,    84,    85,
      87,    36,    59,    23,   112,    26,    15,    81,    88,    92,
      96,   100,   104,   108,    25,   115,    26,    26,    15,    86,
      26,    86,    72,    65,    51,    87,    14,    80,    40,    89,
      39,    93,    35,    37,    97,    98,    31,    32,    33,    34,
     101,   102,    27,    28,   105,   106,    29,    30,   109,   110,
     113,     9,    67,    85,    14,    41,    73,    87,    15,    66,
      67,    26,    90,    94,    95,    99,   103,   107,    87,    67,
      11,    77,    74,    14,    64,    24,    87,    91,    26,    14,
      67,    14,    36,    14,    75,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    47,    48,    46,    49,    49,    50,    51,    51,
      52,    54,    53,    55,    55,    57,    56,    58,    58,    59,
      59,    59,    59,    60,    60,    62,    61,    63,    63,    65,
      64,    66,    66,    67,    68,    68,    69,    69,    69,    69,
      69,    71,    72,    70,    73,    74,    75,    73,    76,    77,
      77,    78,    79,    80,    81,    81,    82,    82,    83,    84,
      84,    85,    85,    86,    86,    88,    87,    89,    90,    89,
      92,    91,    93,    94,    93,    96,    95,    97,    97,    98,
      98,   100,    99,   101,   101,   102,   102,   102,   102,   104,
     103,   105,   105,   106,   106,   108,   107,   109,   109,   110,
     110,   112,   111,   113,   111,   111,   111,   114,   114,   114,
     115,   115,   116,   116
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,    10,     0,     2,     1,     0,     1,
       2,     0,     6,     0,     1,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     0,    11,     0,     1,     0,
       5,     0,     2,     3,     0,     2,     1,     1,     1,     1,
       1,     0,     0,     6,     1,     0,     0,     5,     7,     0,
       2,     7,     5,     2,     0,     2,     1,     1,     5,     0,
       1,     2,     2,     0,     2,     0,     3,     0,     0,     3,
       0,     3,     0,     0,     3,     0,     3,     1,     1,     0,
       2,     0,     3,     0,     2,     1,     1,     1,     1,     0,
       3,     0,     2,     1,     1,     0,     3,     0,     2,     1,
       1,     0,     4,     0,     5,     1,     2,     1,     1,     1,
       1,     1,     1,     1
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
#line 1342 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 3: /* $@2: %empty  */
#line 60 "src/MochiParser/MochiParser.y"
                                            { currScope = globalScope; }
#line 1348 "src/MochiParser/MochiParser.tab.cpp"
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
#line 1361 "src/MochiParser/MochiParser.tab.cpp"
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
#line 1375 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 15: /* $@4: %empty  */
#line 106 "src/MochiParser/MochiParser.y"
       { idQueue.push((yyvsp[0].s)); }
#line 1381 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 19: /* type: int_token  */
#line 116 "src/MochiParser/MochiParser.y"
              { currType = vartype::int_type; }
#line 1387 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 20: /* type: float_token  */
#line 117 "src/MochiParser/MochiParser.y"
                  { currType = vartype::float_type; }
#line 1393 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 21: /* type: string_token  */
#line 118 "src/MochiParser/MochiParser.y"
                   { currType = vartype::string_type; }
#line 1399 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 22: /* type: bool_token  */
#line 119 "src/MochiParser/MochiParser.y"
                 { currType = vartype::bool_type; }
#line 1405 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 23: /* func_type: void_token  */
#line 123 "src/MochiParser/MochiParser.y"
               { currType = vartype::void_type; }
#line 1411 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 25: /* $@5: %empty  */
#line 128 "src/MochiParser/MochiParser.y"
                 { 
        currScope = (yyvsp[0].s);
        if (!funcDir.insertFunction(currScope, currType)){
            semanticErrors++;
        }
    }
#line 1422 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 29: /* $@6: %empty  */
#line 143 "src/MochiParser/MochiParser.y"
                  { 
        funcDir.addParameter(currScope, (yyvsp[-2].s), currType);
    }
#line 1430 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 41: /* $@7: %empty  */
#line 172 "src/MochiParser/MochiParser.y"
       {
        VarEntry* var = funcDir.getVar(currScope, (yyvsp[0].s));
        if (var == nullptr) {
            semanticErrors++;
        } else {
            operand op = operand(var->type, currScope, (yyvsp[0].s));
            quadManager.operands.push(op);
        }
    }
#line 1444 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 42: /* $@8: %empty  */
#line 181 "src/MochiParser/MochiParser.y"
           { quadManager.operators.push(operatortype::assign); }
#line 1450 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 43: /* assign_statement: id $@7 assign $@8 assign_statement_ semicolon  */
#line 182 "src/MochiParser/MochiParser.y"
                                {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && quadManager.operators.top() == operatortype::assign) {
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
    }
#line 1475 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 45: /* $@9: %empty  */
#line 206 "src/MochiParser/MochiParser.y"
         {
        VarEntry* var = funcDir.getVar(currScope, (yyvsp[0].s));
        if (var == nullptr) {
            semanticErrors++;
        } else {
            operand op = operand(var->type, currScope, (yyvsp[0].s));
            quadManager.operands.push(op);
        }
    }
#line 1489 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 46: /* $@10: %empty  */
#line 215 "src/MochiParser/MochiParser.y"
           { quadManager.operators.push(operatortype::assign); }
#line 1495 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 47: /* assign_statement_: id $@9 assign $@10 assign_statement_  */
#line 216 "src/MochiParser/MochiParser.y"
                      {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && quadManager.operators.top() == operatortype::assign) {
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
    }
#line 1521 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 65: /* $@11: %empty  */
#line 290 "src/MochiParser/MochiParser.y"
           {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::or_)) {
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
#line 1549 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 68: /* $@12: %empty  */
#line 318 "src/MochiParser/MochiParser.y"
          { quadManager.operators.push(operatortype::or_); }
#line 1555 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 70: /* $@13: %empty  */
#line 322 "src/MochiParser/MochiParser.y"
            {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::and_)) {
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
#line 1583 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 73: /* $@14: %empty  */
#line 350 "src/MochiParser/MochiParser.y"
           { quadManager.operators.push(operatortype::and_); }
#line 1589 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 75: /* $@15: %empty  */
#line 354 "src/MochiParser/MochiParser.y"
           {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::equal || quadManager.operators.top() == operatortype::not_equal)) {
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
#line 1617 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 77: /* eq_oper: equal  */
#line 381 "src/MochiParser/MochiParser.y"
          { quadManager.operators.push(operatortype::equal); }
#line 1623 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 78: /* eq_oper: not_equal  */
#line 382 "src/MochiParser/MochiParser.y"
                { quadManager.operators.push(operatortype::not_equal); }
#line 1629 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 81: /* $@16: %empty  */
#line 391 "src/MochiParser/MochiParser.y"
            {
        if (!quadManager.operators.empty() && !quadManager.operands.empty() && (quadManager.operators.top() == operatortype::equal_greater_than || quadManager.operators.top() == operatortype::greater_than || quadManager.operators.top() == operatortype::equal_smaller_than || quadManager.operators.top() == operatortype::smaller_than)) {
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
#line 1657 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 85: /* rel_oper: equal_greater_than  */
#line 423 "src/MochiParser/MochiParser.y"
                       { quadManager.operators.push(operatortype::equal_greater_than); }
#line 1663 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 86: /* rel_oper: r_angle_bracket  */
#line 424 "src/MochiParser/MochiParser.y"
                      { quadManager.operators.push(operatortype::greater_than); }
#line 1669 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 87: /* rel_oper: equal_smaller_than  */
#line 425 "src/MochiParser/MochiParser.y"
                         { quadManager.operators.push(operatortype::equal_smaller_than); }
#line 1675 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 88: /* rel_oper: l_angle_bracket  */
#line 426 "src/MochiParser/MochiParser.y"
                      { quadManager.operators.push(operatortype::smaller_than); }
#line 1681 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 89: /* $@17: %empty  */
#line 430 "src/MochiParser/MochiParser.y"
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
#line 1709 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 93: /* term_operator: plus  */
#line 462 "src/MochiParser/MochiParser.y"
         { quadManager.operators.push(operatortype::plus); }
#line 1715 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 94: /* term_operator: minus  */
#line 463 "src/MochiParser/MochiParser.y"
            { quadManager.operators.push(operatortype::minus); }
#line 1721 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 95: /* $@18: %empty  */
#line 467 "src/MochiParser/MochiParser.y"
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
#line 1749 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 99: /* factor_operator: asterisk  */
#line 499 "src/MochiParser/MochiParser.y"
             { quadManager.operators.push(operatortype::asterisk); }
#line 1755 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 100: /* factor_operator: slash  */
#line 500 "src/MochiParser/MochiParser.y"
            { quadManager.operators.push(operatortype::slash); }
#line 1761 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 101: /* $@19: %empty  */
#line 504 "src/MochiParser/MochiParser.y"
                  {
        quadManager.operators.push(operatortype::fake_bottom);
    }
#line 1769 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 102: /* factor: l_parenthesis $@19 expression r_parenthesis  */
#line 507 "src/MochiParser/MochiParser.y"
                             {
        if (quadManager.operators.top() != operatortype::fake_bottom) {
            semanticErrors++;
            std::cerr << "Error: Unexpected operator '" << operatortype_string[static_cast<int>(quadManager.operators.top())] << "'" << std::endl;  
        } else {
            // discard fake bottom
            quadManager.operators.pop();
        }
    }
#line 1783 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 103: /* $@20: %empty  */
#line 517 "src/MochiParser/MochiParser.y"
                                 {
        quadManager.operators.push(operatortype::fake_bottom);
    }
#line 1791 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 104: /* factor: opt_operator l_parenthesis $@20 expression r_parenthesis  */
#line 520 "src/MochiParser/MochiParser.y"
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
#line 1823 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 106: /* factor: opt_operator factor_element  */
#line 550 "src/MochiParser/MochiParser.y"
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
#line 1847 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 107: /* opt_operator: plus  */
#line 572 "src/MochiParser/MochiParser.y"
         { quadManager.operators.push(operatortype::plus); }
#line 1853 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 108: /* opt_operator: minus  */
#line 573 "src/MochiParser/MochiParser.y"
            { quadManager.operators.push(operatortype::minus); }
#line 1859 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 109: /* opt_operator: not_  */
#line 574 "src/MochiParser/MochiParser.y"
           { quadManager.operators.push(operatortype::not_); }
#line 1865 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 110: /* factor_element: id  */
#line 578 "src/MochiParser/MochiParser.y"
       { 
        VarEntry* var = funcDir.getVar(currScope, (yyvsp[0].s));
        if (var == nullptr) {
            semanticErrors++;
        } else {
            operand op = operand(var->type, currScope, (yyvsp[0].s));
            quadManager.operands.push(op);
        }
    }
#line 1879 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 112: /* num_constant: int_constant  */
#line 591 "src/MochiParser/MochiParser.y"
                 {
        operand op = operand(vartype::int_type, currScope, std::to_string((yyvsp[0].i)));
        quadManager.operands.push(op);
    }
#line 1888 "src/MochiParser/MochiParser.tab.cpp"
    break;

  case 113: /* num_constant: float_constant  */
#line 595 "src/MochiParser/MochiParser.y"
                     {
        operand op = operand(vartype::float_type, currScope, std::to_string((yyvsp[0].f)));
        quadManager.operands.push(op);
    }
#line 1897 "src/MochiParser/MochiParser.tab.cpp"
    break;


#line 1901 "src/MochiParser/MochiParser.tab.cpp"

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

#line 601 "src/MochiParser/MochiParser.y"
