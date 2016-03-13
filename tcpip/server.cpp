/*
a thread is created for each client.
the new thread is push to the v_threads
I need to reuse ended threads.
*/


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

#include <iostream> 
#include <thread> 
#include <vector> 
using namespace std;

void fn_sendtime(int connfd);

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 

    listenfd = socket(AF_INET, SOCK_STREAM, 0); //creates an UN-named socket inside the kernel
    //AF_INET For Internet family of IPv4 addresses we use AF_INET.
    //‘SOCK_STREAM’ the transport layer protocol needed should be reliable ie it should have acknowledgement techniques. For example : TCP
    //0 to let the kernel decide of the default protocol to use for this connection. For reliable connections, the default protocol used is TCP.
    // listenfd is integer known as socket descriptor.


    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET; //the family/domain
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);//the interface to listen on (in case the system has multiple interfaces to network)
    serv_addr.sin_port = htons(5000); //the port on which the server will wait for the client requests to come.

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
    //assigns the details specified in the structure ‘serv_addr’ to the socket listenfd.

    listen(listenfd, 10); 
    //10 is maximum number of client connections that server will queue for this listening socket.
    //Q-what happens if more than 10 ? 
    //after listen, listenfd becomes a fully functional socket

    cout << "Server: i am is up and running. Waiting for client ...\n";
    //

    std::vector<std::thread> v_threads;

    while(1)
    {
    	cout << "Server: waiting for a client to connect ...\n";

        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
        //the server is put to sleep
        //it is awaiken when the three way TCP handshake* is complete for an incoming client request
        // connfd is the socket descriptor representing the client socket.

    	//create thread;
    	v_threads.push_back(std::thread(fn_sendtime,connfd)); 

    	cout << "Server: client " << v_threads.size() << " is in connection ...\n";


    	//loop back;
    	//when ending, join all of them, release resources

        sleep(1);
     }
}


void fn_sendtime(int connfd)
{
    char sendBuff[1025];
    time_t ticks; 

	ticks = time(NULL);
	snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
	write(connfd, sendBuff, strlen(sendBuff)); 

	close(connfd);
}