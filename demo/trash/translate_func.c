#include "translate.h"

char* connect_and_return_json(char* message){

 struct addrinfo *res,hints;
 memset(&hints,0,sizeof(hints));
 hints.ai_family=PF_UNSPEC;
 hints.ai_socktype=SOCK_STREAM;
 getaddrinfo(Domain,Port,&hints,&res);
 int s=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
 int con=connect(s,res->ai_addr,res->ai_addrlen);
 char *buf=(char*)malloc(2560);
 printf("connect %d",con);
 if(con<0){
  return buf;
 }
 freeaddrinfo(res);

 send(s,message,strlen(message),0);
 
 int ifrecv=recv(s,buf,sizeof(buf),0);
 if(recv!=0){
  return buf;
 }
 else{
  return buf;
 }
}

int* json_to_unicode(char*json){
 printf("%s",json);
 int i,j;
 /*[Unicode,Unicode]*/
 for(i=0;(json[i]!='d'||json[i+1]!='s'||json[i+2]!='t')&&i<strlen(json)-2;i++){
 }
 for(j=0;(json[j]!='}')&&j<strlen(json);j++){
 }
 int a,b;
 a=i+7;
 b=j-1;
 char uni[2560];
 for(int i=0;i<b-a;i++){
  uni[i]=json[i+a];
  if(i==(b-a-1)){
   uni[i+1]='\0';
  }
 }
 //char[2560]uni======"\uxxxx\uxxxx\uxxxx"

 int zi_size=0;
 for(int i=0;i<strlen(uni);i++){
  if(uni[i]=='\\'){
   zi_size++;
  }
 }
 
 char bianma[zi_size][4];
 int tmpptr=0;
 for(int i=0;i<strlen(uni);i++){
  if(uni[i]=='\\'){
   for(int j=0;j<4;j++){
    bianma[tmpptr][j]=uni[i+2+j];
   }
   tmpptr++;
  }
 }
 //char bianma[zi_size][4]======[['1','2','3','4'],['4','5','a','g']...['3'.'2'.'c'.'5']]
 int pow[4];
 pow[0]=4096;
 pow[1]=256;
 pow[2]=16;
 pow[3]=1;
 int *zi=(int*)malloc((zi_size+1)*sizeof(int));
 for(int i=0;i<zi_size;i++){
  for(int j=0;j<4;j++){
   if((int)bianma[i][j]<58){
    zi[i]+=((int)bianma[i+1][j]-48)*pow[j];
   }
  }
 }
 zi[0]=zi_size;
 return zi;
}


