#ifndef _LOGS_H__
#define _LOGS_H__

#define PREFIX_INFO "[INFO]"
#define PREFIX_ERROR "[ERROR]"

void log_info(const char* msg);
void log_error(const char* msg);

#endif