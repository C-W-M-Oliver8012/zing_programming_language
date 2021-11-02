#include "string.h"

int main(int argc, char *argv[]) {
	if (argc >= 2) {
		String file = string_from_file(argv[1]);
		printf("%s", file.s);
		string_free(&file);
	}

	return 0;
}
