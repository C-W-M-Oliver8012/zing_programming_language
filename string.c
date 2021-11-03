#include "string.h"

usize string_new(String *self) {
	char *temp = malloc(1);
	if (temp == NULL) {
		return 0;
	}
	self->s = temp;
	self->s[0] = 0;
	self->len = 1;
	return self->len;
}

usize string_from(String *self, const char *str) {
	self->len = strlen(str) + 1;
	char *temp = malloc(self->len);
	if (temp == NULL) {
		return 0;
	}
	self->s = temp;
	memcpy(self->s, str, self->len - 1);
	self->s[self->len - 1] = 0;
	return self->len;
}

usize string_from_file(String *self, const char *filename) {
	char temp_string[4096] = "\0";
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		return 0;
	}
	while (fread(temp_string, 1, 4096, file)) {
		string_push_str(self, temp_string);
	}
	fclose(file);
	return self->len;
}

usize string_push_str(String *self, const char *str) {
	usize str_len = strlen(str);
	char *temp = realloc(self->s, self->len + str_len);
	if (temp == NULL) {
		return 0;
	}
	self->s = temp;
	memcpy(&self->s[self->len - 1], str, str_len);
	self->len = self->len + str_len;
	self->s[self->len - 1] = 0;
	return self->len;
}

usize string_push_char(String *self, const char c) {
	self->len = self->len + 1;
	char *temp = realloc(self->s, self->len);
	if (temp == NULL) {
		return 0;
	}
	self->s = temp;
	self->s[self->len - 2] = c;
	self->s[self->len - 1] = 0;
	return self->len;
}

void string_free(String *self) {
	free(self->s);
}
