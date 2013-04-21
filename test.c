#include <stdio.h>

void prtstr(char *str)
{
	printf(str);
}

int main()
{
	const char *hi = "hello wolrd";
	prtstr(hi);
}
