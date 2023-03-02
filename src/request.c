#include "libs/request.h"
#include "libs/logs.h"

#include <string.h>
#include <stdio.h>

Request_details get_details(char* request_header)
{
    Request_details details;

    char *client_http_header = strtok(request_header, "\n");
    char *header_token = strtok(client_http_header, " ");
    int header_parse_counter = 0;

    while (header_token != NULL)
    {
        switch (header_parse_counter)
        {
            case 0:
                details.method = header_token;
            case 1:
                details.route = header_token;
        }
        header_token = strtok(NULL, " ");
        header_parse_counter++;
    }

    printf("%s The method is %s\n", PREFIX_INFO, details.method);
    printf("%s The route is %s\n", PREFIX_INFO, details.route);

    return details;
}