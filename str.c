
#include <string.h>

#include "str.h"

/*
 * string inside
 */
int strins(const char *dest, const char *src)
{
	int result=0;
	const char *p = src;
	// printf("-------------------\n");
	// printf("check string [%s]\n", dest);
	// printf("check src    [%s]\n", src);
	p = strchr(dest, *p);
	// printf("find start   [%s]\n", p);
	if (p!= NULL)
	{
		// printf("start compare\n");
		result = strncmp(p, src, strlen(src));
		return result;
	}else
	{
		return -1;
	}
}
