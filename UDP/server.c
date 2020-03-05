#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	//yaha pe hum socket bana rahe  socket
	int ret = socket(AF_INET, SOCK_DGRAM, 0);
	//yaha pe hum populate values
	struct sockaddr_in mySock;
	mySock.sin_port = htons(5000);
	mySock.sin_addr.s_addr = INADDR_ANY;
	mySock.sin_family= AF_INET;
	
	//bind API
	int status = bind(ret, (const struct sockaddr *)(&mySock), sizeof(mySock));
	
	printf("If you want to end your message system then please type 'exit'...\n");
		
	while(1){
		//recvfrom()
		char received[100]="";
		struct sockaddr_in srcsock; 
		int len = sizeof(srcsock);
		recvfrom(ret, received, sizeof(received), 0, (struct sockaddr *)(&srcsock), &len);
		printf("\nMessage is :- %s\n",received);
		if(strcmp(received, "exit")==0 || strcmp(received, "exit")==0 || strcmp(received, "exit")==0){
			break;		
		}
		
		//sendto()
		char send[100]="";
		printf("\nEnter the message you want to send :- ");	
		scanf("\n%s",send);
		struct sockaddr_in destsock;
		destsock.sin_port = htons(8000);
		destsock.sin_addr.s_addr = INADDR_ANY;
		destsock.sin_family= AF_INET;
		sendto(ret, (const void*)send, strlen(send), 0, (const struct sockaddr*)(&destsock), sizeof(destsock));
		printf("\nmessage sent is :- %s\n", send);
		if(strcmp(send, "exit")==0 || strcmp(send, "exit")==0 || strcmp(send, "exit")==0){
			break;		
		}
	}
	
	close(ret);
	
	return 0;
}
