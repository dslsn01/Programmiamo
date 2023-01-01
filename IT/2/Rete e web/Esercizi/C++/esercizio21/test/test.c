#include <stdio.h>
#include <string.h>

int main()
{
	char *s = "foobarbaz";
	if (strncmp(s, "foo", 3) == 0) {
		printf("Ok!\n");
	}

	char s1[3] = "foo";
	const char* s2 = "foo";

	printf("%s == %s? %d\n", s1, s2, strcmp(s1, s2));
	printf("%s == %s? %d\n", s1, "foo", strcmp(s1, s2));
	printf("%s == %s? %d\n", s2, "foo", strcmp(s1, s2));

	const char* msg = strcmp(s1, s2) == 0 ? "OK" : "KO";
	printf("%s\n", msg);

	return 0;
}

