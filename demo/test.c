#include "translate.h"


#include<sys/socket.h>
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


int main(){
 char *origindd="apple";
 char *appiddd="2015063000000001";
 char *passwddd="12345678";
 char *saltdd="1435660288";
 struct addrinfo *res,hints;
 memset(&hints,0,sizeof(hints));
 hints.ai_family=PF_UNSPEC;
 hints.ai_socktype=SOCK_STREAM;
 getaddrinfo(Domain,Port,&hints,&res);

 char *buf=origin_to_message(appiddd,origindd,saltdd,passwddd);
 char*json= connect_and_return_json(buf,res);
 char *uni=json_to_unicode(json);
 char *origin=json_to_origin(json);
 char *zi=unicode_to_chinese(uni);
 printf(">>>%s | %s\n",origin,zi);

return 0;
}

