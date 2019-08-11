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
#line 1 "parser.y" /* yacc.c:339  */

	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <iostream>
	#include <string>
	extern "C" void yyerror (char *);
	extern int yylex();
	extern int yylineno;
	Procedure * p;
	Symbol_Table* global_sym_tab;
	map<string, Procedure*> funmap;
	bool err=0;

#line 81 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    ASSIGN = 258,
    NAME = 259,
    FLOAT = 260,
    INTEGER = 261,
    DOUBLE_NUMBER = 262,
    VOID = 263,
    INTEGER_NUMBER = 264,
    IF = 265,
    DO = 266,
    WHILE = 267,
    ELSE = 268,
    PRINT = 269,
    RETURN = 270,
    OR = 271,
    AND = 272,
    NOT = 273,
    GT = 274,
    GTEQ = 275,
    LT = 276,
    LTEQ = 277,
    EQ = 278,
    NEQ = 279,
    UMINUS = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "parser.y" /* yacc.c:355  */

	int integer_value;
	double double_value;
	Data_Type data_type;
	std::string * string_value;
	list<Ast *> * ast_list;
	Ast * ast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	Basic_Block * basic_block;
	Procedure * procedure;
	list<Symbol_Table_Entry *> * mylist;

#line 161 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 178 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   298

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

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
      33,    34,    30,    28,    37,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    18,    35,
       2,    16,     2,    17,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    38,     2,     2,     2,     2,
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
      15,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    63,    67,    70,    75,    77,    79,   101,
     107,   155,   156,   161,   162,   166,   172,   178,   184,   191,
     198,   199,   200,   202,   206,   210,   211,   212,   213,   214,
     215,   216,   218,   236,   241,   247,   251,   253,   261,   270,
     275,   275,   275,   275,   275,   275,   275,   275,   276,   276,
     278,   285,   292,   307,   307,   309,   309,   311,   317,   322,
     329,   335,   342,   347,   352,   357,   361,   366,   371,   376,
     378,   383,   390,   395,   399,   418,   423,   429,   461,   464,
     469,   477,   485,   493,   501,   509,   512,   522,   525,   530,
     536,   561
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "NAME", "FLOAT", "INTEGER",
  "DOUBLE_NUMBER", "VOID", "INTEGER_NUMBER", "IF", "DO", "WHILE", "ELSE",
  "PRINT", "RETURN", "'='", "'?'", "':'", "OR", "AND", "NOT", "GT", "GTEQ",
  "LT", "LTEQ", "EQ", "NEQ", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'('",
  "')'", "';'", "'{'", "','", "'}'", "$accept", "SR", "O", "PR", "FD",
  "FSTART", "X", "LA", "KP", "LB", "Y", "T", "body", "stmt", "F_CALL",
  "LP1", "LP", "RET", "Print", "K1", "K2", "W2", "W1", "F", "R", "I", "I1",
  "I2", "W", "DOW", "cndr", "MD", "D", "L", "A", "Expr", "P", "N",
  "UNDNAME", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    61,    63,    58,   271,
     272,   273,   274,   275,   276,   277,   278,   279,    43,    45,
      42,    47,   280,    40,    41,    59,   123,    44,   125
};
# endif

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -48

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -139,    13,  -139,  -139,    11,  -139,  -139,  -139,  -139,  -139,
    -139,     7,  -139,  -139,   128,   -15,    -4,   -17,    24,    33,
     166,    55,    92,   192,  -139,  -139,  -139,    66,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   102,    23,
    -139,    92,    18,    18,    94,    18,  -139,    74,  -139,  -139,
    -139,    18,    18,    18,  -139,  -139,    39,   216,  -139,  -139,
     157,  -139,    18,    92,    92,    76,    75,  -139,    78,    77,
     267,    21,   267,    87,    70,  -139,  -139,  -139,    99,   254,
      18,    18,    18,    18,    18,    18,    18,    18,    18,    18,
      18,    18,    18,  -139,  -139,   230,  -139,  -139,  -139,     9,
      56,    18,  -139,   175,    18,   166,  -139,  -139,   244,   101,
    -139,   267,   267,   267,   267,   267,   267,    -7,    -7,  -139,
    -139,  -139,  -139,    11,    92,    92,   267,    90,   100,   112,
     114,   116,  -139,   121,  -139,   131,   132,   137,   129,  -139,
      18,    92,  -139,    11,  -139,  -139,    18,   138,   193,   106,
     267,  -139,   197,   119,   118,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,   175,    18,  -139,  -139,
     203,   193,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     7,     1,     2,    22,    21,    20,     4,     6,
      24,     0,     5,     9,     0,    91,     0,    76,    91,     0,
       0,     0,     0,     0,    24,    19,    54,     0,    30,    29,
      53,    23,    25,    55,    56,    27,    28,    26,     0,    12,
      74,     0,    35,     0,     0,     0,    91,     0,    90,    89,
      88,     0,     0,     0,    37,    86,     0,     0,    85,    87,
       0,    31,     0,    14,    14,     0,    11,    75,    36,     0,
      34,     0,     0,     0,     0,    39,    68,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    52,     0,    18,    13,    17,     0,
       0,     0,    32,     0,     0,     0,    69,    78,     0,    71,
      70,    62,    63,    64,    65,    67,    66,    83,    81,    80,
      82,    77,     8,    73,    14,    14,    33,     0,     0,    30,
      29,     0,    43,    53,    58,    55,    28,    26,     0,    60,
       0,     0,    10,    73,    16,    15,     0,    31,     0,     0,
      84,    72,     0,     0,     0,    46,    45,    57,    59,    49,
      42,    44,    48,    41,    40,    61,     0,     0,    47,    51,
       0,     0,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   -43,  -139,
    -139,   152,   133,  -139,   -12,  -139,  -139,   -88,   -71,   -98,
     -13,  -139,  -139,   -69,   -19,  -139,   -68,  -138,  -139,   -49,
     -39,    19,   161,   134,   -40,   -16,  -139,   151,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,     8,     9,    10,    65,    96,    66,
      13,   141,    14,    26,    55,    68,    69,    28,    29,   169,
     158,   159,   132,    30,    31,    32,    33,    34,    35,    36,
      56,   142,   143,    16,    37,    72,    58,    59,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    44,    27,    38,    71,   131,    74,    57,    27,    38,
     162,    15,    76,     3,    78,   129,     5,     6,    39,     7,
      41,    98,    18,    91,    92,    49,    70,    50,    63,    64,
      17,    40,   130,   162,   133,   135,    77,    79,    80,    51,
      81,    82,   109,   110,   122,   123,    95,    52,    27,    38,
     157,    53,    97,    97,   136,   103,    80,    42,    81,    82,
     155,   124,   125,   137,   108,   138,    43,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   156,   129,   160,
     161,   144,   145,   155,   134,   126,   139,    80,    45,    81,
      82,   128,    38,    27,    38,   130,    46,   133,   135,   163,
     156,    61,   160,   161,   105,    62,    73,   152,   164,    75,
      99,   102,   100,    97,    97,   101,    80,   136,    81,    82,
     104,    82,   163,   146,   150,   -46,   137,   -45,   170,   148,
      17,   164,    18,   106,   -42,   147,   154,    38,    19,    20,
      21,   165,    22,    23,   -44,   -41,    80,   139,    81,    82,
     -40,   -47,   167,   168,   128,    38,    11,    60,   172,   154,
      38,    18,   151,   149,    24,    12,    25,    19,    20,    21,
      18,    22,    23,    47,     0,    67,    19,    20,    21,    18,
      22,    23,     0,     0,     0,    19,    20,   127,     0,    22,
      23,     0,     0,    24,     0,    94,    18,    18,     0,    49,
       0,    50,    24,    19,    20,   153,     0,    22,    23,     0,
       0,    24,     0,    51,    80,     0,    81,    82,     0,     0,
      80,    52,    81,    82,     0,    53,     0,    54,     0,    24,
       0,   166,     0,     0,     0,     0,     0,   171,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,    93,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   140,     0,     0,   121,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,   107,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      11,    20,    14,    14,    43,   103,    45,    23,    20,    20,
     148,     4,    51,     0,    53,   103,     5,     6,    33,     8,
      37,    64,     4,    30,    31,     7,    42,     9,     5,     6,
      41,    35,   103,   171,   103,   103,    52,    53,    17,    21,
      19,    20,    81,    82,    35,    36,    62,    29,    60,    60,
     148,    33,    63,    64,   103,    34,    17,    33,    19,    20,
     148,     5,     6,   103,    80,   104,    33,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,   148,   166,   148,
     148,   124,   125,   171,   103,   101,   105,    17,    33,    19,
      20,   103,   103,   105,   105,   166,     4,   166,   166,   148,
     171,    35,   171,   171,    34,     3,    12,   146,   148,    35,
      34,    34,    37,   124,   125,    37,    17,   166,    19,    20,
      33,    20,   171,    33,   140,    13,   166,    13,   167,    13,
     141,   171,     4,    34,    13,    35,   148,   148,    10,    11,
      12,    35,    14,    15,    13,    13,    17,   166,    19,    20,
      13,    13,    33,    35,   166,   166,     4,    24,   171,   171,
     171,     4,   143,    34,    36,     4,    38,    10,    11,    12,
       4,    14,    15,    22,    -1,    41,    10,    11,    12,     4,
      14,    15,    -1,    -1,    -1,    10,    11,    12,    -1,    14,
      15,    -1,    -1,    36,    -1,    38,     4,     4,    -1,     7,
      -1,     9,    36,    10,    11,    12,    -1,    14,    15,    -1,
      -1,    36,    -1,    21,    17,    -1,    19,    20,    -1,    -1,
      17,    29,    19,    20,    -1,    33,    -1,    35,    -1,    36,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    34,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    35,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    18,    -1,    -1,    35,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,    42,     5,     6,     8,    43,    44,
      45,    50,    71,    49,    51,     4,    72,    77,     4,    10,
      11,    12,    14,    15,    36,    38,    52,    53,    56,    57,
      62,    63,    64,    65,    66,    67,    68,    73,    77,    33,
      35,    37,    33,    33,    63,    33,     4,    76,    77,     7,
       9,    21,    29,    33,    35,    53,    69,    74,    75,    76,
      51,    35,     3,     5,     6,    46,    48,    72,    54,    55,
      74,    69,    74,    12,    69,    35,    69,    74,    69,    74,
      17,    19,    20,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    35,    38,    74,    47,    77,    47,    34,
      37,    37,    34,    34,    33,    34,    34,    34,    74,    69,
      69,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    35,    35,    36,     5,     6,    74,    12,    53,    56,
      57,    58,    61,    62,    63,    65,    68,    73,    69,    63,
      18,    50,    70,    71,    47,    47,    33,    35,    13,    34,
      74,    70,    69,    12,    53,    56,    57,    58,    59,    60,
      62,    65,    66,    68,    73,    35,    34,    33,    35,    58,
      69,    34,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    42,    42,    42,    42,    43,    44,
      45,    46,    46,    47,    47,    48,    48,    48,    48,    49,
      50,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    54,    54,    55,    55,    56,    56,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    61,    62,    63,    63,    64,    64,    65,    66,    66,
      67,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    71,    72,    72,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    75,
      76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     2,     0,     6,     2,
       7,     1,     0,     1,     0,     4,     4,     2,     2,     2,
       1,     1,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     2,     4,     3,     1,     0,     1,     2,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       5,     5,     3,     1,     1,     1,     1,     7,     5,     7,
       5,     7,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     2,     0,     3,     3,     1,     4,     3,     2,
       3,     3,     3,     3,     5,     1,     1,     1,     1,     1,
       1,     1
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
#line 58 "parser.y" /* yacc.c:1646  */
    {
				program_object.set_procedure_map(funmap);
				program_object.set_global_table(*global_sym_tab);
			}
#line 1401 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 63 "parser.y" /* yacc.c:1646  */
    {
				global_sym_tab=new Symbol_Table();
			}
#line 1409 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "parser.y" /* yacc.c:1646  */
    {

			}
#line 1417 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "parser.y" /* yacc.c:1646  */
    {
				Symbol_Table * temp2=(yyvsp[0].symbol_table);
				temp2->set_table_scope(global);
				global_sym_tab->append_list(*temp2,yylineno);
			}
#line 1427 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 75 "parser.y" /* yacc.c:1646  */
    {
			}
#line 1434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "parser.y" /* yacc.c:1646  */
    {}
#line 1440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "parser.y" /* yacc.c:1646  */
    {
				string *str=(yyvsp[-4].string_value);
				if(*(yyvsp[-4].string_value)=="main" && (yyvsp[-5].data_type)!=void_data_type){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Main should be defined and it's type should be void\n",yylineno);
					exit(1);
				}
				else if(*(yyvsp[-4].string_value)=="main"){}
				else{
					*str=*str+"_";
				}
				if(funmap.find(*(yyvsp[-4].string_value))!=funmap.end()){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Current procedure already defined\n",yylineno);
					exit(1);
				}
				Procedure* p1=new Procedure((yyvsp[-5].data_type),*str,yylineno);
				Symbol_Table * temp=(yyvsp[-2].symbol_table);
				temp->set_table_scope(local);
				p1->set_formal_param_list(*temp);
				funmap[p1->get_proc_name()] = p1;
				(yyval.procedure)=p1;
			}
#line 1466 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "parser.y" /* yacc.c:1646  */
    {
				Procedure* temp = (yyvsp[-1].procedure);
				temp->set_ast_list(*(yyvsp[0].ast_list));
				(yyval.procedure) = temp;
			}
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "parser.y" /* yacc.c:1646  */
    {
				string * str=(yyvsp[-5].string_value);
				if(*(yyvsp[-5].string_value)=="main" && (yyvsp[-6].data_type)!=void_data_type){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Main should be defined and it's type should be void\n",yylineno);
					exit(1);
				}
				else if(*(yyvsp[-5].string_value)=="main"){}
				else{
					*str=*str+"_";
				}

				if(funmap.find(*str)!=funmap.end()){
					if((yyvsp[-6].data_type)!=funmap[*str]->get_return_type()){
						fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Return data types not matching\n",yylineno);
						exit(1);
					}
					list<Symbol_Table_Entry*> param_list = funmap[*str]->get_formal_param_list().get_table();
					list<Symbol_Table_Entry*> l=(yyvsp[-3].symbol_table)->get_table();
					if(l.size()!=param_list.size()){
						fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Number of parameters not matching\n",yylineno);
						exit(1);
					}
					list<Symbol_Table_Entry*>::iterator it1=param_list.begin();
					list<Symbol_Table_Entry*>::iterator it2=l.begin();
					for(;it1!=param_list.end();it1++){
						if((*it1)->get_data_type()!=(*it2)->get_data_type()){
							fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Parameters not matching\n",yylineno);
							exit(1);
						}
						if((*it2)->get_variable_name()=="#"){
							fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Parameters not given in function definition\n",yylineno);
							exit(1);
						}
						it2++;
					}

				}
				p=new Procedure((yyvsp[-6].data_type),*str,yylineno);
				Symbol_Table * temp=(yyvsp[0].symbol_table);
				temp->set_table_scope(local);
				p->set_local_list(*temp);
				Symbol_Table * temp2 = (yyvsp[-3].symbol_table);
				temp2->set_table_scope(formal);
				p->set_formal_param_list(*temp2);
				funmap[*str]=p;
				(yyval.procedure)=p;
			}
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "parser.y" /* yacc.c:1646  */
    {(yyval.symbol_table)=(yyvsp[0].symbol_table);}
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 156 "parser.y" /* yacc.c:1646  */
    {
				Symbol_Table * temp=new Symbol_Table();
				(yyval.symbol_table)= temp;
			}
#line 1543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.string_value)=(yyvsp[0].string_value);}
#line 1549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 162 "parser.y" /* yacc.c:1646  */
    {
				string * temp=new string("#");
				(yyval.string_value)=temp;
			}
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 166 "parser.y" /* yacc.c:1646  */
    {
				Symbol_Table_Entry * temp = new Symbol_Table_Entry(*(yyvsp[0].string_value), int_data_type, yylineno, fp_ref);
				Symbol_Table* t1=(yyvsp[-3].symbol_table);
				t1->push_symbol(temp);
				(yyval.symbol_table) = t1;
			}
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 172 "parser.y" /* yacc.c:1646  */
    {
				Symbol_Table_Entry * temp = new Symbol_Table_Entry(*(yyvsp[0].string_value), double_data_type, yylineno, fp_ref);
				Symbol_Table* t1=(yyvsp[-3].symbol_table);
				t1->push_symbol(temp);
				(yyval.symbol_table) = t1;
			}
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 178 "parser.y" /* yacc.c:1646  */
    {
				Symbol_Table_Entry * temp = new Symbol_Table_Entry(*(yyvsp[0].string_value), int_data_type, yylineno, fp_ref);
				Symbol_Table* temp2 = new Symbol_Table();
				temp2->push_symbol(temp);
				(yyval.symbol_table) = temp2;
			}
#line 1591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 184 "parser.y" /* yacc.c:1646  */
    {
				Symbol_Table_Entry * temp = new Symbol_Table_Entry(*(yyvsp[0].string_value), double_data_type, yylineno, fp_ref);
				Symbol_Table* temp2 = new Symbol_Table();
				temp2->push_symbol(temp);
				(yyval.symbol_table) = temp2;
			}
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 191 "parser.y" /* yacc.c:1646  */
    {
				if(err){
					exit(1);
				}
				(yyval.ast_list)=(yyvsp[-1].ast_list);
			}
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type)=void_data_type;}
#line 1619 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type)=int_data_type;}
#line 1625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.data_type)=double_data_type;}
#line 1631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 202 "parser.y" /* yacc.c:1646  */
    {
				list<Ast *> * temp=(yyvsp[-1].ast_list);
				temp->push_back((yyvsp[0].ast));
				(yyval.ast_list)=temp;	
			}
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 206 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast_list)=new list<Ast *>;
			}
#line 1649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1655 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 212 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[0].ast);}
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[-1].ast);}
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 218 "parser.y" /* yacc.c:1646  */
    {
				if((*(yyvsp[-3].string_value))=="main"){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Main is not callable\n",yylineno);
					exit(1);
				}
				string * str=(yyvsp[-3].string_value);
				*str=*str+"_";
				if(funmap.find(*str)==funmap.end()){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Function does not exist\n",yylineno);
					exit(1);
				}
				Call_Ast * temp=new Call_Ast(*str,yylineno);
				temp->set_data_type(funmap[*str]->get_return_type());
				temp->set_actual_param_list(*(yyvsp[-1].ast_list));
				temp->set_register(NULL);
				(yyval.ast)=temp;
			}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 236 "parser.y" /* yacc.c:1646  */
    {
				list<Ast*>* temp=(yyvsp[-2].ast_list);
				temp->push_back((yyvsp[0].ast));
				(yyval.ast_list)=temp;
			}
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 241 "parser.y" /* yacc.c:1646  */
    {
				list<Ast*> *temp=new list<Ast*>;
				temp->push_back((yyvsp[0].ast));
				(yyval.ast_list)=temp;
			}
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 247 "parser.y" /* yacc.c:1646  */
    {
				list<Ast*> *temp=new list<Ast*>;
				(yyval.ast_list)=temp;
			}
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 251 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_list)=(yyvsp[0].ast_list);}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 253 "parser.y" /* yacc.c:1646  */
    {
				Return_Ast* temp=new Return_Ast(NULL,p->get_proc_name(),yylineno);
				if(p->get_return_type()!=void_data_type){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Return value required\n",yylineno);
					exit(1);
				}
				(yyval.ast)=temp;
			}
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 261 "parser.y" /* yacc.c:1646  */
    {
				Return_Ast* temp=new Return_Ast((yyvsp[-1].ast),p->get_proc_name(),yylineno);
				if(p->get_return_type()!=(yyvsp[-1].ast)->get_data_type()){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Return value does not matc the required\n",yylineno);
					exit(1);
				}
				(yyval.ast)=temp;
			}
#line 1774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 270 "parser.y" /* yacc.c:1646  */
    {
				Print_Ast* temp = new Print_Ast((yyvsp[-1].ast), yylineno);
				(yyval.ast) = temp;
			}
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1801 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[0].ast);}
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.ast)=(yyvsp[-1].ast);}
#line 1831 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1837 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 278 "parser.y" /* yacc.c:1646  */
    {
				Iteration_Statement_Ast* temp  = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno,0);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1854 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 285 "parser.y" /* yacc.c:1646  */
    {
				Iteration_Statement_Ast* temp  = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno,0);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1865 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 292 "parser.y" /* yacc.c:1646  */
    {
				Sequence_Ast* temp = new Sequence_Ast(yylineno);
				list<Ast*>::iterator it;
				if((yyvsp[-1].ast_list)->begin()==(yyvsp[-1].ast_list)->end()){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Empty block\n",yylineno);
					exit(1);
				}
				for(it=(yyvsp[-1].ast_list)->begin();it!=(yyvsp[-1].ast_list)->end();it++){
					temp->ast_push_back(*it);
				}
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 307 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 307 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 311 "parser.y" /* yacc.c:1646  */
    {
				Selection_Statement_Ast* temp = new Selection_Statement_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1919 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 317 "parser.y" /* yacc.c:1646  */
    {
				Selection_Statement_Ast* temp = new Selection_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), NULL,yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 322 "parser.y" /* yacc.c:1646  */
    {
				Selection_Statement_Ast* temp = new Selection_Statement_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 329 "parser.y" /* yacc.c:1646  */
    {
				Iteration_Statement_Ast* temp  = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[0].ast), yylineno,0);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 335 "parser.y" /* yacc.c:1646  */
    {
				Iteration_Statement_Ast* temp = new Iteration_Statement_Ast((yyvsp[-2].ast), (yyvsp[-5].ast),yylineno, 1);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1963 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 342 "parser.y" /* yacc.c:1646  */
    {
				Relational_Expr_Ast* temp = new Relational_Expr_Ast((yyvsp[-2].ast),greater_than,(yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 347 "parser.y" /* yacc.c:1646  */
    {
				Relational_Expr_Ast* temp = new Relational_Expr_Ast((yyvsp[-2].ast),greater_equalto,(yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 352 "parser.y" /* yacc.c:1646  */
    {
				Relational_Expr_Ast* temp = new Relational_Expr_Ast((yyvsp[-2].ast),less_than,(yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 1996 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 357 "parser.y" /* yacc.c:1646  */
    {
				Relational_Expr_Ast* temp = new Relational_Expr_Ast((yyvsp[-2].ast),less_equalto,(yyvsp[0].ast),yylineno);
				temp->check_ast();
				(yyval.ast) = temp;
			}
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 361 "parser.y" /* yacc.c:1646  */
    {
				Relational_Expr_Ast* temp = new Relational_Expr_Ast((yyvsp[-2].ast),not_equalto,(yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 2017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 366 "parser.y" /* yacc.c:1646  */
    {
				Relational_Expr_Ast* temp = new Relational_Expr_Ast((yyvsp[-2].ast),equalto,(yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 371 "parser.y" /* yacc.c:1646  */
    {
				Logical_Expr_Ast* temp = new Logical_Expr_Ast(NULL, _logical_not, (yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 2039 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 376 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast) = (yyvsp[-1].ast);
			}
#line 2047 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 378 "parser.y" /* yacc.c:1646  */
    {
				Logical_Expr_Ast *temp = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_and , (yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 2058 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 383 "parser.y" /* yacc.c:1646  */
    {
				Logical_Expr_Ast *temp = new Logical_Expr_Ast((yyvsp[-2].ast), _logical_or , (yyvsp[0].ast),yylineno);
				if(!temp->check_ast())
					err= 1;
				(yyval.ast) = temp;
			}
#line 2069 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 390 "parser.y" /* yacc.c:1646  */
    {
				Symbol_Table * temp=(yyvsp[-1].symbol_table);
				temp->append_list(*(yyvsp[0].symbol_table),yylineno);
				(yyval.symbol_table)=temp;
			}
#line 2079 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 395 "parser.y" /* yacc.c:1646  */
    {
				(yyval.symbol_table)=new Symbol_Table();
			}
#line 2087 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 399 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].data_type)==void_data_type){
					yyerror("cs316: Error: error: void datatype for variable not supported\n");
					exit(1);
				}
				list<Symbol_Table_Entry *> * temp=(yyvsp[-1].mylist);
				list<Symbol_Table_Entry *>::iterator it;
				Symbol_Table * A=new Symbol_Table();
				for(it=temp->begin();it!=temp->end();it++){
					(*it)->set_data_type((yyvsp[-2].data_type));
					if(A->variable_in_symbol_list_check((*it)->get_variable_name())){
						yyerror("cs316: Error: error: Variable is declared twice\n");
						exit(1);
					}
					A->push_symbol(*it);
				}
				(yyval.symbol_table)=A;
			}
#line 2110 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 418 "parser.y" /* yacc.c:1646  */
    {
				list<Symbol_Table_Entry *> *temp=(yyvsp[0].mylist);
				temp->push_front(new Symbol_Table_Entry(*(yyvsp[-2].string_value),int_data_type,yylineno));
				(yyval.mylist)=temp;
			}
#line 2120 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 423 "parser.y" /* yacc.c:1646  */
    {
				list<Symbol_Table_Entry *> *temp= new list<Symbol_Table_Entry *>;
				temp->push_front(new Symbol_Table_Entry(*(yyvsp[0].string_value),int_data_type,yylineno));
				(yyval.mylist)=temp;
			}
#line 2130 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 429 "parser.y" /* yacc.c:1646  */
    {
				Symbol_Table_Entry temp1;
				Name_Ast * temp;
				if(p->variable_in_symbol_list_check(*(yyvsp[-3].string_value))){
					temp1=p->get_symbol_table_entry(*(yyvsp[-3].string_value));
					temp=new Name_Ast(*(yyvsp[-3].string_value),p->get_symbol_table_entry(*(yyvsp[-3].string_value)),yylineno);
					temp->set_data_type(p->get_symbol_table_entry(*(yyvsp[-3].string_value)).get_data_type());
				}
				else{
					if(p->variable_in_formal_list_check(*(yyvsp[-3].string_value))){
						temp1=p->get_formal_param_entry(*(yyvsp[-3].string_value));
						temp=new Name_Ast(*(yyvsp[-3].string_value),p->get_formal_param_entry(*(yyvsp[-3].string_value)),yylineno);
						temp->set_data_type(p->get_formal_param_entry(*(yyvsp[-3].string_value)).get_data_type());
					}
					else if(global_sym_tab->variable_in_symbol_list_check(*(yyvsp[-3].string_value))){
						temp1=global_sym_tab->get_symbol_table_entry(*(yyvsp[-3].string_value));
						temp=new Name_Ast(*(yyvsp[-3].string_value),global_sym_tab->get_symbol_table_entry(*(yyvsp[-3].string_value)),yylineno);
						temp->set_data_type(global_sym_tab->get_symbol_table_entry(*(yyvsp[-3].string_value)).get_data_type());
					}
					else{
						fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Variable has not been declared\n",yylineno);
						exit(1);
					}
				}
				Assignment_Ast * res=new Assignment_Ast(temp,(yyvsp[-1].ast),yylineno);
				if(!res->check_ast()){
					err=1;
				}
				(yyval.ast)=res;
			}
#line 2165 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 461 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast) = (yyvsp[-1].ast);
			}
#line 2173 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 464 "parser.y" /* yacc.c:1646  */
    {
				UMinus_Ast * temp=new UMinus_Ast((yyvsp[0].ast), NULL, yylineno);
				temp->set_data_type((yyvsp[0].ast)->get_data_type());
				(yyval.ast)=temp;
			}
#line 2183 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 469 "parser.y" /* yacc.c:1646  */
    {
				Mult_Ast * temp=new Mult_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
				temp->set_data_type((yyvsp[-2].ast)->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				(yyval.ast)=temp;
			}
#line 2196 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 477 "parser.y" /* yacc.c:1646  */
    {
				Minus_Ast * temp=new Minus_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
				temp->set_data_type((yyvsp[-2].ast)->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				(yyval.ast)=temp;
			}
#line 2209 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 485 "parser.y" /* yacc.c:1646  */
    {
				Divide_Ast * temp=new Divide_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
				temp->set_data_type((yyvsp[-2].ast)->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				(yyval.ast)=temp;
			}
#line 2222 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 493 "parser.y" /* yacc.c:1646  */
    {
				Plus_Ast * temp=new Plus_Ast((yyvsp[-2].ast),(yyvsp[0].ast),yylineno);
				temp->set_data_type((yyvsp[-2].ast)->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				(yyval.ast)=temp;
			}
#line 2235 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 501 "parser.y" /* yacc.c:1646  */
    {
				Conditional_Expression_Ast* temp = new Conditional_Expression_Ast((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), yylineno);
				temp->set_data_type((yyvsp[-2].ast)->get_data_type());
				if(!temp->check_ast()){
					err=1;
				}
				(yyval.ast)= temp;
			}
#line 2248 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 509 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast)=(yyvsp[0].ast);
			}
#line 2256 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 512 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[0].ast)->get_data_type()==void_data_type){
					fprintf(stderr,"cs316: Error: cfglp error: Line: %d: Void data type cannot be used in expression\n",yylineno);
					exit(1);
				}
				Call_Ast* temp=(Call_Ast*) (yyvsp[0].ast);
				temp->set_register(new Register_Descriptor());
				(yyval.ast)=temp;
			}
#line 2270 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 522 "parser.y" /* yacc.c:1646  */
    {
				(yyval.ast) = (yyvsp[0].ast);
			}
#line 2278 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 525 "parser.y" /* yacc.c:1646  */
    {
				Number_Ast<int> * temp=new Number_Ast<int>((yyvsp[0].integer_value),int_data_type,yylineno);
				temp->set_data_type(int_data_type);
				(yyval.ast)=temp;
			}
#line 2288 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 530 "parser.y" /* yacc.c:1646  */
    {
				Number_Ast<double> * temp =new Number_Ast<double>((yyvsp[0].double_value),double_data_type,yylineno);
				temp->set_data_type(double_data_type);
				(yyval.ast)=temp;
			}
#line 2298 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 536 "parser.y" /* yacc.c:1646  */
    {
				string* str = (yyvsp[0].string_value);
				if(p->variable_in_symbol_list_check(*str)){
					Name_Ast * temp = new Name_Ast(*str,p->get_symbol_table_entry(*str),yylineno);
					temp->set_data_type(p->get_symbol_table_entry(*str).get_data_type());
					(yyval.ast)=temp;
				}
				else if(p->variable_in_formal_list_check(*str)){
					Name_Ast * temp = new Name_Ast(*str,p->get_formal_param_entry(*str),yylineno);
					temp->set_data_type(p->get_formal_param_entry(*str).get_data_type());
					(yyval.ast)=temp;
				}
				else{
					if(global_sym_tab->variable_in_symbol_list_check(*str)){
						Name_Ast* temp = new Name_Ast(*str,global_sym_tab->get_symbol_table_entry(*str),yylineno);
						temp->set_data_type(global_sym_tab->get_symbol_table_entry(*str).get_data_type());
						(yyval.ast)=temp;
					}
					else{
						yyerror("cs316: Error: error: variable not declared\n");
						exit(1);
					}
				}
			}
#line 2327 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 561 "parser.y" /* yacc.c:1646  */
    {
				string* str = (yyvsp[0].string_value);
				*str = *str + "_";
				(yyval.string_value) = str;
			}
#line 2337 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2341 "parser.tab.c" /* yacc.c:1646  */
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
