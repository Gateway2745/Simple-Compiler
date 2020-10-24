#ifndef PARSER_H
#define PARSER_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Term {
    char name[20];
    struct Term* next;
} Term;

typedef struct Grammar {
    char name[20];
    struct Term* next;
} Grammar;

typedef enum NonTerm {
    PROGRAM, DECL_LIST, ASSGN_LIST, DECL_STMT, ASSGN_STMT,
    INDEX, RNG, TYPE, ARRAY_RANGE, DTYPE,
    ONE_OR_MORE_VAR, LISTVAR, SINGLEVAR_DEC, MULTIVAR_DEC,
    JAGGED2_DEC, JAGGED3_DEC, JAGGED2_INIT, JAGGED3_INIT,
    JAGGED2_IDX, JAGGED3_IDX, JAGGED2_RNG, JAGGED3_RNG,
    JAGGED2_SINGLE_INIT, JAGGED3_SINGLE_INIT,
    EXPRESSION, ARRAY_SEL, VAR, ARRAY_IDX,
    ARITHMETIC_EXP, BOOLEAN_EXP,
    TERM, FACTOR, L_OR_TERM, L_AND_TERM
} NonTerm;

typedef union TermType {
    Token tok;
    NonTerm nt;
} TermType;

typedef struct parseTree {
    TermType grammar_term;
    int num_children;
    struct parseTree ** children;
    //type stuff, later
} parseTree;

typedef enum Token {
    BO, BC, SQO, SQC, CURLO, CURLC, CLN, SEMCOL, ROP, ASSGN,
    KEY_PROG, KEY_DECL, KEY_LIST, KEY_OF, KEY_VARS, KEY_ARR, R1,
    KEY_SIZE, KEY_VALS, KEY_JAG, KEY_INT, KEY_REAL, KEY_BOOL,
    OP_PLUS, OP_MINUS, OP_STAR, OP_SLASH, OP_AND, OP_OR,
    ID, INT,
    END
} Token;

typedef struct tokenStream {
    Token token;
    char lexeme[21];
    int line_num;
    struct tokenStream * next;
} tokenStream;

char * loadfile (char * filename, long * sizeptr);
void tokeniseSourcecode(char * source_file, tokenStream *s);

#endif