//
//  main.cpp
//  lab2_server
//
//  Created by Erick Andrew Kawala on 3/17/16.
//  Copyright (c) 2016 Erick Andrew Kawala. All rights reserved.

#include <iostream>
#include <fstream>      // file open and close
#include <cstring>
#include <string>
#include <sys/socket.h> // socket functions
#include <sys/types.h>
#include <netdb.h>      // socket functions
#include <netinet/in.h> //sockaddr_in struct

#define ECHO_MAX 256

int main(int argc, const char * argv[]) {
    
    //declare address struct
    struct sockaddr_in server_addr, client_addr;
    unsigned int clilen;
    int rcvmsgsize;
    char echoBuffer[ECHO_MAX];
    
    // init address structure with zeroes
    bzero((char*) &server_addr, sizeof(server_addr));
    // set to internet address family
    server_addr.sin_family = AF_INET;
    // work with any incoming interface
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8888);
    
    // create UDP socket
    int Sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_UDP);
    // handle socket error
    if (Sockfd == -1)
    {
        std::cout<<"Unable to open socket \n";
        return 1;
    }
    
    // bind to the local address
    if (bind(Sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
    {
        std::cout<<"Unable to Bind to local address\n";
        return 2;
    }
    
    int x;
    
    while ((x=1))
    {
        clilen = sizeof(client_addr);
        
        if((rcvmsgsize = recvfrom(Sockfd, echoBuffer, ECHO_MAX, 0,(struct sockaddr *) &client_addr,
                                  &clilen)) <0)
        {
            std::cout<<"Unable to receive message from client\n";
            return 3;
        }
        std::cout<<"Receiving message from client\n";
        std::cout << echoBuffer <<"\n";
        
    }
    
    
    
    return 0;
}

