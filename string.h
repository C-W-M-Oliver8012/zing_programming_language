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

String string_new(String *self);
String string_from(String *self, const char *str);
String string_from_file(String *self, const char *filename);
void string_push_str(String *self, const char *str);
void string_push_char(String *self, const char c);
void string_free(String *self);

#endif
