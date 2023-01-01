/* test string functions */

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char s[100];
	// s[0] = 0;
	strncpy(s, "foo ", sizeof(s));
	strcat(s, "bar");
	// strcat

	printf("%s\n", s);

	return 0;
}

