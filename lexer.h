#ifndef LEXER
#define LEXER

#include "string.h"

typedef struct Token {
	String str;
	usize num;
} Token;

typedef struct Token_vec {
	Token *v;
	usize len;
} Token_vec;

#endif
