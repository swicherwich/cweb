#include <stdio.h>
#include "libs/logs.h"

void log_info(const char* msg)
{
    printf("%s %s\n", PREFIX_INFO, msg);
}

void log_error(const char* msg)
{
    printf("%s %s\n", PREFIX_ERROR, msg);
}