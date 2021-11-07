#include "string.h"

char *string_new(String *self) {
	char *temp = malloc(sizeof temp);
	if (temp == NULL) {
		self->len = 0;
		self->s = NULL;
		return NULL;
	}
	self->s = temp;
	self->s[0] = 0;
	self->len = 1;
	return self->s;
}

char *string_from(String *self, const char *str) {
	self->len = strlen(str) + 1;
	char *temp = malloc(sizeof temp * self->len);
	if (temp == NULL) {
		self->len = 0;
		self->s = NULL;
		return NULL;
	}
	self->s = temp;
	memcpy(self->s, str, self->len - 1);
	self->s[self->len - 1] = 0;
	return self->s;
}

char *string_from_file(String *self, const char *filename) {
	string_new(self);
	char temp_string[4096] = "\0";
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		if (self->s != NULL) {
			string_free(self);
		}
		return NULL;
	}
	while (fread(temp_string, 1, 4096, file)) {
		string_push_str(self, temp_string);
	}
	fclose(file);
	return self->s;
}

char *string_from_stdin(String *self) {
	string_new(self);
	char temp_string[4096] = "\0";
	while (fgets(temp_string, 4096, stdin)) {
		usize str_len = strlen(temp_string);
		if (temp_string[str_len - 1] == '\n') {
			temp_string[str_len - 1] = 0;
			if (string_push_str(self, temp_string) == NULL) {
				return NULL;
			}
			break;
		}
		if (string_push_str(self, temp_string) == NULL) {
			return NULL;
		}
	}
	return self->s;
}

char *string_push_str(String *self, const char *str) {
	usize str_len = strlen(str);
	char *temp = realloc(self->s, self->len + str_len);
	if (temp == NULL) {
		if (self->s != NULL) {
			string_free(self);
		}
		return NULL;
	}
	self->s = temp;
	memcpy(&self->s[self->len - 1], str, str_len);
	self->len = self->len + str_len;
	self->s[self->len - 1] = 0;
	return self->s;
}

char *string_push_char(String *self, const char c) {
	self->len = self->len + 1;
	char *temp = realloc(self->s, self->len);
	if (temp == NULL) {
		if (self->s != NULL) {
			string_free(self);
		}
		return NULL;
	}
	self->s = temp;
	self->s[self->len - 2] = c;
	self->s[self->len - 1] = 0;
	return self->s;
}

char *string_push_string(String *self, const String *s) {
	char *temp = realloc(self->s, sizeof temp * (self->len + s->len - 1));
	if (temp == NULL) {
		if (self->s != NULL) {
			string_free(self);
		}
		return NULL;
	}
	self->s = temp;
	memcpy(&self->s[self->len - 1], s->s, s->len);
	self->len = self->len + s->len - 1;
	return self->s;
}

void string_free(String *self) {
	free(self->s);
	self->s = NULL;
	self->len = 0;
}
