#include "unp.h"

int Socket(int fam,int type,int pr){
	int n;
	if((n=socket(fam,type,pr))<0)
		err_sys("socket error");
	return n;

}

int Connect(int sockfd,struct sockaddr* addr,socklen_t addrlen){
	int n;
	if((n=connect(sockfd,(struct sockaddr*)addr,addrlen))<0)
		err_sys("connect error");
	return n;
}

int Close(int sockfd){
	int n;
	if((n=close(sockfd))<0)
		err_sys("close error");
	return n;
}



int Bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen){
	int n;
	if((n=bind(sockfd,(struct sockaddr * )addr,(socklen_t)addrlen))<0)
		err_sys("bind error");
	return n;
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
	int n;
	if((n=accept(sockfd,(struct sockaddr* )addr,addrlen))<0)
		err_sys("accept error");
	return n;
}

int Listen(int sockfd,int bl){
	int n;
	if((n=listen(sockfd,bl))<0)
		err_sys("listen error");
	return n;
}


ssize_t Write(int fd,const void* buf,size_t count){
	ssize_t n;
	if((n=write(fd,buf,count))<0)
		err_sys("write error");
	return n;

}

ssize_t Read(int fd,void *buf,size_t count){
	ssize_t n;
	if((n=read(fd,buf,count))<0)
		err_sys("read error");
	return n;


}

ssize_t Recv(int fd,void *buf,size_t len,int flags){
   ssize_t n;
   if((n=recv(fd,buf,len,flags))<0)
	  err_sys("recv error");
   return n;
}

ssize_t Send(int fd,const void *buf){
   ssize_t n;
   size_t len=sizeof(buf);
   int flags=0;
   if((n=send(fd,buf,len,flags))<0)
	  err_sys("recv error");
   return n;
}

