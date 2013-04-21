
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lce.h"
#include "str.h"
#include "file.h"
#include "error.h"
#include "public.h"


char last_param[PARAM_MAX];
int is_record_param;

int main(int argc, char const *argv[])
{
	int i, n=0, result, ifsetOut=0;
	char cmd[CMD_MAX];
	char file_in[50]={0};
	char file_out[50]={0};
	char options[100]={0};

	if (argc == 1)
	{
		help();
		exit(0);
	}else if (argc == 2)
	{
		result = judgeType( argv[1], "c" );
		error_exit( result );

		// save c file path
		memmove(file_in, argv[1], strlen(argv[1]));
	}else if (argc > 2)
	{
		parseArg(argc, argv);
	}

	while(2+n < argc)
	{
		if( ifsetOut == 0 && strins(argv[2+n], "-o") == 0)
		{
			is_record_param = 1;
			ifsetOut = 1;
			n++;
			continue;
		}

		if (is_record_param == 1)
		{
			record_param(argv[2+n]);
			is_record_param = 0;
			n++;
			continue;
		}

		sprintf(options, "%s %s", options, argv[2+n]);
		n++;
	}

	if ( ifsetOut == 0 )
	{
		char *p = strrchr(argv[1], '.');
		if ( p != NULL )
		{
			*p = '\0';
			memmove(file_out, argv[1], strlen(argv[1]));
		}
	}else if (ifsetOut == 1)
	{
		// printf("manual set output %s\n", last_param);
		memmove(file_out, last_param, strlen(last_param));
	}

	sprintf(cmd, "gcc %s -o %s%s", file_in, file_out, options );
	printf("%s\n", cmd);


	system(cmd);

	return 0;
}


void record_param(const char *src)
{
	strcpy(last_param, src);
}



int error_exit(int error_num)
{
	switch(error_num)
	{
		case TRUE:
			return TRUE;
		break;

		case FILE_TYPE_ERROR:
			printf("file type error\n");
			exit(-1);
		break;
	}
}

void help()
{
    printf("Lazy compiler execute\n");
    printf("Usage: \n");
	printf("\tlce <C file> [options]\n");
    printf("Example: \n");
    printf("\tlce test.c -g\n");
}
