#include "translate.h"


int main(){
 char origindd[2560];
 printf("please input an English Word:>> ");
 scanf("%s\0",&origindd);
 char *appiddd="20180814000194109";
 char *passwddd="D3RNNJBRSCVrN4qFMtPV";
 char *saltdd="1435660288";
 struct addrinfo *res,hints;
 memset(&hints,0,sizeof(hints));
 hints.ai_family=PF_UNSPEC;
 hints.ai_socktype=SOCK_STREAM;
 getaddrinfo(Domain,Port,&hints,&res);

 // char *buf=origin_to_message(appiddd,origindd,saltdd,passwddd);
 // char*json= connect_and_return_json(buf,res);
 // char *uni=json_to_unicode(json);
 // char *origin=json_to_origin(json);
 // char *zi=unicode_to_chinese(uni);
 char *zi;
 if(origindd[0]=='\\'){
  zi=C2E(appiddd,origindd,saltdd,passwddd,res);
 }else{
  zi=E2C(appiddd,origindd,saltdd,passwddd,res);
 }
 printf(">>>  | %s\n",zi);

return 0;
}

