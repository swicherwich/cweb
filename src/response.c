#include "libs/response.h"
#include "libs/logs.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char* render_html(const char* html_file_name);

char* create_response(const char* html_file_name)
{
    char* body = render_html(html_file_name);

    char* response = (char*) malloc(strlen(HEADERS) + strlen(body));

    strcat(response, HEADERS);
    strcat(response, body);

    return response;
}

char* render_html(const char* html_file_name)
{
    char dir[128] = {};
    strcat(dir, "../static/");
    strcat(dir, html_file_name);

    log_info("Rendering page...");
    FILE *file = fopen(dir, "r");

    if (file == NULL) {
        log_error("File static/%s does not exists", html_file_name);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* file_buff = (char*) malloc(file_size + 1);

    if (fread(file_buff, file_size, 1, file) < 0) {
        log_error("Error reading file %s", html_file_name);
    }
    log_info("Page is rendered");

    fclose(file);


    return file_buff;
}