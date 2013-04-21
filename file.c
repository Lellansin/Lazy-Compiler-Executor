
#include <string.h>
#include <stdlib.h>

#include "file.h"
#include "public.h"
#include "error.h"

char *FileNames[FILE_NUM_MAX];
int FileCount;

Coption *options[OPTION_NUM_MAX]; 
int OptionCount;

/* option with param */
char owp[][OPTION_NAME_MAX] = {
	"-o"
};

char owp_num = sizeof(owp) / sizeof(owp[0]);

int parseArg(int argc, char const *argv[])
{
	if (argc < 2)
		exit(-1);

	int is_record_param=0;
	int is_option=0;

	int i, res;
	for (i = 1; i < argc; ++i)
	{
		/*if ( is_option == judgeOption(argc[i]) ==  TRUE)
		{
			
		}*/
		if ( is_record_param == 0 && (res = judgeType(argv[i], "c")) == TRUE )
		{
			FileNames[FileCount] = argv[i];
			FileCount++;
		}else if (is_record_param == 1)
		{
			/* code */
		}
	}
}

int judgeOption(const char *option)
{
	int i;

	if (*option != '-')
	{
		return NOT_OPTION;
	}

	for (i = 0; i < owp_num; ++i)
	{
		if(strcmp(owp[i], option) == 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

int judgeType(const char *file_name, const char *file_type)
{
	char *p;
	p = strrchr(file_name, '.');
	if ( p != NULL )
	{
		if ( strcmp( p+1, file_type ) == 0 )
		{
			return TRUE;
		}else
		{
			return FILE_TYPE_ERROR;
		}
	}else
	{
		return FILE_TYPE_ERROR;
	}
}

