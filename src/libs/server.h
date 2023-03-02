#ifndef _SERVER_H__
#define _SERVER_H__

typedef struct http_server {
    int socket;
    int port;
} http_server;

void init_server(http_server *server, int port, int queue);

#endif