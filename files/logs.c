#include <stdio.h>

#define PREFIX_INFO "[INFO]"
#define PREFIX_ERROR "[ERROR]"

void log_info(const char* msg)
{
    printf("%s %s\n", PREFIX_INFO, msg);
}

void log_error(const char* msg)
{
    printf("%s %s\n", PREFIX_ERROR, msg);
}