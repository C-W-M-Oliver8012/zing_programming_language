#include <stdio.h>
#include "string.h"

int main(int argc, char *argv[]) {
	if (argc >= 2) {
		String file;
		string_new(&file);
		string_from_file(&file, argv[1]);
		printf("%s\n", file.s);
		string_free(&file);
	}

	return 0;
}
