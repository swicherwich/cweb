#ifndef _LOGS_H__
#define _LOGS_H__

#define PREFIX_INFO "[INFO]"
#define PREFIX_ERROR "[ERROR]"
#define TIME_FORMAT "[]"

void log_info(char* fmt, ...);
void log_error(char* fmt, ...);

#endif