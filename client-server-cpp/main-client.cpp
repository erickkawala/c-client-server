—//
//  main.cpp
//  lab2_client
//
//  Created by Erick Andrew Kawala on 3/17/16.
//  Copyright (c) 2016 Erick Andrew Kawala. All rights reserved.
//

#include <iostream>
#include <fstream>      //For opening and closing files
#include <cstring>
#include <string>
#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <netinet/in.h> //For sockaddr_in struct



int main(int argc, char *argv[]) {
    
    //The array we will use to capture the message entered by the user
    char array[256];
    
    //create the struct that will contain the host information
    struct hostent *host;
    
    
    
    //Get the information
    if ((host = gethostbyname(argv[1])) == NULL)
        
    {
        
        std::cout<<"gethostbyname failed\n";
        return 1;
        
    }
    
    //Initialize the address structure
    struct sockaddr_in my_addr;
    
    //Initialize our address structureth zeroes
    bzero((char*) &my_addr, sizeof(my_addr));
    
    //Use IPV4
    my_addr.sin_family = AF_INET;
    
    //Set the port to 8888
    my_addr.sin_port = htons(8888);
    
    //Initialing my_addr with info returned to hostent host struct
    bcopy((char*) host->h_addr,(char *) &my_addr.sin_addr,host->h_length);
    
    
    
    // Create a socket, use UDP
    
    std::cout<<"Creating a socket \n";
    int Sockfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP); //if returns -1, unable
    
    
    
    //Make sure the socket opened
    
    if (Sockfd == -1)
        
    {
        std::cout<<"Unable to open socket \n";
        return 2;
    }
    
    int x;
    
    //Loop forever
    while ((x=1))
    {
        //Get the message from the user
        std::cout << "Please enter a message to send to the server\n";
        std::cin>>array;
        
        //Send messag to the server
        long int num_bytes = sendto(Sockfd, argv[2], 256, 0, (struct sockaddr*) & host,  sizeof(host));
        std::cout<<"Sending "<<num_bytes<<"of data to server";
        //Receive message from the server recvfrom
        
        
        //Print message from the server
    }
    
    
    return 0;
    
}
