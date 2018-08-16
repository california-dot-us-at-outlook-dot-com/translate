/*#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<arpa/inet.h>

#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
#include<stdlib.h>

#include<stdio.h>
#include<string.h>
#include<netdb.h>
*/
#include "../demo/translate.h"
#define IP "127.0.0.1"
#define PORT 6666

int main(){
 int a=0;
 char *b="aaaaa";
 struct addrinfo *res,hints;                                                    //用域名domain连接
 memset(&hints,0,sizeof(hints));                                               //
 hints.ai_family=PF_UNSPEC;                                                   //
 hints.ai_socktype=SOCK_STREAM;                                              //
 getaddrinfo("api.fanyi.baidu.com","80",&hints,&res);                                 //
 int s=socket(res->ai_family,res->ai_socktype,res->ai_protocol);           //
 int con=connect(s,res->ai_addr,res->ai_addrlen);                         //
 printf("Domain connect %d\n",con);                                      //
 freeaddrinfo(res);                                                     //
/*
 printf("into main\n");

 int sd=socket(AF_INET,SOCK_STREAM,0);//Success>=0,Fail<0

 printf("socket %d\n",sd);
 
 struct sockaddr_in s_in;

 s_in.sin_family=AF_INET;

 s_in.sin_port=htons(PORT);

 s_in.sin_addr.s_addr=inet_addr(IP);

 int slen=sizeof(s_in);

// bzero(&(s_in.sin_zero),8);

 int conn=connect(sd,(struct sockaddr*)(&s_in),sizeof(struct sockaddr));//Success>=0,Fail<0

 printf("connect %d\n",conn);
*/
 char message[256]="GET /api/trans/vip/translate?q=apple&from=en&to=zh&appid=2015063000000001&salt=1435660288&sign=f89f9594663708c1605f3d736d01d2d4 HTTP/1.1\r\nHost:api.fanyi.baidu.com\r\n\r\n";

 send(s,message,strlen(message),0);
// sleep(1);
 char buf[2560];
 printf(">>>%s\n",message);
 printf("strLen:%d\n",strlen(message));
 int rec=recv(s,buf,sizeof(buf),0);
 printf("%s\n",buf);
 printf("recv return %d",rec);
 //close(sd);
 return 0;
 

}
