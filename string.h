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

char *string_new(String *self);
char *string_from(String *self, const char *str);
char *string_from_file(String *self, const char *filename);
char *string_from_stdin(String *self);
char *string_push_str(String *self, const char *str);
char *string_push_char(String *self, const char c);
char *string_push_string(String *self, const String *s);
void string_free(String *self);

#endif
