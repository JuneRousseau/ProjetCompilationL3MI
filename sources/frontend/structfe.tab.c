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
    char *name;

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
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

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
       0,    37,    37,    46,    56,    74,    84,   106,   133,   176,
     184,   200,   209,   236,   248,   263,   269,   274,   283,   292,
     312,   335,   344,   370,   397,   405,   423,   442,   460,   480,
     488,   513,   537,   545,   579,   587,   621,   629,   658,   675,
     685,   693,   703,   710,   717,   728,   727,   759,   759,   768,
     786,   794,   803,   815,   815,   826,   826,   837,   837,   846,
     891,   891,   900,   900,   910,   917,   927,   938,   945,   952,
     959,   966,   975,   978,   981,   989,   999,  1008,  1019,  1026,
    1036,  1043,  1054,  1062,  1072,  1089,  1120,  1142,  1167,  1175,
    1185,  1192,  1198,  1207,  1212,  1221
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
  "struct_specifier", "$@1", "$@2", "struct_declaration_list",
  "struct_declaration", "declarator", "@3", "@4", "direct_declarator",
  "@5", "$@6", "$@7", "parameter_list", "parameter_declaration",
  "statement", "entree", "sortie", "compound_statement",
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

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -63

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,     8,   -67,   -67,    -7,   -67,    13,   -67,    29,    80,
      90,   -67,   -67,   -67,   -67,   -67,    75,   -67,    84,    -1,
     -67,   -67,   -67,     8,   -67,    -1,    82,   -67,   129,   -67,
     -67,   -67,    78,    13,    12,   -67,     8,    78,   -67,   217,
      92,    94,   100,   192,   233,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,     9,    77,   233,    -9,    66,     5,    59,   128,
     135,   126,   -67,    13,   -67,   -67,   104,   154,   -67,   -67,
     -67,   -67,    13,   131,   134,   -67,   -67,    61,    65,   -67,
     233,   233,   204,   -67,   136,   138,   127,   220,   233,   -67,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   -67,   141,   -67,   -67,   -67,   154,   -67,   -67,
     145,    90,   146,   -67,   -67,   147,   149,   162,   204,   -67,
     -67,   -67,   -67,     2,   -67,   -67,   -67,   -67,   -67,    -9,
      -9,    66,    66,    66,    66,     5,     5,    59,   128,   -67,
     -67,    13,    48,   -67,   -67,   -67,   179,   179,   233,   -67,
     233,   -67,   -67,    90,   159,   -67,   163,   -67,   -67,   179,
     179,   -67,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    43,    42,     0,    94,    55,    41,    44,     0,
      90,    91,    93,    40,    44,    47,    49,    53,     0,     0,
      39,     1,    92,     0,    45,     0,    72,    38,     0,    95,
      57,    59,    56,    55,     0,    50,     0,    54,    74,     0,
       0,     0,     0,     0,     0,    82,    15,    16,    17,     4,
       3,     5,    11,    18,     0,    21,    24,    29,    32,    34,
      36,     0,    78,    55,    80,    67,     0,     0,    68,    69,
      70,    71,    55,    60,     0,    48,    51,     0,     0,    14,
       0,     0,     0,    88,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,    73,    79,    76,     0,    81,    75,
       0,     0,     0,    52,    46,     0,     0,     0,     0,    89,
       2,     8,     6,     0,     9,    37,    19,    20,    18,    23,
      22,    27,    28,    26,    25,    30,    31,    33,    35,    77,
      58,    55,     0,    64,    63,    13,     0,     0,     0,     7,
       0,    66,    61,     0,    84,    86,     0,    10,    65,     0,
       0,    85,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -36,   -67,   -21,    39,   -12,    62,
      85,   -67,   -37,   -20,   -28,    11,     4,   -67,   -67,   151,
     -29,   -32,   -67,   -67,   160,   -67,   -67,   -67,   -67,    37,
     -65,   -67,   -58,   173,   -67,   142,   -66,   -67,   -67,   -67,
     -67,   -67,   182,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    51,    52,   123,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     5,     6,     7,    14,    36,    23,    34,
      35,    18,    25,    19,    32,    72,   111,   112,   142,   143,
      64,    28,   106,    65,    66,    67,    68,    69,    70,    71,
       9,    10,    11,    12
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    74,   108,    79,     8,    76,    84,    85,    62,   109,
      94,    95,    13,    86,     8,    15,   118,    90,    89,    30,
       2,     3,     4,   149,     2,     3,     4,    16,    91,    87,
     150,   103,     8,    31,    33,    75,    96,    97,    63,    17,
     110,    85,   108,   116,   117,    33,   105,    33,    76,   139,
     124,   125,   148,    20,   126,   127,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,    98,    99,    39,   152,
       8,   129,   130,     2,     3,     4,   153,     2,     3,     4,
      21,   154,   155,   141,   114,    44,   135,   136,    33,   115,
      46,    47,    48,    92,   161,   162,    93,    24,    73,    49,
      50,     1,     2,     3,     4,    38,    26,    39,    27,   151,
      88,   156,    80,   157,    81,     1,     2,     3,     4,    40,
      82,    41,    42,    43,    44,   141,    26,   104,    45,    46,
      47,    48,    39,   131,   132,   133,   134,   100,    49,    50,
       1,     2,     3,     4,    40,   101,    41,    42,    43,    44,
     102,    26,   -62,    45,    46,    47,    48,    39,   113,   120,
     119,   121,   137,    49,    50,    27,   140,   144,   145,    40,
     146,    41,    42,    43,    44,   159,    26,   104,    45,    46,
      47,    48,    39,   147,   160,    37,   138,    77,    49,    50,
     158,    29,    22,     0,    40,    39,    41,    42,    43,    44,
       0,    26,     0,    45,    46,    47,    48,    39,   107,     0,
       0,     0,    44,    49,    50,     0,    83,    46,    47,    48,
      39,     0,     0,    39,    44,     0,    49,    50,    45,    46,
      47,    48,     0,     0,     0,     0,    39,    78,    49,    50,
      44,   122,    46,    47,    48,    46,    47,    48,     0,     0,
       0,    49,    50,    44,    49,    50,     0,     0,    46,    47,
      48,     0,     0,     0,     0,     0,     0,    49,    50
};

static const yytype_int16 yycheck[] =
{
      28,    33,    67,    39,     0,    34,    43,    44,    28,    67,
       5,     6,     1,     4,    10,    22,    82,    26,    54,    20,
      12,    13,    14,    21,    12,    13,    14,    34,    37,    20,
      28,    63,    28,    34,    23,    23,    31,    32,    66,    26,
      72,    78,   107,    80,    81,    34,    66,    36,    77,   107,
      87,    88,   118,    24,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,     7,     8,     3,    21,
      66,    92,    93,    12,    13,    14,    28,    12,    13,    14,
       0,   146,   147,   111,    23,    20,    98,    99,    77,    78,
      25,    26,    27,    27,   159,   160,    30,    22,    20,    34,
      35,    11,    12,    13,    14,    23,    22,     3,    24,   141,
      33,   148,    20,   150,    20,    11,    12,    13,    14,    15,
      20,    17,    18,    19,    20,   153,    22,    23,    24,    25,
      26,    27,     3,    94,    95,    96,    97,     9,    34,    35,
      11,    12,    13,    14,    15,    10,    17,    18,    19,    20,
      24,    22,    21,    24,    25,    26,    27,     3,    24,    21,
      24,    34,   100,    34,    35,    24,    21,    21,    21,    15,
      21,    17,    18,    19,    20,    16,    22,    23,    24,    25,
      26,    27,     3,    21,    21,    25,   101,    36,    34,    35,
     153,    18,    10,    -1,    15,     3,    17,    18,    19,    20,
      -1,    22,    -1,    24,    25,    26,    27,     3,    66,    -1,
      -1,    -1,    20,    34,    35,    -1,    24,    25,    26,    27,
       3,    -1,    -1,     3,    20,    -1,    34,    35,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,     3,    20,    34,    35,
      20,    21,    25,    26,    27,    25,    26,    27,    -1,    -1,
      -1,    34,    35,    20,    34,    35,    -1,    -1,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    13,    14,    51,    52,    53,    54,    78,
      79,    80,    81,    53,    54,    22,    34,    26,    59,    61,
      24,     0,    80,    56,    22,    60,    22,    24,    69,    71,
      20,    34,    62,    53,    57,    58,    55,    62,    23,     3,
      15,    17,    18,    19,    20,    24,    25,    26,    27,    34,
      35,    39,    40,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    68,    71,    72,    73,    74,    75,
      76,    77,    63,    20,    59,    23,    58,    57,    20,    42,
      20,    20,    20,    24,    50,    50,     4,    20,    33,    42,
      26,    37,    27,    30,     5,     6,    31,    32,     7,     8,
       9,    10,    24,    59,    23,    51,    70,    73,    68,    70,
      59,    64,    65,    24,    23,    53,    50,    50,    74,    24,
      21,    34,    21,    41,    50,    50,    42,    42,    42,    44,
      44,    45,    45,    45,    45,    46,    46,    47,    48,    70,
      21,    52,    66,    67,    21,    21,    21,    21,    74,    21,
      28,    59,    21,    28,    68,    68,    50,    50,    67,    16,
      21,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    39,    40,    40,    40,    40,    41,
      41,    42,    42,    42,    42,    43,    43,    43,    44,    44,
      44,    45,    45,    45,    46,    46,    46,    46,    46,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    53,    55,    54,    56,    54,    54,
      57,    57,    58,    60,    59,    61,    59,    63,    62,    62,
      64,    62,    65,    62,    66,    66,    67,    68,    68,    68,
      68,    68,    69,    70,    71,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    79,    79,    80,    80,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     1,     1,     3,     4,     3,     1,
       3,     1,     2,     4,     2,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     3,     2,
       2,     1,     1,     1,     1,     0,     6,     0,     5,     2,
       1,     2,     3,     0,     3,     0,     2,     0,     4,     1,
       0,     5,     0,     4,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     7,     2,     3,
       1,     1,     2,     1,     1,     3
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
    (yyval.attributs).declarations= strdup((yyvsp[-1].attributs).declarations);
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
}
#line 1387 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].number));
    (yyval.attributs).declarations=strdup("");

    (yyval.attributs).type= basic_type(INT_T, "");
}
#line 1399 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "structfe.y" /* yacc.c:1646  */
    {
    //fprintf(stderr, "\nON AFFICHE LA TABLE DES SYMBOLE AU MOMENT OU ON VEUT IDENTIFIER %s:\n", $1);
    //afficher_pile();
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].name));
    symbole_t *s= find((yyvsp[0].name));
    if(s)
	{(yyval.attributs).type=s->type;}
    else
	{
	    fprintf(stderr, "line %d: l'identifiant %s n'a jamais ete declare\n", yylineno, (yyvsp[0].name));
	    (yyval.attributs).type= basic_type(ERROR_T, strdup((yyvsp[0].name)));
	}
    (yyval.attributs).declarations=strdup("");
}
#line 1419 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 75 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);

    (yyval.attributs).type= (yyvsp[0].attributs).type;
}
#line 1431 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "structfe.y" /* yacc.c:1646  */
    {
/* on vérifie que le type de postfix_expression est une fonction qui prend void en entrée*/
    if(verif_type((yyvsp[-2].attributs).type, FCT_T)) /*on a bien une fonction*/
	{
	    arbre_t *depart= (yyvsp[-2].attributs).type->fils_gauche;
	    if (verif_type(depart, VOID_T)) /*l'espace de départ est bien VOID_T*/ /* VOID OU NULL??*/
		{(yyval.attributs).type = (yyvsp[-2].attributs).type->fils_droit;}
	    else
		{type_error_function_arguments(depart, basic_type(VOID_T, ""), yylineno, &(yyval.attributs));}
	}
    else
	{type_error(FCT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}

    (yyval.attributs).code = strdup((yyvsp[-2].attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "()", ";\n", NULL);
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, (yyval.attributs).type, (yyvsp[-2].attributs).declarations);
}
#line 1454 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 107 "structfe.y" /* yacc.c:1646  */
    {

    /* on vérifie que le type de postfix_expression est une fonction qui prend le bon type en entrée*/
    if(verif_type((yyvsp[-3].attributs).type, FCT_T)) /*on a bien une fonction*/
	{
	    arbre_t *depart= (yyvsp[-3].attributs).type->fils_gauche;
	    if (compare_arbre_t(depart, (yyvsp[-1].attributs).type)) /*l'espace de départ est bien du bon type*/
		{(yyval.attributs).type = (yyvsp[-3].attributs).type->fils_droit;}
	    else
		{type_error_function_arguments(depart, (yyvsp[-1].attributs).type, yylineno, &(yyval.attributs));}
	}
    else
	{ type_error(FCT_T, (yyvsp[-3].attributs).type, yylineno, &(yyval.attributs));}

    (yyval.attributs).code = strdup((yyvsp[-3].attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-3].attributs).code, (yyvsp[-1].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-3].attributs).res,"(", (yyvsp[-1].attributs).res, ")", ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, (yyvsp[-3].attributs).declarations, (yyvsp[-1].attributs).declarations, NULL);
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, (yyval.attributs).type, tmp_decla);
}
#line 1482 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 134 "structfe.y" /* yacc.c:1646  */
    {
    int offset;
    if(verif_type((yyvsp[-2].attributs).type, PTR_T))
	{
	    if(verif_type((yyvsp[-2].attributs).type->fils_gauche, STRUCT_T)) {offset= get_offset_member((yyvsp[-2].attributs).type->fils_gauche, (yyvsp[0].name));}
	    else
		{
		    fprintf(stderr, "Type error line %d: expected_type: PTR_T( STRUCT_T ) found_type: %s\n", yylineno, draw_type_expr((yyvsp[-2].attributs).type));
		    offset= -2;
		    
		}
	}
    else
	{
	    fprintf(stderr, "Type error line %d: expected_type: PTR_T( STRUCT_T ) found_type: %s\n", yylineno, draw_type_expr((yyvsp[-2].attributs).type));
	    offset= -2;
	}

    if(offset < 0) /*il y a une erreur*/
	{
	    if (offset == -1) {fprintf(stderr, "Type error line %d: The structure %s doesn't have the following member %s\n", yylineno, draw_type_expr((yyvsp[-2].attributs).type), (yyvsp[0].name));}
	    (yyval.attributs).type= basic_type(ERROR_T, "");
	}
    else
	{
	    arbre_t *type= get_type_member((yyvsp[-2].attributs).type->fils_gauche, (yyvsp[0].name));
	    (yyval.attributs).type= type;
	}
    //fprintf(stderr, "Le type de la structure est: %s\n", draw_type_expr($1.type));    
    //fprintf(stderr, "Le type trouvé pour le -> est: %s\n", draw_type_expr($$.type));    
    (yyval.attributs).code = strdup((yyvsp[-2].attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    char* offset_c;
    offset_c= malloc(0);
    sprintf(offset_c, "%d", offset);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyval.attributs).res, " = ",(yyvsp[-2].attributs).res, "+", offset_c, ";\n", NULL);;
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, ptr_type(basic_type(VOID_T,""),""), (yyvsp[-2].attributs).declarations);
}
#line 1525 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 177 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 1536 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 185 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).res = init_code((yyval.attributs).res);
    (yyval.attributs).res = concatener((yyval.attributs).res, (yyvsp[-2].attributs).res, ",", (yyvsp[0].attributs).res, NULL);
    (yyval.attributs).declarations= init_code((yyval.attributs).declarations);
    (yyval.attributs).declarations= concatener((yyval.attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);

    (yyval.attributs).type= prod_type((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, ""); /*c'est un arbre "recursif a gauche"*/
}
#line 1551 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 201 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 1562 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 210 "structfe.y" /* yacc.c:1646  */
    {
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

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res)); /* stockage du resultat*/
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-1].attributs).code, (yyvsp[0].attributs).res,";\n", NULL);
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, (yyval.attributs).type, (yyvsp[0].attributs).declarations);
}
#line 1591 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 237 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    //$$.res = strdup(new_var($$.res));
    //$$.code = concatener($$.code, $$.res, " = (", $3.code , ");\n", NULL);
    (yyval.attributs).res=init_code((yyval.attributs).res);
    sprintf((yyval.attributs).res, "%d", sizeof_type((yyvsp[-1].attributs).type));
    (yyval.attributs).type= basic_type(INT_T, "");
    (yyval.attributs).declarations = strdup("");
    //$$.declarations= add_declaration($$.res, $$.type, strdup(""));
}
#line 1606 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 249 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    //$$.res = strdup(new_var($$.res));
    //$$.code = concatener($$.code, $$.res, " = sizeof(",$2.res , ");\n", NULL);
    (yyval.attributs).res=init_code((yyval.attributs).res);
    sprintf((yyval.attributs).res, "%d", sizeof_type((yyvsp[0].attributs).type));
    (yyval.attributs).type= basic_type(INT_T, "");
    (yyval.attributs).declarations = strdup("");
    //$$.declarations= add_declaration($$.res, $$.type, $2.declarations);
}
#line 1621 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 264 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = ajouter_code((yyval.attributs).code, "&");
}
#line 1630 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 270 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = ajouter_code((yyval.attributs).code, "*");
}
#line 1639 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 275 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = ajouter_code((yyval.attributs).code, "-");
}
#line 1648 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 284 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 1659 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 293 "structfe.y" /* yacc.c:1646  */
    {
    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "*", (yyvsp[0].attributs).res, ";\n", NULL);
    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, (yyval.attributs).type, tmp_decla);

}
#line 1681 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 313 "structfe.y" /* yacc.c:1646  */
    {

    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "/", (yyvsp[0].attributs).res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, (yyval.attributs).type, tmp_decla);
}
#line 1704 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 336 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 1715 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 345 "structfe.y" /* yacc.c:1646  */
    {
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

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "+", (yyvsp[0].attributs).res, ";\n",  NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, (yyval.attributs).type, tmp_decla);
}
#line 1743 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 371 "structfe.y" /* yacc.c:1646  */
    {
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

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyval.attributs).res, " = ", (yyvsp[-2].attributs).res, "-", (yyvsp[0].attributs).res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, (yyval.attributs).type, tmp_decla);
}
#line 1771 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 398 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 1782 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 406 "structfe.y" /* yacc.c:1646  */
    {
    if(verif_type((yyvsp[-2].attributs).type, INT_T) || verif_type((yyvsp[-2].attributs).type, PTR_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)  || verif_type((yyvsp[0].attributs).type, PTR_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).res= init_code((yyval.attributs).res);
    (yyval.attributs).res= concatener((yyval.attributs).res, (yyvsp[-2].attributs).res, "<", (yyvsp[0].attributs).res, NULL);

    (yyval.attributs).declarations= init_code((yyval.attributs).declarations);
    (yyval.attributs).declarations= concatener((yyval.attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
}
#line 1803 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 424 "structfe.y" /* yacc.c:1646  */
    {
    if(verif_type((yyvsp[-2].attributs).type, INT_T) || verif_type((yyvsp[-2].attributs).type, PTR_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)  || verif_type((yyvsp[0].attributs).type, PTR_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}


    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).res= init_code((yyval.attributs).res);
    (yyval.attributs).res= concatener((yyval.attributs).res, (yyvsp[-2].attributs).res, ">", (yyvsp[0].attributs).res, NULL);

    (yyval.attributs).declarations= init_code((yyval.attributs).declarations);
    (yyval.attributs).declarations= concatener((yyval.attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
}
#line 1825 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 443 "structfe.y" /* yacc.c:1646  */
    {
    if(verif_type((yyvsp[-2].attributs).type, INT_T) || verif_type((yyvsp[-2].attributs).type, PTR_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)  || verif_type((yyvsp[0].attributs).type, PTR_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).res= init_code((yyval.attributs).res);
    (yyval.attributs).res= concatener((yyval.attributs).res, (yyvsp[-2].attributs).res, "<=", (yyvsp[0].attributs).res, NULL);

    (yyval.attributs).declarations= init_code((yyval.attributs).declarations);
    (yyval.attributs).declarations= concatener((yyval.attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
}
#line 1846 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 461 "structfe.y" /* yacc.c:1646  */
    {
    if(verif_type((yyvsp[-2].attributs).type, INT_T) || verif_type((yyvsp[-2].attributs).type, PTR_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T) || verif_type((yyvsp[0].attributs).type, PTR_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).res= init_code((yyval.attributs).res);
    (yyval.attributs).res= concatener((yyval.attributs).res, (yyvsp[-2].attributs).res, ">=", (yyvsp[0].attributs).res, NULL);

    (yyval.attributs).declarations= init_code((yyval.attributs).declarations);
    (yyval.attributs).declarations= concatener((yyval.attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
}
#line 1867 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 481 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 1878 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 489 "structfe.y" /* yacc.c:1646  */
    {
    //$$.res = init_code($$.res);
    //$$.res = concatener($$.res, $$.res, " = ", $1.res, "==", $3.res);

    if(compare_arbre_t((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type)) {(yyval.attributs).type= basic_type(INT_T, "");}
    else
	{
	    if(verif_type((yyvsp[-2].attributs).type, INT_T) || verif_type((yyvsp[-2].attributs).type, PTR_T))
		{
		    if(verif_type((yyvsp[0].attributs).type, INT_T)  || verif_type((yyvsp[0].attributs).type, PTR_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
		    else {type_error_relational((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
		}
	    else {type_error_relational((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).res= init_code((yyval.attributs).res);
    (yyval.attributs).res= concatener((yyval.attributs).res, (yyvsp[-2].attributs).res, "==", (yyvsp[0].attributs).res, NULL);

    (yyval.attributs).declarations= init_code((yyval.attributs).declarations);
    (yyval.attributs).declarations= concatener((yyval.attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
}
#line 1906 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 514 "structfe.y" /* yacc.c:1646  */
    {
    if(compare_arbre_t((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type)) {(yyval.attributs).type= basic_type(INT_T, "");}
    else
	{
	    if(verif_type((yyvsp[-2].attributs).type, INT_T) || verif_type((yyvsp[-2].attributs).type, PTR_T))
		{
		    if(verif_type((yyvsp[0].attributs).type, INT_T)  || verif_type((yyvsp[0].attributs).type, PTR_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
		    else {type_error_relational((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
		}
	    else {type_error_relational((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
	}

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).res= init_code((yyval.attributs).res);
    (yyval.attributs).res= concatener((yyval.attributs).res, (yyvsp[-2].attributs).res, "!=", (yyvsp[0].attributs).res, NULL);

    (yyval.attributs).declarations= init_code((yyval.attributs).declarations);
    (yyval.attributs).declarations= concatener((yyval.attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
}
#line 1931 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 538 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 1942 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 546 "structfe.y" /* yacc.c:1646  */
    {
    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    char* label_suite;
    char* label_falsee;
    char* label_truee;
    label_suite= strdup(new_label(label_suite));
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));

    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, "if (", (yyvsp[-2].attributs).res, ") goto ", label_suite,";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, "goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"\n",  label_suite, ":\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[0].attributs).code, "if (", (yyvsp[0].attributs).res, ") goto ", label_truee,";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"\n",  label_truee,":\n", (yyval.attributs).res, "= 1;\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"\n", label_falsee,":\n", (yyval.attributs).res, "= 0;\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, (yyval.attributs).type, tmp_decla);
}
#line 1977 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 580 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 1988 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 588 "structfe.y" /* yacc.c:1646  */
    {
    if(verif_type((yyvsp[-2].attributs).type, INT_T))
	{
	    if(verif_type((yyvsp[0].attributs).type, INT_T)) {(yyval.attributs).type= basic_type(INT_T, "");}
	    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}
	}
    else {type_error(INT_T, (yyvsp[-2].attributs).type, yylineno, &(yyval.attributs));}

    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).res = strdup(new_var((yyval.attributs).res));
    char* label_suite;
    char* label_falsee;
    char* label_truee;
    label_suite= strdup(new_label(label_suite));
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
 
    (yyval.attributs).code = concatener((yyval.attributs).code,"", (yyvsp[-2].attributs).code, "if (", (yyvsp[-2].attributs).res, ") goto ", label_truee,";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", "goto ", label_suite, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", label_suite, ":\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", (yyvsp[0].attributs).code, "if (", (yyvsp[0].attributs).res, ") goto ", label_truee,";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", "goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", label_truee,":\n", (yyval.attributs).res, "= 1;\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code,"", label_falsee,":\n", (yyval.attributs).res, "= 0;\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
    (yyval.attributs).declarations= add_declaration((yyval.attributs).res, (yyval.attributs).type, tmp_decla);
}
#line 2023 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 622 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).res = strdup((yyvsp[0].attributs).res);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 2034 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 630 "structfe.y" /* yacc.c:1646  */
    {
    //fprintf(stderr, "Type de unary expression: %s\n", draw_type_expr($1.type));
    //fprintf(stderr, "Type de expression: %s\n", draw_type_expr($3.type));
    if(compare_arbre_t((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type)) {
	(yyval.attributs).type= (yyvsp[-2].attributs).type;}
    else {
	if(verif_type((yyvsp[-2].attributs).type, PTR_T) && verif_type((yyvsp[0].attributs).type, INT_T)){(yyval.attributs).type= (yyvsp[-2].attributs).type;}
	else {type_error_affect((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
    }

	(yyval.attributs).code = init_code((yyval.attributs).code);
	(yyval.attributs).res = strdup((yyvsp[-2].attributs).res);
	
	if(verif_type((yyvsp[-2].attributs).type, PTR_T) && !(verif_type((yyvsp[0].attributs).type, PTR_T)))
	    {
	(yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, "*", (yyvsp[-2].attributs).res, " = ", (yyvsp[0].attributs).res, ";\n", NULL);
    }
	else
	    {
	(yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, (yyvsp[0].attributs).code, (yyvsp[-2].attributs).res, " = ", (yyvsp[0].attributs).res, ";\n", NULL);
    }
    
	(yyval.attributs).declarations= init_code((yyval.attributs).declarations);
	(yyval.attributs).declarations= concatener((yyval.attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
    }
#line 2064 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 659 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code);
    if(verif_type((yyvsp[-1].attributs).type, INT_T))
	{(yyval.attributs).code=concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, " ", (yyvsp[-1].attributs).code, ";\n", NULL);}
    else {(yyval.attributs).code=concatener((yyval.attributs).code, "void ", (yyvsp[-1].attributs).code, ";\n", NULL);}
    
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
    //$2.id->type= $2.type;
    (yyval.attributs).declarations=strdup("");
    //fprintf(stderr, "\nON AFFICHE LA TABLE DES SYMBOLE APRES AVOIR DEFINI(avant pop) %s:\n", $2.id->nom);
    //afficher_pile();
    if((yyval.attributs).type->root == FCT_T){pop();} /*il faudra verifier si on a un pointeur sur fonction*/
    //fprintf(stderr, "\nON AFFICHE LA TABLE DES SYMBOLE APRES AVOIR DEFINI(apres pop)  %s:\n", $2.id->nom);
    //afficher_pile();
}
#line 2084 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 676 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup("");
    (yyval.attributs).type= (yyvsp[-1].attributs).type; /*type structure*/
    (yyval.attributs).declarations=strdup("");
}
#line 2094 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 686 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, "extern ", (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations=strdup("");
}
#line 2105 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 694 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations=strdup("");
}
#line 2115 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 704 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup("void");
    (yyval.attributs).type= basic_type(VOID_T, "");
    (yyval.attributs).declarations=strdup("");
}
#line 2125 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 711 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup("int");
    (yyval.attributs).type= basic_type(INT_T, "");
    (yyval.attributs).declarations=strdup("");
}
#line 2135 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 718 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations=strdup("");
}
#line 2145 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 728 "structfe.y" /* yacc.c:1646  */
    {
    char *id=(yyvsp[-1].name);
    symbole_t *s=rechercher(top(), id);
    if(s)
	{
	    fprintf(stderr, "La structure %s est deja definie\n", id);
	    s->type=basic_type(ERROR_T, "");
	}
    else
	{ symbole_t *n= ajouter(top(), strdup(id)); n->type= struc_type(NULL, id); }
    push(nouvelle_table());
}
#line 2162 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 740 "structfe.y" /* yacc.c:1646  */
    {
    pop();
    symbole_t *s=rechercher(top(), (yyvsp[-4].name));
    if(s)
	{
	    if(verif_type(s->type, STRUCT_T))
		{
	(s->type)= struc_type((yyvsp[-1].attributs).type, strdup((yyvsp[-4].name)));
		    //afficher_pile();
		}
	    (yyval.attributs).type= s->type;
	}
    else {(yyval.attributs).type= basic_type(ERROR_T, strdup((yyvsp[-4].name)));}

    (yyval.attributs).code=strdup("");
    (yyval.attributs).declarations=strdup("");
}
#line 2184 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 759 "structfe.y" /* yacc.c:1646  */
    {push(nouvelle_table());}
#line 2190 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 760 "structfe.y" /* yacc.c:1646  */
    {
    pop();
    (yyval.attributs).code=strdup("");
    (yyval.attributs).type=struc_type((yyvsp[-1].attributs).type, "");
    (yyval.attributs).declarations=strdup("");
}
#line 2201 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 769 "structfe.y" /* yacc.c:1646  */
    {
//afficher_pile();
    (yyval.attributs).code= strdup("void");
    symbole_t *s_id= find((yyvsp[0].name));
    if(s_id)
	{
	    (yyval.attributs).type=s_id->type;
	}
    else
	{
	    fprintf(stderr, "La structure %s n'a jamais ete definie\n", (yyvsp[0].name));
	    (yyval.attributs).type=basic_type(ERROR_T, "");
	}
}
#line 2220 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 787 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup("");
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations=strdup("");
}
#line 2230 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 795 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup("");
    (yyval.attributs).type= prod_type((yyvsp[-1].attributs).type, (yyvsp[0].attributs).type, ""); /*c'est un arbre "recursif a gauche"*/
    (yyval.attributs).declarations=strdup("");
}
#line 2240 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 804 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=strdup("");
    (yyvsp[-1].attributs).type->name= strdup((yyvsp[-1].attributs).id->nom); //modif ici
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
    //$2.id->type= $2.type;
    (yyval.attributs).declarations=strdup("");
    if((yyval.attributs).type->root == FCT_T){pop();} /*il faudra verifier si on a un pointeur sur fonction*/
}
#line 2253 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 815 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).type= ptr_type((yyvsp[-1].attributs).type, "");}
#line 2259 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 816 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, "*", (yyvsp[0].attributs).code, NULL);
    //$$.type= ptr_type($3.type, "");
    (yyval.attributs).id = (yyvsp[0].attributs).id;
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).id->type= (yyval.attributs).type;
    (yyval.attributs).declarations=strdup("");
}
#line 2273 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 826 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).type= (yyvsp[0].attributs).type;}
#line 2279 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 827 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).id = (yyvsp[0].attributs).id;
    (yyval.attributs).id->type= (yyval.attributs).type;
    (yyval.attributs).declarations=strdup("");
}
#line 2291 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 837 "structfe.y" /* yacc.c:1646  */
    {(yyval.attributs).type= (yyvsp[-1].attributs).type;}
#line 2297 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 838 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code); (yyval.attributs).code = concatener((yyval.attributs).code, "(", (yyvsp[-1].attributs).code, ")", NULL);
    (yyval.attributs).type= (yyvsp[-4].attributs).type;
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
    (yyval.attributs).id= (yyvsp[-1].attributs).id;
    (yyval.attributs).declarations=strdup("");
}
#line 2309 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 847 "structfe.y" /* yacc.c:1646  */
    {
    symbole_t *s;
    s= rechercher(top(), (yyvsp[0].name));
    if(s)
	{
	    fprintf(stderr, "Identifiant \"%s\" deja declare et du type %s", (yyvsp[0].name), draw_type_expr(s->type));
	    (yyval.attributs).type=basic_type(ERROR_T, strdup((yyvsp[0].name)));
	}
    else
	{
	    if(top()->suivant)
		{
		    s= rechercher(top()->suivant, (yyvsp[0].name));
		    if(s)
			{ if(s->is_arg)
				{
				    fprintf(stderr, "L'identifiant %s est un argument de fonction du type %s", (yyvsp[0].name), draw_type_expr(s->type));  
				    (yyval.attributs).type=basic_type(ERROR_T, strdup((yyvsp[0].name)));
				}
			    else
				{(yyval.attributs).type= (yyvsp[-1].attributs).type;
				    s= ajouter(top(), (yyvsp[0].name));}

			}
		    else
			{
			    (yyval.attributs).type= (yyvsp[-1].attributs).type;
			    s= ajouter(top(), (yyvsp[0].name));
			}
		    
		}
	    else
		{
		    (yyval.attributs).type= (yyvsp[-1].attributs).type;
		    s= ajouter(top(), (yyvsp[0].name));
		}
	}
    (yyval.attributs).id=s;
    (yyval.attributs).id->is_arg=0;
    (yyval.attributs).code = strdup((yyvsp[0].name));
    (yyval.attributs).declarations=strdup("");
}
#line 2356 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 891 "structfe.y" /* yacc.c:1646  */
    {push(nouvelle_table());}
#line 2362 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 892 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code); (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-4].attributs).code, "(",(yyvsp[-1].attributs).code,")", NULL);
    (yyval.attributs).type= fct_type((yyvsp[-1].attributs).type, (yyvsp[-4].attributs).type, "");
    (yyval.attributs).id= (yyvsp[-4].attributs).id;
    (yyval.attributs).declarations=strdup("");
    //afficher_pile();
}
#line 2374 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 900 "structfe.y" /* yacc.c:1646  */
    {push(nouvelle_table());}
#line 2380 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 901 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code); (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-3].attributs).code, "()", NULL);
    (yyval.attributs).type= fct_type(basic_type(VOID_T, ""), (yyvsp[-3].attributs).type, "");
    (yyval.attributs).id= (yyvsp[-3].attributs).id;
    (yyval.attributs).declarations=strdup("");
}
#line 2391 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 911 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
    (yyval.attributs).declarations=strdup("");
}
#line 2401 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 918 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, "," , (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type= prod_type((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type, ""); /*c'est un arbre "recursif a gauche"*/
    (yyval.attributs).declarations=strdup("");
}
#line 2412 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 928 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code); (yyval.attributs).code=concatener((yyval.attributs).code, (yyvsp[-1].attributs).code, " ", (yyvsp[0].attributs).code," ", NULL);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations=strdup("");
    (yyvsp[0].attributs).id->is_arg=1;
    if((yyval.attributs).type->root == FCT_T){pop();} /*il faudra verifier si on a un pointeur sur fonction*/
}
#line 2424 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 939 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 2434 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 946 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 2444 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 953 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 2454 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 960 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 2464 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 967 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 2474 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 975 "structfe.y" /* yacc.c:1646  */
    {push(nouvelle_table());}
#line 2480 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 978 "structfe.y" /* yacc.c:1646  */
    {pop();}
#line 2486 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 982 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code); (yyval.attributs).code= ajouter_code((yyval.attributs).code, "{ }\n");
    (yyval.attributs).type= basic_type(VOID_T, "");
    (yyval.attributs).declarations= strdup("");
}
#line 2496 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 990 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, "{\n", (yyvsp[-1].attributs).declarations, (yyvsp[-1].attributs).code ,"}\n", NULL);
    (yyval.attributs).type = (yyvsp[-1].attributs).type;
    (yyval.attributs).declarations= strdup("");
    //    $$.declarations= strdup($2.declarations);
}
#line 2508 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1000 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, "{\n", (yyvsp[-1].attributs).code ,"}\n", NULL);
    (yyval.attributs).type = (yyvsp[-1].attributs).type;
    (yyval.attributs).declarations= strdup("");
}
#line 2519 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1009 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, "{\n", (yyvsp[-2].attributs).code, (yyvsp[-1].attributs).declarations, (yyvsp[-1].attributs).code ,"}\n", NULL);
    (yyval.attributs).type = (yyvsp[-1].attributs).type;
    (yyval.attributs).declarations= strdup("");
    //$$.declarations= strdup($3.declarations);
}
#line 2531 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1020 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[0].attributs).code); /*verifier qu'on a pas une erreur de type*/
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations=strdup("");
}
#line 2541 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1027 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-1].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations=strdup("");
}
#line 2552 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1037 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type=(yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[0].attributs).declarations);
}
#line 2562 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1044 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code=init_code((yyval.attributs).code);
    (yyval.attributs).code=concatener((yyval.attributs).code, (yyvsp[-1].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= init_code((yyval.attributs).declarations);
    (yyval.attributs).declarations= concatener((yyval.attributs).declarations, (yyvsp[-1].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
}
#line 2574 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1055 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code=ajouter_code((yyval.attributs).code, ";\n"); (yyval.attributs).res= NULL;
    (yyval.attributs).type= basic_type(VOID_T, "");
    (yyval.attributs).declarations= strdup("\n");
}
#line 2585 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1063 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[-1].attributs).code);
    (yyval.attributs).res= strdup((yyvsp[-1].attributs).res);
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[-1].attributs).declarations);
}
#line 2596 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1073 "structfe.y" /* yacc.c:1646  */
    {
    char* label_falsee;
    char* label_truee;
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if (", (yyvsp[-2].attributs).res, ") goto ", label_truee, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, label_truee, ":\n", (yyvsp[0].attributs).code, label_falsee, ":\n", NULL);
    (yyval.attributs).res = NULL;

    (yyval.attributs).type= (yyvsp[0].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[-2].attributs).declarations);
}
#line 2616 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1090 "structfe.y" /* yacc.c:1646  */
    {
    char* label_falsee;
    char* label_truee;
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-4].attributs).code,"\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if (", (yyvsp[-4].attributs).res, ") goto ", label_truee, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_falsee, ";\n", NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, label_truee, ":\n", (yyvsp[-2].attributs).code, NULL);
    (yyval.attributs).code = concatener((yyval.attributs).code, label_falsee, ":\n", (yyvsp[0].attributs).code,  NULL);
    (yyval.attributs).res= NULL;

    if(compare_arbre_t((yyvsp[-2].attributs).type, (yyvsp[0].attributs).type))
	{
	    (yyval.attributs).type= (yyvsp[-2].attributs).type;
	}
    else
	{
	    /*char* error_msg;
	    error_msg=malloc(0);
	    sprintf(error_msg, "Type error line %d: Les types de retour dans le if (%s) et dans le else (%s) doivent etre les memes", yylineno, draw_type_expr($5.type), draw_type_expr($7.type));
	    type_error_custom(error_msg, &$$);*/
	    (yyval.attributs).type=basic_type(VOID_T, "");
	}
    (yyval.attributs).declarations= strdup((yyvsp[-4].attributs).declarations);
}
#line 2648 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1121 "structfe.y" /* yacc.c:1646  */
    {
    char* label_loop;
    char* label_end;
    label_loop  = strdup(new_label(label_loop));
    label_end= strdup(new_label(label_end));

    (yyval.attributs).code=init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, "\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if (", (yyvsp[-2].attributs).res , ") goto ", label_loop, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_end, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "\n", label_loop, ":\n", (yyvsp[0].attributs).code, "\n", (yyvsp[-2].attributs).code, "\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if (", (yyvsp[-2].attributs).res , ") goto ", label_loop, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_end, ";\n\n",label_end,":\n", NULL);
    (yyval.attributs).res= strdup("");
    (yyval.attributs).declarations=init_code((yyval.attributs).declarations);
    //fprintf(stderr, "Declarations dans le while : [ %s ]\n", $$.declarations);
    (yyval.attributs).declarations=concatener((yyval.attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);
    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 2672 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1143 "structfe.y" /* yacc.c:1646  */
    {
    char* label_loop;
    char* label_end;
    label_loop  = strdup(new_label(label_loop));
    label_end= strdup(new_label(label_end));

    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-4].attributs).code, NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, (yyvsp[-3].attributs).code, NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if (", (yyvsp[-3].attributs).res , ") goto ", label_loop, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_end, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, label_loop, ":\n", (yyvsp[0].attributs).code, "\n", (yyvsp[-2].attributs).code, "\n", (yyvsp[-3].attributs).code, NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "if (", (yyvsp[-3].attributs).res , ") goto ", label_loop, ";\n", NULL);
    (yyval.attributs).code= concatener((yyval.attributs).code, "goto ", label_end, ";\n",label_end,":\n", NULL);
    (yyval.attributs).res= NULL;
    
    (yyval.attributs).declarations=init_code((yyval.attributs).declarations);
    (yyval.attributs).declarations=concatener((yyval.attributs).declarations, (yyvsp[-4].attributs).declarations, (yyvsp[-3].attributs).declarations, (yyvsp[-2].attributs).declarations, (yyvsp[0].attributs).declarations, NULL);

    (yyval.attributs).type= basic_type(VOID_T, "");
}
#line 2698 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1168 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= init_code((yyval.attributs).code);
    (yyval.attributs).code= ajouter_code((yyval.attributs).code, "return ;\n");
    (yyval.attributs).type= basic_type(VOID_T, "");
    (yyval.attributs).declarations= strdup("\n");
}
#line 2709 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1176 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[-1].attributs).code);
    (yyval.attributs).code= concatener((yyval.attributs).code, "return ", (yyvsp[-1].attributs).res," ;\n", NULL);
    (yyval.attributs).type= (yyvsp[-1].attributs).type;
    (yyval.attributs).declarations= strdup((yyvsp[-1].attributs).declarations);
}
#line 2720 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1186 "structfe.y" /* yacc.c:1646  */
    {
    if(!(verif_type((yyvsp[0].attributs).type, ERROR_T))){printf("%s",(yyvsp[0].attributs).code);}
    else{printf(" ");}
}
#line 2729 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1193 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code= strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type= (yyvsp[0].attributs).type;
}
#line 2738 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1199 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-1].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type= prod_type((yyvsp[-1].attributs).type, (yyvsp[0].attributs).type, "");
}
#line 2748 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1208 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 2757 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1213 "structfe.y" /* yacc.c:1646  */
    {
    (yyval.attributs).code = strdup((yyvsp[0].attributs).code);
    (yyval.attributs).type = (yyvsp[0].attributs).type;
}
#line 2766 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1222 "structfe.y" /* yacc.c:1646  */
    {
    pop(); /*on pop la table des symboles des parametres*/
    (yyval.attributs).code = init_code((yyval.attributs).code);
    (yyval.attributs).code = concatener((yyval.attributs).code, (yyvsp[-2].attributs).code, " " ,(yyvsp[-1].attributs).code, (yyvsp[0].attributs).code, NULL);
    (yyval.attributs).type = (yyvsp[-1].attributs).type;
    if(verif_type((yyvsp[-1].attributs).type, FCT_T))
	{
	    arbre_t * arrivee= (yyvsp[-1].attributs).type->fils_droit;
	    if(!(compare_arbre_t(arrivee, (yyvsp[0].attributs).type)))
		{
		    type_error_function_definition(arrivee, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));
		}
	}
    else {type_error(FCT_T, (yyvsp[0].attributs).type, yylineno, &(yyval.attributs));}
}
#line 2786 "structfe.tab.c" /* yacc.c:1646  */
    break;


#line 2790 "structfe.tab.c" /* yacc.c:1646  */
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
#line 1239 "structfe.y" /* yacc.c:1906  */

	 
int main()
{
    /* init_pile();
       push(nouvelle_table());
       symbole_t *x=ajouter(top(), "x");
       x->type=basic_type(INT_T, "");
       fprintf(stderr, "Ajout du symbole x: \n");
       afficher_pile();
       push(nouvelle_table());
       symbole_t *y=ajouter(top(), "y");
       y->type=basic_type(INT_T, "");
       fprintf(stderr, "Ajout du symbole y: \n");
       afficher_pile();
       pop();
       fprintf(stderr, "On pop la table: \n");
       afficher_pile();
       pop();
       fprintf(stderr, "On pop la table: \n");
       afficher_pile();
       push(nouvelle_table());
       fprintf(stderr, "On ajoute une nouvelle table: \n");
       afficher_pile();
       push(nouvelle_table());
       fprintf(stderr, "On ajoute une nouvelle table: \n");
       afficher_pile();*/
    
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
    exit(get_error_code());
    
}

int yyerror(char* s)
{
    fprintf(stderr, "line %d: %s\n", yylineno, s);
    exit(SYNTAXERROR);
}
