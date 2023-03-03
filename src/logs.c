#include "libs/logs.h"

#include <stdio.h>
#include <stdarg.h>


void log_info(char* fmt, ...)
{
    char buf[100];

    va_list vl;
    va_start(vl, fmt);

    vsnprintf(buf, sizeof(buf), fmt, vl);

    va_end(vl);

    printf("%s %s\n", PREFIX_INFO, buf);
}

void log_error(char* fmt, ...)
{
    char buf[100];

    va_list vl;
    va_start(vl, fmt);

    vsnprintf(buf, sizeof(buf), fmt, vl);

    va_end(vl);

    printf("%s %s\n", PREFIX_ERROR, buf);
}