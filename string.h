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

usize string_new(String *self);
usize string_from(String *self, const char *str);
usize string_from_file(String *self, const char *filename);
usize string_push_str(String *self, const char *str);
usize string_push_char(String *self, const char c);
void string_free(String *self);

#endif
