#ifndef _REQUEST_H__
#define _REQUEST_H__

typedef struct request_details {
    char* method;
    char* route;
} Request_details;

Request_details get_details(char* req_header);

#endif