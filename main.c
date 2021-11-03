#include <stdio.h>
#include "string.h"

int main(int argc, char *argv[]) {
	if (argc >= 2) {
		String file;
		string_from_file(&file, argv[1]);
		printf("%s\n", file.s);
		string_free(&file);
	}

	String input;
	string_from_stdin(&input);
	printf("%s: %zu\n", input.s, input.len);
	string_free(&input);

	return 0;
}
