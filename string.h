#ifndef STRING
#define STRING

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef size_t usize;

typedef struct String {
	char *s;
	usize len;
} String;

String string_new(void);
String string_from(char *s);
String string_from_file(char *filename);
void string_push_str(String *self, char *str);
void string_push_char(String *self, char c);
void string_free(String *self);

#endif
