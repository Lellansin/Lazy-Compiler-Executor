
#ifndef _FILE_H_
#define _FILE_H_

#define FILE_NUM_MAX 20
#define OPTION_NUM_MAX 20
#define OPTION_NAME_MAX 10
#define OPTION_PARAM_MAX 255

#define NOT_OPTION 100

int judgeType(const char *file_name, const char *file_type);

typedef struct __options
{
	char name[OPTION_NAME_MAX];
	char param[OPTION_PARAM_MAX];
} Coption;

extern int FileCount;
extern int OptionCount;
extern char *FileNames[FILE_NUM_MAX];
extern Coption *options[OPTION_NUM_MAX]; 

#endif
