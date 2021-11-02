#include "string.h"

String string_new(String *self) {
	if (self != NULL) {
		string_free(self);
	}

	String string;
	char *temp = malloc(1);
	if (temp == NULL) {
		printf("Failed to allocate memory in \"string_new()\".\n");
		exit(-1);
	}
	string.s = temp;
	string.s[0] = 0;
	string.len = 1;
	return string;
}

String string_from(String *self, const char *str) {
	if (self != NULL) {
		string_free(self);
	}

	String string = string_new(NULL);
	string.len = strlen(str) + 1;
	char *temp = malloc(string.len);
	if (temp == NULL) {
		printf("Failed to allocate memory in \"string_new()\".\n");
		exit(-1);
	}
	string.s = temp;
	memcpy(string.s, str, string.len - 1);
	string.s[string.len - 1] = 0;
	return string;
}

String string_from_file(String *self, const char *filename) {
	if (self != NULL) {
		string_free(self);
	}

	String string = string_new(NULL);
	char temp_string[1000];
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Unable to open file \"%s.\"\n", filename);
		return string;
	}
	while (fgets(temp_string, 1000, file)) {
		string_push_str(&string, temp_string);
	}
	fclose(file);
	return string;
}

void string_push_str(String *self, const char *str) {
	usize str_len = strlen(str);
	char *temp = realloc(self->s, self->len + str_len);
	if (temp == NULL) {
		printf("Failed to allocate memory in \"string_push_str.\"");
		exit(-1);
	}
	self->s = temp;
	memcpy(&self->s[self->len - 1], str, str_len);
	self->len = self->len + str_len;
	self->s[self->len - 1] = 0;
}

void string_push_char(String *self, const char c) {
	self->len = self->len + 1;
	char *temp = realloc(self->s, self->len);
	if (temp == NULL) {
		printf("Failed to allocate memory in \"string_push_char()\".\n");
		exit(-1);
	}
	self->s = temp;
	self->s[self->len - 2] = c;
	self->s[self->len - 1] = 0;
}

void string_free(String *self) {
	free(self->s);
}
