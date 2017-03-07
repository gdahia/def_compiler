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
#line 1 "src/grammar.y" /* yacc.c:339  */

#include <vector>
#include <string>

#include <ast.hpp>

AST::Program program;

extern int yylex();

void yyerror(const char * s) {
    throw std::runtime_error(s);
}


#line 82 "src/parser.cpp" /* yacc.c:339  */

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
   by #include "parser.hpp".  */
#ifndef YY_YY_SRC_PARSER_HPP_INCLUDED
# define YY_YY_SRC_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 17 "src/grammar.y" /* yacc.c:355  */

#include <holder.hpp>

#define YYSTYPE Holder

#line 118 "src/parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    VOID = 259,
    ID = 260,
    DEC = 261,
    DEF = 262,
    IF = 263,
    WHILE = 264,
    RETURN = 265,
    CONTINUE = 266,
    BREAK = 267,
    ELSE = 268,
    LEQ = 269,
    GEQ = 270,
    AND = 271,
    OR = 272,
    EQ = 273,
    DIFF = 274,
    MINUS = 275,
    PLUS = 276,
    STAR = 277,
    SLASH = 278,
    ASS = 279,
    LPAR = 280,
    RPAR = 281,
    LBRAC = 282,
    RBRAC = 283,
    COMMA = 284,
    SCOLON = 285,
    LESS = 286,
    GREAT = 287,
    NOT = 288,
    UMINUS = 289
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 171 "src/parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    54,    55,    56,    58,    59,    61,    62,
      64,    66,    67,    69,    71,    72,    74,    75,    77,    78,
      79,    80,    81,    82,    83,    84,    86,    87,    89,    91,
      92,    94,    96,    97,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   118,   119
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "ID", "DEC", "DEF", "IF",
  "WHILE", "RETURN", "CONTINUE", "BREAK", "ELSE", "LEQ", "GEQ", "AND",
  "OR", "EQ", "DIFF", "MINUS", "PLUS", "STAR", "SLASH", "ASS", "LPAR",
  "RPAR", "LBRAC", "RBRAC", "COMMA", "SCOLON", "LESS", "GREAT", "NOT",
  "UMINUS", "$accept", "program", "instr", "decvar", "decfunc",
  "paramlist", "params", "block", "decvars", "stmts", "stmt", "decl",
  "assign", "funccall", "arglist", "args", "expr", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF -45

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      59,   -45,   -45,    67,    44,   -45,    59,    59,    30,    47,
     -45,   -45,   -45,    35,    62,    25,   -45,     6,    65,   -45,
      25,    25,    25,   -45,    63,    79,    29,    86,    21,   -45,
      82,   -45,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,   -45,    25,    25,    67,   -45,    79,    78,   -45,
      66,   101,   -45,   -16,   -16,   211,   196,   224,   224,    50,
      50,   -45,   -45,   -16,   -16,    67,    28,   -45,    67,   -45,
     -45,    25,   -45,   -45,    64,    84,    85,    23,    81,    95,
      98,    28,    97,   -45,   -45,   107,   101,    25,    25,    25,
     -45,   120,   -45,   -45,   -45,   -45,   -45,    78,   -45,   177,
     139,   158,   -45,   -45,    79,    79,   115,   -45,    79,   -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    52,    53,     0,     0,     2,     5,     5,     0,     0,
       1,     3,     4,     0,     0,     0,     6,     0,    51,    50,
       0,     0,     0,    49,     0,     0,     0,     0,     0,    46,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     0,    15,     9,     0,    12,    30,
       0,    33,    48,    39,    41,    44,    45,    42,    43,    35,
      34,    36,    37,    38,    40,    15,    17,     8,     0,    10,
      29,     0,    31,    14,     0,     0,     0,     0,     0,     0,
       0,    17,     0,    26,    27,     0,    33,     0,     0,     0,
      23,     0,    25,    24,    13,    16,    18,    12,    32,    28,
       0,     0,    22,    11,     0,     0,    19,    21,     0,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,    68,   -23,   -45,   -45,    32,   -44,    80,    83,
     -45,   -45,   -45,   -32,   -45,    45,   -20,     8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    26,    69,    46,    66,    80,
      81,    82,    83,    23,    50,    72,    24,     8
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      29,    30,    31,    67,    38,    39,    40,    41,    51,     1,
       2,     9,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    65,    63,    64,    27,    18,    19,    18,    19,
      18,    19,    25,    74,    84,    13,    75,    76,    77,    78,
      79,    20,    65,    20,    10,    20,    21,    49,    21,    84,
      21,    86,    14,    90,    22,    47,    22,    91,    22,    15,
     106,   107,     1,     2,   109,    16,     3,    99,   100,   101,
       1,     2,    40,    41,    11,    12,    85,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    17,    87,    28,
      28,    48,    70,    42,    43,    44,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    45,    68,    52,    88,
      89,    92,    97,    43,    44,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    93,    94,    96,   108,   103,
      71,    98,    43,    44,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    73,     0,     0,     0,     0,
     102,    43,    44,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,    95,   104,     0,     0,     0,     0,
      43,    44,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,   105,     0,     0,     0,     0,    43,
      44,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,     0,     0,     0,     0,    43,    44,
      32,    33,    34,     0,    36,    37,    38,    39,    40,    41,
       0,     0,     0,     0,     0,    32,    33,    43,    44,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    32,    33,
       0,     0,    43,    44,    38,    39,    40,    41,     0,     0,
       0,     0,     0,     0,     0,    43,    44
};

static const yytype_int8 yycheck[] =
{
      20,    21,    22,    47,    20,    21,    22,    23,    28,     3,
       4,     3,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    45,    43,    44,    17,     5,     6,     5,     6,
       5,     6,    26,     5,    66,     5,     8,     9,    10,    11,
      12,    20,    65,    20,     0,    20,    25,    26,    25,    81,
      25,    71,     5,    30,    33,    26,    33,    77,    33,    24,
     104,   105,     3,     4,   108,    30,     7,    87,    88,    89,
       3,     4,    22,    23,     6,     7,    68,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    25,    24,    25,
      25,     5,    26,    30,    31,    32,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    27,    29,    26,    25,
      25,    30,     5,    31,    32,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    30,    28,    30,    13,    97,
      29,    86,    31,    32,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    65,    -1,    -1,    -1,    -1,
      30,    31,    32,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    81,    26,    -1,    -1,    -1,    -1,
      31,    32,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    31,
      32,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    14,    15,    31,    32,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    14,    15,
      -1,    -1,    31,    32,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,    36,    37,    38,    39,    52,    52,
       0,    37,    37,     5,     5,    24,    30,    25,     5,     6,
      20,    25,    33,    48,    51,    26,    40,    52,    25,    51,
      51,    51,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    30,    31,    32,    27,    42,    26,     5,    26,
      49,    51,    26,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    38,    43,    42,    29,    41,
      26,    29,    50,    43,     5,     8,     9,    10,    11,    12,
      44,    45,    46,    47,    48,    52,    51,    24,    25,    25,
      30,    51,    30,    30,    28,    44,    30,     5,    50,    51,
      51,    51,    30,    41,    26,    26,    42,    42,    13,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    37,    38,    38,    39,    39,
      40,    41,    41,    42,    43,    43,    44,    44,    45,    45,
      45,    45,    45,    45,    45,    45,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     5,     7,     6,
       3,     4,     0,     4,     2,     0,     2,     0,     2,     5,
       7,     5,     3,     2,     2,     2,     1,     1,     3,     4,
       3,     2,     3,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     1,
       1,     1,     1,     1
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
        case 3:
#line 54 "src/grammar.y" /* yacc.c:1646  */
    { program.instr.push_back((yyvsp[-1].decvar)); }
#line 1344 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 55 "src/grammar.y" /* yacc.c:1646  */
    { program.instr.push_back((yyvsp[-1].decfunc)); }
#line 1350 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.decvar) = std::make_shared<AST::DecVar>((yyvsp[-2].token), (yyvsp[-1].lexeme)); }
#line 1356 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.decvar) = std::make_shared<AST::DecVar>((yyvsp[-4].token), (yyvsp[-3].lexeme), (yyvsp[-1].expr)); }
#line 1362 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 61 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.decfunc) = std::make_shared<AST::DecFunc>((yyvsp[-5].token), (yyvsp[-4].lexeme), (yyvsp[-2].params), (yyvsp[0].block)); }
#line 1368 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 62 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.decfunc) = std::make_shared<AST::DecFunc>((yyvsp[-4].token), (yyvsp[-3].lexeme), (yyvsp[0].block)); }
#line 1374 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 64 "src/grammar.y" /* yacc.c:1646  */
    { (yyvsp[0].params)->emplace_back((yyvsp[-2].token), (yyvsp[-1].lexeme)); (yyval.params) = (yyvsp[0].params); }
#line 1380 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 66 "src/grammar.y" /* yacc.c:1646  */
    { (yyvsp[0].params)->emplace_back((yyvsp[-2].token), (yyvsp[-1].lexeme)); (yyval.params) = (yyvsp[0].params); }
#line 1386 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 67 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.params) = std::make_shared<std::vector<AST::Param>>(); }
#line 1392 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 69 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.block) = std::make_shared<AST::Block>((yyvsp[-2].decvars), (yyvsp[-1].stmts)); }
#line 1398 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 71 "src/grammar.y" /* yacc.c:1646  */
    { (yyvsp[0].decvars)->push_back((yyvsp[-1].decvar)); (yyval.decvars) = (yyvsp[0].decvars); }
#line 1404 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 72 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.decvars) = std::make_shared<std::vector<std::shared_ptr<AST::DecVar>>>(); }
#line 1410 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 74 "src/grammar.y" /* yacc.c:1646  */
    { (yyvsp[0].stmts)->push_back((yyvsp[-1].stmt)); (yyval.stmts) = (yyvsp[0].stmts); }
#line 1416 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 75 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmts) = std::make_shared<std::vector<std::shared_ptr<AST::Stmt>>>(); }
#line 1422 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 77 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].stmt); }
#line 1428 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 78 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = std::make_shared<AST::If>((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1434 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 79 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = std::make_shared<AST::If>((yyvsp[-4].expr), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1440 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 80 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = std::make_shared<AST::While>((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1446 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 81 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = std::make_shared<AST::Return>((yyvsp[-1].expr)); }
#line 1452 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 82 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = std::make_shared<AST::Return>(); }
#line 1458 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 83 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = std::make_shared<AST::Break>(); }
#line 1464 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 84 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = std::make_shared<AST::Continue>(); }
#line 1470 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 86 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1476 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 87 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].funccall); }
#line 1482 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 89 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.stmt) = std::make_shared<AST::Assign>((yyvsp[-2].lexeme), (yyvsp[0].expr)); }
#line 1488 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 91 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.funccall) = std::make_shared<AST::FuncCall>((yyvsp[-3].lexeme), (yyvsp[-1].args)); }
#line 1494 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 92 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.funccall) = std::make_shared<AST::FuncCall>((yyvsp[-2].lexeme)); }
#line 1500 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 94 "src/grammar.y" /* yacc.c:1646  */
    { (yyvsp[0].args)->push_back((yyvsp[-1].expr)); (yyval.args) = (yyvsp[0].args); }
#line 1506 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 96 "src/grammar.y" /* yacc.c:1646  */
    { (yyvsp[0].args)->push_back((yyvsp[-1].expr)); (yyval.args) = (yyvsp[0].args); }
#line 1512 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 97 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.args) = std::make_shared<std::vector<std::shared_ptr<AST::Expr>>>(); }
#line 1518 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 99 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Add>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1524 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 100 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Sub>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1530 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 101 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Times>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1536 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 102 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Div>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1542 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 103 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Less>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1548 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 104 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Leq>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1554 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 105 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Great>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1560 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 106 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Geq>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1566 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 107 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Eq>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1572 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 108 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Diff>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1578 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 109 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::And>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1584 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 110 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Or>((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1590 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 111 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Opp>((yyvsp[0].expr)); }
#line 1596 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 112 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Not>((yyvsp[0].expr)); }
#line 1602 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 113 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1608 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 114 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].funccall); }
#line 1614 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 115 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Number>((yyvsp[0].lexeme)); }
#line 1620 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 116 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.expr) = std::make_shared<AST::Var>((yyvsp[0].lexeme)); }
#line 1626 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 118 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1632 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 119 "src/grammar.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1638 "src/parser.cpp" /* yacc.c:1646  */
    break;


#line 1642 "src/parser.cpp" /* yacc.c:1646  */
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
#line 121 "src/grammar.y" /* yacc.c:1906  */

