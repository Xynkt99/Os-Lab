#include "../utils/unp.h"
#include "../utils/error.c"
#include "../utils/wrapsock.c"
#include<pthread.h>  // mulit-threading
#include<fcntl.h>

#define PATH "data/"

void *doRecv(void *sockfd){
	int fd=*((int *)sockfd);
	while(1){
		char buf[MAXLINE+1];

		int n=Read(fd,buf,MAXLINE);
		buf[n]=0;
		printf("----->\n%s\r\n",buf);

	}

}

void waitRandom(int time){
  int rand_time=rand()%time;
  int sec=rand()%2;
  struct timespec _t={sec,rand_time};
  usleep(rand_time);

}


int main(int argc, char const *argv[])
{
   int sockfd,n;
   struct sockaddr_in servaddr;

   if(argc!=2){
   	err_quit("Usage ./client <PORT>");
   }

   sockfd=Socket(AF_INET,SOCK_STREAM,0);



   bzero(&servaddr,sizeof(servaddr));
   servaddr.sin_family=AF_INET;
   servaddr.sin_port=htons(atoi(argv[1]));

   servaddr.sin_addr.s_addr=INADDR_ANY; 
   // connect to any ipaddr

   // if(inet_pton(AF_INET,&argv[1],&servaddr.sin_addr)<=0)
		// err_quit("inet_pton error for %s",argv[1]);

   Connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

   fprintf(stderr,"---Connection Established---");
   send(sockfd,"consumer",sizeof("consumer"),0);
   int resp=1,req=0;
   do{
    waitRandom(100000);
    int num;
    int timeout=100;
    fprintf(stderr, "------------------------------>Willing to consume from buffer\n");
    while(timeout<=1e5){
      fprintf(stderr, "Trying to consume with timeout %dmus\n",timeout);

      req=1;
      n=send(sockfd,&req,sizeof(req),0);

      struct timeval tv;
      timeout=rand()%10111+100000;  //exponential backoff for timeout 
      tv.tv_sec=0;
      tv.tv_usec=timeout;
      setsockopt(sockfd,SOL_SOCKET,SO_RCVTIMEO,(const char*)&tv,sizeof(tv));

      resp=0;
      n=recv(sockfd,&resp,sizeof(resp),0); //adawd
      usleep(timeout);
      if(resp!=1)continue;

      // add blocking
      n=recv(sockfd,&num,sizeof(num),0);
      fprintf(stderr, "-------------------->Successfully consumed the number %d\n",num);
      break;
    }

   }while(1);

	return 0;
}
