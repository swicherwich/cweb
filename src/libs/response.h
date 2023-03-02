#ifndef _RESPONSE_H__
#define _RESPONSE_H__

#define HEADERS "HTTP/1.0 200 OK\r\n\r\n"
#define HTML_CONTENT_TYPE "Content-Type: text/html\r\n\r\n"

char* response(const char* html_file_name);
char* render_html(const char* html_file_name);

#endif