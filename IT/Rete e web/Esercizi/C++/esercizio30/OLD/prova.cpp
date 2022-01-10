#include <cstdio>
#include <cstring>

int main()
{
	printf("%%\n");
	char buf[10];
	snprintf(buf, sizeof(buf), "%% annuo\n");

	printf("%s", buf);
}

