#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/logs.h"
#include "libs/server.h"

#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

char* render_page();

int main(int argc, char** argv)
{
    int client_socket;

   http_server http_server;
   init_server(&http_server, 8080, 5);

    while (1)
    {
        log_info("Accepting client connection...");
        client_socket = accept(http_server.socket, NULL, NULL);

        if (client_socket < 0)
        {
            printf("%d\n", client_socket);
            log_error("Could not accept connection");
            return 1;
        }
        log_info("Connection accepted");

        char client_msg[4096];

        if (recv(client_socket, client_msg, 4096, 0) < 0)
        {
            log_error("Error receiving message");
            return 1;
        }

        printf("Msg from client: %s\n", client_msg);


        char* header = "HTTP/1.1 200 OK\r\n\r\n";
        log_info("Rendering page");
        char* body = render_page();
        log_info("Page is rendered");

        if (body == NULL) {
            log_error("Couldn't open static/index.html");
            return 1;
        }

        char* response = (char*)malloc(strlen(header) + strlen(body) + 1);
        strcat(response, header);
        strcat(response, body);

        log_info("Sending response");
        printf("%s", response);
        if (send(client_socket, response, strlen(response), 0) < 0)
        {
            log_error("Error sending message");
            return 1;
        }

        log_info("Message sent");

        close(client_socket);
    }

    return 0;
}

char* render_page() 
{
    FILE *page = fopen("../static/index.html", "r");

    if (page == NULL) {
        log_error("Couldn't open static/index.html");
        return NULL;
    }

    fseek(page, 0, SEEK_END);
    size_t file_size = ftell(page);
    fseek(page, 0, SEEK_SET);

    char* page_buff = (char*)malloc(file_size + 1);
    fread(page_buff, file_size, 1, page);

    fclose(page);

    return page_buff;
}