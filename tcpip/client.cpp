#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr; 

    if(argc != 2)
    {
        printf("\n Usage: %s <ip of server> \n",argv[0]);
        return 1;
    } 

    memset(recvBuff, '0',sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000); 

    const char *server_address = argv[1]; //is an IPv4 network address

    int address_family = AF_INET;
    int address_conversion_outcome = inet_pton(address_family, server_address, &serv_addr.sin_addr);
    //converts server_address into a network address structure in the af address family
    //then copies the network address structure to dst.

    if(address_conversion_outcome<0) 
    {
        cout << address_family << " is not a  a valid address family.\n";
        return 1;
    } 
    else if(address_conversion_outcome==0) 
    {
        cout << server_address << " is a character string representing a valid network address in the address family " <<address_family << endl;
        return 1;
    } 
    else if(address_conversion_outcome==1) 
    {
        cout << server_address << "success of the address conversion."<< endl;
    } 
    else
    {
        cout << "This should never happen !!!"<< endl;
        return 1;
    }

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return 1;
    } 

    while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }
    } 

    if(n < 0)
    {
        printf("\n Read error \n");
    } 

    return 0;
}