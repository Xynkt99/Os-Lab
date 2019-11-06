#include<sys/stat.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<arpa/inet.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/un.h>
#include<stdlib.h>
#include<unistd.h>

// #ifndef HAVE_BZERO
// #define bzero(ptr,n)	memest(ptr,0,n)
// #endif

#ifndef HAVE_GETHOSTBYNAME2
#define gethostbyname2(host,family)	gethostbyname(host)
#endif

#ifdef HAVE_SYS_IOCTL_H
#include<sys/ioctl.h>
#endif

#define MAXLINE 4096
#define BUFFSIZE 8192

#define PROD_TOKEN 0
#define CONS_TOKEN 1
#define min(a,b) ( (a) < (b) ? (a) : (b)) 
#define max(a,b) ( (a) > (b) ? (a) : (b)) 



