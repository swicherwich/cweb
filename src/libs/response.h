#ifndef _RESPONSE_H__
#define _RESPONSE_H__

#define HEADER "HTTP/1.0 200 OK"
#define HTML_CONTENT_TYPE "content-type: text/html"

char* response(char* html_file_name);
char* render_html(char* html_file_name);

#endif