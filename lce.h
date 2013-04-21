
#ifndef _LCE_H_
#define _LCE_H_

#define CMD_MAX 300
#define PARAM_MAX 10  

void help();
int error_exit(int error_num);
void record_param(const char *src);

#endif
