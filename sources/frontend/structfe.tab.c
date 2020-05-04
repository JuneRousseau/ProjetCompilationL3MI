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
#line 1 "structfe.y" /* yacc.c:339  */

#include "structfe.h"
#define SEMANTICERROR 2
#define SYNTAXERROR 1

extern int yylineno;
    

#line 75 "structfe.tab.c" /* yacc.c:339  */

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
   by #include "structfe.tab.h".  */
#ifndef YY_YY_STRUCTFE_TAB_H_INCLUDED
# define YY_YY_STRUCTFE_TAB_H_INCLUDED
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
    SIZEOF = 258,
    PTR_OP = 259,
    LE_OP = 260,
    GE_OP = 261,
    EQ_OP = 262,
    NE_OP = 263,
    AND_OP = 264,
    OR_OP = 265,
    EXTERN = 266,
    INT = 267,
    VOID = 268,
    STRUCT = 269,
    IF = 270,
    ELSE = 271,
    WHILE = 272,
    FOR = 273,
    RETURN = 274,
    IDENTIFIER = 275,
    CONSTANT = 276
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "structfe.y" /* yacc.c:355  */

    char *number;
    attributs_t attributs;
    symbole_t *symbol;

#line 143 "structfe.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_STRUCTFE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 160 "structfe.tab.c" /* yacc.c:358  */

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,     2,
      20,    21,    26,    30,    28,    27,    29,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
      32,    33,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    34,    35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    46,    55,    65,    74,    95,   116,   127,
     134,   148,   156,   182,   190,   201,   207,   212,   221,   229,
     245,   262,   270,   292,   314,   321,   335,   349,   363,   379,
     386,   396,   408,   415,   444,   451,   480,   487,   500,   507,
     516,   523,   532,   538,   544,   553,   554,   555,   559,   560,
     564,   568,   568,   576,   576,   585,   592,   602,   610,   619,
     625,   634,   642,   643,   644,   645,   646,   650,   657,   665,
     673,   682,   688,   697,   703,   712,   719,   728,   744,   763,
     783,   805,   812,   821,   824,   829,   837,   842,   850
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SIZEOF", "PTR_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "EXTERN", "INT", "VOID", "STRUCT",
  "IF", "ELSE", "WHILE", "FOR", "RETURN", "'('", "')'", "'{'", "'}'",
  "';'", "'&'", "'*'", "'-'", "','", "'.'", "'+'", "'>'", "'<'", "'='",
  "IDENTIFIER", "CONSTANT", "\"then\"", "'/'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression", "expression",
  "declaration", "declaration_specifiers", "type_specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "declarator", "@1", "@2", "direct_declarator", "parameter_list",
  "parameter_declaration", "statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "program_start", "program", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      40,    41,   123,   125,    59,    38,    42,    45,    44,    46,
      43,    62,    60,    61,   275,   276,   277,    47
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     114,    39,   -75,   -75,    -7,   -75,    46,   -75,     7,    17,
     114,   -75,   -75,   -75,   -75,    39,    54,   -75,    68,    -9,
     -75,   -75,   -75,    46,    20,   -75,    39,    -9,    96,   -75,
     -75,    46,   -75,    75,    76,   -75,   -75,    56,    75,   234,
      83,    97,   109,   209,   250,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,     6,   104,   250,    45,    59,    18,     5,
     133,   144,   134,   -75,    46,   -75,   -75,   121,   146,   -75,
     -75,   -75,   -75,   136,   139,   -75,   -75,    71,   -75,   250,
     250,   221,   -75,   135,   141,   145,   237,   250,   -75,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   -75,   143,   -75,   -75,   171,   -75,   -75,   -75,   -75,
      46,    52,   -75,   161,   162,   163,   221,   -75,   -75,   -75,
     -75,    73,   -75,   -75,   -75,   -75,   -75,    45,    45,    59,
      59,    59,    59,    18,    18,     5,   133,   -75,   -75,   -75,
     114,   -75,   196,   196,   250,   -75,   250,   -75,   169,   -75,
     166,   -75,   196,   196,   -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    43,    42,     0,    87,    53,    41,    44,     0,
      83,    84,    86,    40,    44,     0,    47,    51,     0,     0,
      39,     1,    85,    53,     0,    48,     0,     0,     0,    38,
      88,    53,    56,    54,     0,    46,    49,     0,    52,     0,
       0,     0,     0,     0,     0,    67,    75,    15,    16,    17,
       4,     3,     5,    11,    18,     0,    21,    24,    29,    32,
      34,    36,     0,    71,    53,    73,    62,     0,     0,    63,
      64,    65,    66,     0,     0,    50,    45,     0,    14,     0,
       0,     0,    81,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,    69,    72,     0,    68,    74,    55,    58,
      53,     0,    59,     0,     0,     0,     0,    82,     2,     8,
       6,     0,     9,    37,    19,    20,    18,    23,    22,    27,
      28,    26,    25,    30,    31,    33,    35,    70,    61,    57,
       0,    13,     0,     0,     0,     7,     0,    60,    77,    79,
       0,    10,     0,     0,    78,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   -75,   -35,   -75,   -70,    82,   -31,    93,
     100,   -75,   -42,   -19,   -28,     4,     8,   175,    -8,   -17,
     -75,   -75,   176,   -75,    62,   -65,   186,   -75,   140,   -74,
     -75,   -75,   -75,   -75,   -75,   198,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    52,    53,   121,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     5,     6,     7,    14,    24,    25,    18,
      27,    19,    33,   111,   112,    65,    66,    67,    68,    69,
      70,    71,    72,     9,    10,    11,    12
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,    83,    84,   107,    78,    13,    34,   116,     8,    63,
      85,    31,    97,    98,    73,    15,    36,    21,     8,    23,
      88,   127,   128,    93,    94,    32,    86,    16,    23,    36,
      23,    20,     2,     3,     4,    84,     8,   114,   115,    64,
     107,    23,   144,    35,   122,   123,   110,   102,   104,    95,
      96,     2,     3,     4,   124,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   133,   134,     2,     3,
       4,    89,    17,   139,    39,     8,    26,   148,   149,    76,
     140,   113,    90,     2,     3,     4,    91,   154,   155,    92,
      28,    44,    29,   138,   145,    74,    47,    48,    49,    39,
      75,   146,   150,    79,   151,    50,    51,     1,     2,     3,
       4,    40,   110,    41,    42,    43,    44,    80,    28,    45,
      46,    47,    48,    49,    39,     1,     2,     3,     4,    81,
      50,    51,     1,     2,     3,     4,    40,    87,    41,    42,
      43,    44,    99,    28,   103,    46,    47,    48,    49,    39,
       1,     2,     3,     4,   100,    50,    51,   108,   101,   117,
     109,    40,   118,    41,    42,    43,    44,    29,    28,   106,
      46,    47,    48,    49,    39,   129,   130,   131,   132,   119,
      50,    51,   141,   142,   143,   152,    40,   153,    41,    42,
      43,    44,   135,    28,   137,    46,    47,    48,    49,    39,
     136,    37,   147,    38,    30,    50,    51,   105,    22,     0,
       0,    40,    39,    41,    42,    43,    44,     0,    28,     0,
      46,    47,    48,    49,    39,     0,     0,     0,     0,    44,
      50,    51,     0,    82,    47,    48,    49,    39,     0,     0,
      39,    44,     0,    50,    51,    46,    47,    48,    49,     0,
       0,     0,     0,    39,    77,    50,    51,    44,   120,    47,
      48,    49,    47,    48,    49,     0,     0,     0,    50,    51,
      44,    50,    51,     0,     0,    47,    48,    49,     0,     0,
       0,     0,     0,     0,    50,    51
};

static const yytype_int16 yycheck[] =
{
      28,    43,    44,    68,    39,     1,    23,    81,     0,    28,
       4,    20,     7,     8,    31,    22,    24,     0,    10,    15,
      55,    91,    92,     5,     6,    34,    20,    34,    24,    37,
      26,    24,    12,    13,    14,    77,    28,    79,    80,    67,
     105,    37,   116,    23,    86,    87,    74,    64,    67,    31,
      32,    12,    13,    14,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    97,    98,    12,    13,
      14,    26,    26,    21,     3,    67,    22,   142,   143,    23,
      28,    77,    37,    12,    13,    14,    27,   152,   153,    30,
      22,    20,    24,   110,    21,    20,    25,    26,    27,     3,
      24,    28,   144,    20,   146,    34,    35,    11,    12,    13,
      14,    15,   140,    17,    18,    19,    20,    20,    22,    23,
      24,    25,    26,    27,     3,    11,    12,    13,    14,    20,
      34,    35,    11,    12,    13,    14,    15,    33,    17,    18,
      19,    20,     9,    22,    23,    24,    25,    26,    27,     3,
      11,    12,    13,    14,    10,    34,    35,    21,    24,    24,
      21,    15,    21,    17,    18,    19,    20,    24,    22,    23,
      24,    25,    26,    27,     3,    93,    94,    95,    96,    34,
      34,    35,    21,    21,    21,    16,    15,    21,    17,    18,
      19,    20,    99,    22,    23,    24,    25,    26,    27,     3,
     100,    26,   140,    27,    18,    34,    35,    67,    10,    -1,
      -1,    15,     3,    17,    18,    19,    20,    -1,    22,    -1,
      24,    25,    26,    27,     3,    -1,    -1,    -1,    -1,    20,
      34,    35,    -1,    24,    25,    26,    27,     3,    -1,    -1,
       3,    20,    -1,    34,    35,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,     3,    20,    34,    35,    20,    21,    25,
      26,    27,    25,    26,    27,    -1,    -1,    -1,    34,    35,
      20,    34,    35,    -1,    -1,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    13,    14,    51,    52,    53,    54,    71,
      72,    73,    74,    53,    54,    22,    34,    26,    57,    59,
      24,     0,    73,    53,    55,    56,    22,    58,    22,    24,
      64,    20,    34,    60,    57,    23,    56,    55,    60,     3,
      15,    17,    18,    19,    20,    23,    24,    25,    26,    27,
      34,    35,    39,    40,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    63,    64,    65,    66,    67,
      68,    69,    70,    57,    20,    24,    23,    20,    42,    20,
      20,    20,    24,    50,    50,     4,    20,    33,    42,    26,
      37,    27,    30,     5,     6,    31,    32,     7,     8,     9,
      10,    24,    57,    23,    51,    66,    23,    63,    21,    21,
      52,    61,    62,    53,    50,    50,    67,    24,    21,    34,
      21,    41,    50,    50,    42,    42,    42,    44,    44,    45,
      45,    45,    45,    46,    46,    47,    48,    23,    57,    21,
      28,    21,    21,    21,    67,    21,    28,    62,    63,    63,
      50,    50,    16,    21,    63,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    39,    40,    40,    40,    40,    41,
      41,    42,    42,    42,    42,    43,    43,    43,    44,    44,
      44,    45,    45,    45,    46,    46,    46,    46,    46,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    54,    54,    54,    55,    55,
      56,    58,    57,    59,    57,    60,    60,    60,    60,    61,
      61,    62,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    72,    72,    73,    73,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     1,     1,     3,     4,     3,     1,
       3,     1,     2,     4,     2,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     3,     2,
       2,     1,     1,     1,     1,     5,     4,     2,     1,     2,
       3,     0,     3,     0,     2,     3,     1,     4,     3,     1,
       3,     2,     1,     1,     1,     1,     1,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       7,     2,     3,     1,     1,     2,     1,     1,     3
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
        case 2:
#line 38 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-1].attributs).code, NULL);
    (yyval.attributs).res = strdup((yyvsp[-1].attributs).res);

    (yyval.attributs).type= (yyvsp[-1].attributs).type;
}
#line 1382 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = (yyvsp[0].number);

    (yyval.attributs).type= basic_type(INT_T, "");
}
#line 1393 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 56 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].symbol)->nom);

    //$$.type = basic_type(VOID_T, "");
    (yyval.attributs).type = (yyvsp[0].symbol)->type;
}
#line 1405 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);

    (yyval.attributs).type= (yyvsp[0].attributs).type;
}
#line 1416 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 75 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[-2].attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "()", ";\n", NULL);

    /* on vérifie que le type de postfix_expression est une fonction qui prend void en entrée*/
    if(verif_type((yyvsp[-2].attributs).type, FCT_T)) /*on a bien une fonction*/
	{
	    arbre_t *depart= (yyvsp[-2].attributs).type->fils_gauche;
	    if (verif_type(depart, VOID_T)) /*l'espace de départ est bien VOID_T*/ /* VOID OU NULL??*/
		{(yyval.attributs).type = (yyvsp[-2].attributs).type->fils_droit;}
	    else
		{type_error_function_arguments(basic_type(VOID_T, ""), depart, yylineno, &(yyval.attributs));}
	}
    else
	{type_error(FCT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1438 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 96 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[-3].attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-3].attributs).code, (yyvsp[-1].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-3].attributs).res,"(", (yyvsp[-1].attributs).res, ")", ";\n", NULL);

    /* on vérifie que le type de postfix_expression est une fonction qui prend le bon type en entrée*/
    if(verif_type((yyvsp[-3].attributs).type, FCT_T)) /*on a bien une fonction*/
	{
	    arbre_t *depart= (yyvsp[-3].attributs).type->fils_gauche;
	    if (compare_arbre_t(depart, (yyvsp[-1].attributs).type)) /*l'espace de départ est bien du bon type*/
		{(yyval.attributs).type = (yyvsp[-3].attributs).type->fils_droit;}
	    else
		{type_error(VOID_T, depart, yylineno, &(yyval.attributs));}
	}
    else
	{ type_error(FCT_T, (yyvsp[-3].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1460 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 117 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[-2].attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "->", strdup((yyvsp[0].symbol)->nom), ";\n", NULL);
    (yyval.attributs).type= basic_type(VOID_T, ""); /*type du champs de structure....*/
}
#line 1471 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 128 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 1481 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).res = init_code((yyval.attributs).res);
    (yyval.attributs).res = concatener((yyval.attributs).res, (yyvsp[-2].attributs).res, ",", (yyvsp[0].attributs).res, NULL);

    (yyval.attributs).type= prod_type((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, ""); /*c'est un arbre "recursif a gauche"*/
}
#line 1494 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 149 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
}
#line 1504 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 157 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res)); /* stockage du resultat*/
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-1].attributs).code, (yyvsp[0].attributs).res,";\n", NULL);

    if(!(strcmp((yyvsp[-1].attributs).code, "-")))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type = basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}

    else if(!(strcmp((yyvsp[-1].attributs).code, "&")))
	{
	    if((yyvsp[0].attributs).type == NULL) {fprintf(stderr, "Type error line %d > Expected type: not NULL , Found_type: NULL \n", yylineno); (yyval.attributs).type=basic_type(ERROR_T, ""); }
	    else{(yyval.attributs).type = ptr_type((yyvsp[0].attributs).type, ""); }
	}

    else
	{
	    if(verif_type((yyvsp[0].attributs).type, PTR_T)) {(yyval.attributs).type= (yyvsp[0].attributs).type->fils_gauche;}
	    else {type_error(PTR_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}
}
#line 1532 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 183 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyval.attributs).res, " = sizeof(", (yyvsp[-1].attributs).code , ");\n", NULL);
    (yyval.attributs).type= basic_type(INT_T, "");
}
#line 1543 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 191 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyval.attributs).res, " = sizeof(",(yyvsp[0].attributs).res , ");\n", NULL);
    (yyval.attributs).type= basic_type(INT_T, "");
}
#line 1554 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 202 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = ajouter_code((yyval.attributs).code, "&");
}
#line 1563 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 208 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = ajouter_code((yyval.attributs).code, "*");
}
#line 1572 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 213 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = ajouter_code((yyval.attributs).code, "-");
}
#line 1581 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 222 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 1591 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 230 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "*", (yyvsp[0].attributs).res, ";\n", NULL);

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}

}
#line 1609 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 246 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "/", (yyvsp[0].attributs).res, ";\n", NULL);

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1626 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 263 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 1636 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 271 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "+", (yyvsp[0].attributs).res, ";\n",  NULL);


    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type = basic_type(INT_T, "");}
	    else if (verif_type((yyvsp[0].attributs).type, PTR_T)) {(yyval.attributs).type= (yyvsp[0].attributs).type;}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs)); /*int_t ou ptr_t*/}
	} 
    else if (verif_type((yyvsp[-2].attributs).type, PTR_T))
	{
	    if (verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= (yyvsp[-2].attributs).type;}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs)); /*int_t */}
	}
    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs)); /*int_t ou ptr_t*/}
}
#line 1660 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 293 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "-", (yyvsp[0].attributs).res, ";\n", NULL);

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type = basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	} 
    else if (verif_type((yyvsp[-2].attributs).type, PTR_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type = (yyvsp[-2].attributs).type;}
	    else if (verif_type((yyvsp[0].attributs).type, PTR_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs)); /*int_t ou ptr_t*/}
	}
    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs)); /*int_t ou ptr_t*/}
}
#line 1683 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 315 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 1693 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 322 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "<", (yyvsp[0].attributs).res, ";\n", NULL);

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1710 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 336 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, ">", (yyvsp[0].attributs).res, ";\n", NULL);

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1727 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 350 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "<=", (yyvsp[0].attributs).res, ";\n", NULL);

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1744 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 364 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, ">=", (yyvsp[0].attributs).res, ";\n", NULL);

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1761 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 380 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 1771 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 387 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "==", (yyvsp[0].attributs).res, ";\n", NULL);

    if(compare_arbre_t((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type)) {(yyval.attributs).type= basic_type(INT_T, "");}
    else { type_error_relational((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1784 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 397 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "!=", (yyvsp[0].attributs).res, ";\n",  NULL);

    if(compare_arbre_t((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type)) {(yyval.attributs).type= basic_type(INT_T, "");}
    else { type_error_relational((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs)); }
}
#line 1797 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 409 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 1807 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    char* label_suite;
    char* label_falsee;
    char* label_truee;
    label_suite= strdup(new_label(label_suite));
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));

    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, "if ", (yyvsp[-2].attributs).res, " goto ", label_suite,";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, "goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"\n",  label_suite, ":\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[0].attributs).code, "if ", (yyvsp[0].attributs).res, " goto ", label_truee,";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"\n",  label_truee,":\n", (yyval.attributs).res, "= 1;\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"\n", label_falsee,":\n", (yyval.attributs).res, "= 0;\n", NULL);

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1837 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 445 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 1847 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 452 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    char* label_suite;
    char* label_falsee;
    char* label_truee;
    label_suite= strdup(new_label(label_suite));
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
 
    (yyval.attributs).code = concatener((yyval.attributs).code,"", (yyvsp[-2].attributs).code, "if ", (yyvsp[-2].attributs).res, "goto ", label_truee,";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", "goto ", label_suite, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", label_suite, ":\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", (yyvsp[0].attributs).code, "if ", (yyvsp[0].attributs).res, "goto ", label_truee,";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", "goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", label_truee,":\n", (yyval.attributs).res, "= 1;\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", label_falsee,":\n", (yyval.attributs).res, "= 0;\n", NULL);

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1877 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 481 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
}
#line 1887 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 488 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup((yyvsp[-2].attributs).res);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyvsp[-2].attributs).res, " = ", (yyvsp[0].attributs).res, ";\n", NULL);

    if(compare_arbre_t((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type)) {
	(yyval.attributs).type= (yyvsp[-2].attributs).type;}
    else {type_error_affect((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
}
#line 1901 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 501 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code);
    (yyval.attributs).code=concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, " ", (yyvsp[-1].attributs).code, ";\n", NULL);
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
}
#line 1911 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 508 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup("not yet implemented: struct specifier");
    (yyval.attributs).type= basic_type(VOID_T, ""); /*type structure*/
}
#line 1920 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 517 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, "extern ", (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 1930 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 524 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
}
#line 1939 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 533 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup("void");
    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 1948 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 539 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup("int");
    (yyval.attributs).type= basic_type(INT_T, "");
}
#line 1957 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 545 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup("not yet implemented: struct_specifier");
    (yyval.attributs).type= basic_type(VOID_T, ""); /* type structure*/
}
#line 1966 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 568 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).type= ptr_type((yyvsp[-1].attributs).type, "");}
#line 1972 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 569 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, "*", (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
    (yyval.attributs).id = (yyvsp[0].attributs).id;
}
#line 1983 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 576 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).type= (yyvsp[0].attributs).type;}
#line 1989 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 577 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
    (yyval.attributs).id = (yyvsp[0].attributs).id;
}
#line 1999 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 586 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code); (yyval.attributs).code = concatener((yyval.attributs).code, "(", (yyvsp[-1].attributs).code, ")", NULL);
    (yyval.attributs).type= (yyvsp[-3].attributs).type;
    (yyval.attributs).id= (yyvsp[-1].attributs).id;
}
#line 2009 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 593 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].symbol)->nom);
    (yyvsp[0].symbol)->type= (yyvsp[-1].attributs).type;
    //if($1->type != NULL) {fprintf(stderr, "TYPE DE L'ID %s: %s\n",$1->nom, get_type_readable( ($1->type)->root) );}
    (yyval.attributs).type= (yyvsp[0].symbol)->type;
    (yyval.attributs).id= (yyvsp[0].symbol);
}
#line 2021 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 603 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code); (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-3].attributs).code, "(",(yyvsp[-1].attributs).code,")", NULL);
    //if($1.type != NULL) {fprintf(stderr, "TYPE DE DIRECT DECLA: %s\n", get_type_readable( ($1.type)->root) );}
    (yyval.attributs).type= fct_type((yyvsp[-1].attributs).type, (yyvsp[-3].attributs).type, "");
    ((yyvsp[-3].attributs).id)->type= (yyval.attributs).type;
}
#line 2032 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 611 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code); (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, "()", NULL);
    (yyval.attributs).type= fct_type(basic_type(VOID_T, ""), (yyvsp[-2].attributs).type, "");
    ((yyvsp[-2].attributs).id)->type= (yyval.attributs).type;
}
#line 2042 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 620 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 2051 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 626 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, "," , (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type= prod_type((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, ""); /*c'est un arbre "recursif a gauche"*/
}
#line 2061 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 635 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code); (yyval.attributs).code=concatener((yyval.attributs).code, (yyvsp[-1].attributs).code, " ", (yyvsp[0].attributs).code," ", NULL);
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
}
#line 2070 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 642 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).code = strdup((yyvsp[0].attributs).code); (yyval.attributs).type= (yyvsp[0].attributs).type;}
#line 2076 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 643 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).code = strdup((yyvsp[0].attributs).code); (yyval.attributs).type= (yyvsp[0].attributs).type;}
#line 2082 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 644 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).code = strdup((yyvsp[0].attributs).code); (yyval.attributs).type= (yyvsp[0].attributs).type;}
#line 2088 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 645 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).code = strdup((yyvsp[0].attributs).code); (yyval.attributs).type= (yyvsp[0].attributs).type;}
#line 2094 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 646 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).code = strdup((yyvsp[0].attributs).code); (yyval.attributs).type= (yyvsp[0].attributs).type;}
#line 2100 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 651 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code); (yyval.attributs).code= ajouter_code((yyval.attributs).code, "{ }\n");
    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 2109 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 658 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, "{\n", (yyvsp[-1].attributs).code ,"}\n", NULL);
    (yyval.attributs).type = (yyvsp[-1].attributs).type;
}
#line 2119 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 666 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, "{\n", (yyvsp[-1].attributs).code ,"}\n", NULL);
    (yyval.attributs).type = (yyvsp[-1].attributs).type;
}
#line 2129 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 674 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, "{\n", (yyvsp[-2].attributs).code, (yyvsp[-1].attributs).code ,"}\n", NULL);
    (yyval.attributs).type = (yyvsp[-1].attributs).type;
}
#line 2139 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 683 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[0].attributs).code); /*verifier qu'on a pas une erreur de type*/
    (yyval.attributs).type= (yyvsp[0].attributs).type;
}
#line 2148 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 689 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-1].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
}
#line 2158 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 698 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type=(yyvsp[0].attributs).type;
}
#line 2167 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 704 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code);
    (yyval.attributs).code=concatener((yyval.attributs).code, (yyvsp[-1].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
}
#line 2177 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 713 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code=ajouter_code((yyval.attributs).code, ";\n"); (yyval.attributs).res= NULL;
    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 2187 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 720 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[-1].attributs).code);
    (yyval.attributs).res= strdup((yyvsp[-1].attributs).res);
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
}
#line 2197 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 729 "structfe.y" /* yacc.c:1646  */
    {
    char* label_falsee;
    char* label_truee;
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if ", (yyvsp[-2].attributs).res, " goto ", label_truee, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, label_truee, ":\n", (yyvsp[0].attributs).code, label_falsee, ":\n", NULL);
    (yyval.attributs).res = NULL;

    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 2216 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 745 "structfe.y" /* yacc.c:1646  */
    {
    char* label_falsee;
    char* label_truee;
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-4].attributs).code,"\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if ", (yyvsp[-4].attributs).res, " goto ", label_truee, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, label_truee, ":\n", (yyvsp[-2].attributs).code, NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, label_falsee, ":\n", (yyvsp[0].attributs).code,  NULL);
    (yyval.attributs).res= NULL;

    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 2236 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 764 "structfe.y" /* yacc.c:1646  */
    {
    char* label_loop;
    char* label_end;
    label_loop  = strdup(new_label(label_loop));
    label_end= strdup(new_label(label_end));

    (yyval.attributs).code=init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, "\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if ", (yyvsp[-2].attributs).res , " goto ", label_loop, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_end, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, label_loop, ":\n", (yyvsp[0].attributs).code, "\n", (yyvsp[-2].attributs).code, "\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if ", (yyvsp[-2].attributs).res , " goto ", label_loop, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_end, ";\n",label_end,":\n", NULL);
    (yyval.attributs).res= NULL;

    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 2258 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 784 "structfe.y" /* yacc.c:1646  */
    {
    char* label_loop;
    char* label_end;
    label_loop  = strdup(new_label(label_loop));
    label_end= strdup(new_label(label_end));

    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-4].attributs).code, NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-3].attributs).code, NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if ", (yyvsp[-3].attributs).res , " goto ", label_loop, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_end, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, label_loop, ":\n", (yyvsp[0].attributs).code, "\n", (yyvsp[-2].attributs).code, "\n", (yyvsp[-3].attributs).code, NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if ", (yyvsp[-3].attributs).res , " goto ", label_loop, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_end, ";\n",label_end,":\n", NULL);
    (yyval.attributs).res= NULL;

    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 2281 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 806 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= ajouter_code((yyval.attributs).code, "return ;\n");
    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 2291 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 813 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[-1].attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, "return ", (yyvsp[-1].attributs).res," ;\n", NULL);
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
}
#line 2301 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 821 "structfe.y" /* yacc.c:1646  */
    {printf("%s",(yyvsp[0].attributs).code);}
#line 2307 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 825 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[0].attributs).code);
}
#line 2315 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 830 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-1].attributs).code, (yyvsp[0].attributs).code, NULL);
}
#line 2324 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 838 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 2333 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 843 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 2342 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 851 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, " " ,(yyvsp[-1].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type = (yyvsp[-1].attributs).type;
}
#line 2352 "structfe.tab.c" /* yacc.c:1646  */
    break;


#line 2356 "structfe.tab.c" /* yacc.c:1646  */
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
#line 858 "structfe.y" /* yacc.c:1906  */

	 
int main()
{
    init_pile();
    init_cpt_var();
    init_cpt_label();
    init_error();
    int c = yyparse();
    
    while(c)
	{
	    c=yyparse();
	}

    /*afficher_pile();*/

    printf("\n\n\nAccepted\n");
    exit(get_error_code());
}

int yyerror(char* s)
{
    fprintf(stderr, "line %d: %s\n", yylineno, s);
    exit(SYNTAXERROR);
}
