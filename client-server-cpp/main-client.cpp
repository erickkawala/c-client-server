—//
//  main.cpp
//  lab2_client
//
//  Created by Erick Andrew Kawala on 3/17/16.
//  Copyright (c) 2016 Erick Andrew Kawala. All rights reserved.
//

#include <iostream>
#include <fstream>      // file open/close
#include <cstring>
#include <string>
#include <sys/socket.h> // socket functions
#include <netdb.h>      // socket functions
#include <netinet/in.h> // sockaddr_in struct



int main(int argc, char *argv[]) {
    
    // message buffer
    char array[256];
    
    // host entity info struct
    struct hostent *host;
    
    
    
    // get host information
    if ((host = gethostbyname(argv[1])) == NULL)
        
    {
        
        std::cout<<"gethostbyname failed\n";
        return 1;
        
    }
    
    // init address struct
    struct sockaddr_in my_addr;
    
    // init address with zeroes
    bzero((char*) &my_addr, sizeof(my_addr));
    
    // Use IPV4
    my_addr.sin_family = AF_INET;
    
    // Set the port to 8888
    my_addr.sin_port = htons(8888);
    
    // init my_addr with info returned from host entity info struct
    bcopy((char*) host->h_addr,(char *) &my_addr.sin_addr,host->h_length);
    
    
    
    // create UDP socket
    std::cout<<"Creating UDP socket \n";
    int Sockfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    //error returns -1
    if (Sockfd == -1)
        
    {
        std::cout<<"Unable to open socket \n";
        return 2;
    }
    
    //Poll forever
    int x;
    while ((x=1))
    {
        //Get message buffer
        std::cout << "Please enter a message to send to the server\n";
        std::cin>>array;
        
        //Send message buffer
        long int num_bytes = sendto(Sockfd, argv[2], 256, 0, (struct sockaddr*) & host,  sizeof(host));
        std::cout << "Sending " << num_bytes << "of data to server";
        //Receive message buffer from server with recvfrom
        //Print message from the server
    }
    
    
    return 0;
    
}
