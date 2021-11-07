#include <stdio.h>
#include "string.h"

int main(int argc, char *argv[]) {
	if (argc >= 2) {
		String file;
		if (string_from_file(&file, argv[1]) != NULL) {
			printf("%s\n", file.s);
			string_free(&file);
		}
	}

	return 0;
}
