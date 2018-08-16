#include "translate.h"


char* connect_and_return_json(char* message,struct addrinfo *res){
 int s=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
 int con=connect(s,res->ai_addr,res->ai_addrlen);
 freeaddrinfo(res);
 char *buf=(char*)malloc(sizeof(char)*2560);
 send(s,message,strlen(message),0);
 int ifrecv=recv(s,buf,sizeof(char)*2560,0);
 if(recv!=0){
  return buf;
 }
 else{
  return buf;
 }
}

char* json_to_unicode(char*json){
 int i,j;
 for(i=1;(json[i-1]!='"'||json[i]!='d'||json[i+1]!='s'||json[i+2]!='t'||json[i+3]!='"')&&i<strlen(json)-3;i++){
 }
 for(j=0;(json[j]!='}')&&j<strlen(json);j++){
 }
 int a,b;
 a=i+6;
 b=j-1;
 char *uni=malloc(b-a+1);
 for(int i=0;i<b-a;i++){
  uni[i]=json[i+a];
  if(i==(b-a-1)){
   uni[i+1]='\0';
  }
 }
 return uni;
}

char* unicode_to_chinese(char*uni){
 printf("chinese-uni:%s\n",uni);
 int zi_size=0;
 for(int i=0;i<strlen(uni);i++){
  if(uni[i]=='\\'){
   zi_size++;
  }
 }
 printf("zishu_%d\n",zi_size);
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
 printf("bianma_size:%d\n",tmpptr);
 //char bianma[zi_size][4]======[['1','2','3','4'],['4','5','a','g']...['3'.'2'.'c'.'5']]
 int pow[4];
 pow[0]=4096;
 pow[1]=256;
 pow[2]=16;
 pow[3]=1;
 int *zi=(int*)malloc((zi_size+1)*sizeof(int));
 for(int i=0;i<zi_size+1;i++){
  *(zi+i)=0;
 }
 for(int i=0;i<zi_size;i++){
  for(int j=0;j<4;j++){
   if(bianma[i][j]<58){
    zi[i+1]+=((bianma[i][j])-48)*pow[j];
   }
   if(bianma[i][j]>96){
    zi[i+1]+=((bianma[i][j])-87)*pow[j];
   }
  }
  printf("zi[]:%d\n",zi[i+1]);

 }
 zi[0]=zi_size;
 //zi[]=====[int size,int unicode,int unicode,........,int unicode]
 char *chinese=(char*)malloc(sizeof(char)*6*(zi_size+1));
 chinese[zi_size]='\0';
 wchar_t wstr[zi_size];
 for(int i=0;i<zi_size;i++){
  wstr[i]=zi[i+1];
 }
 setlocale(LC_ALL,"");

 wcstombs(chinese,wstr,zi_size*3);
 printf("chinese:%s\n",chinese);
 return chinese;
}

char* json_to_origin(char*json){
 int i,j;
 for(i=0;(json[i]!='s'||json[i+1]!='r'||json[i+2]!='c'||json[i+3]!='"')&&i<strlen(json)-3;i++){
 }
 for(j=1;(json[j-1]!=','||json[j]!='"'||json[j+1]!='d'||json[j+2]!='s'||json[j+3]!='t');j++){
 }
 int a,b;
 a=i+6;
 b=j-2;
 char *uni=malloc(sizeof(char)*2560);
 for(int i=0;i<b-a;i++){
  uni[i]=json[i+a];
  if(i==(b-a-1)){
   uni[i+1]='\0';
  }
 }
 printf("uni:%s\n",uni);
 return uni;
}

char* origin_to_message(char*appid,char*origin,char*salt,char*passwd){
 //str1=appid+origin+salt+passwd
 //sign=md5(str1)
 //message=/api/trans/vip/translate?q=apple&from=en&to=zh&appid=2015063000000001&salt=1435660288&sign=f89f9594663708c1605f3d736d01d2d4
 char str1[strlen(appid)+strlen(origin)+strlen(salt)+strlen(passwd)+1];
 strcpy(&(str1[0]),appid);
 strcpy(&(str1[strlen(appid)]),origin);
 strcpy(&(str1[strlen(appid)+strlen(origin)]),salt);
 strcpy(&(str1[strlen(appid)+strlen(origin)+strlen(salt)]),passwd);
 str1[strlen(appid)+strlen(origin)+strlen(salt)+strlen(passwd)]='\0';
 unsigned char sign1[16];
 char sign[33];
 MD5_CTX md5;
 MD5Init(&md5);
 MD5Update(&md5,str1,strlen((char*)str1));
 MD5Final(&md5,sign1);
 for(int i=0;i<16;i++){
  sprintf(&(sign[2*i]),"%02x",sign1[i]);
 }
 sign[32]='\0';
 //sign ==sign
 char *api_1="GET /api/trans/vip/translate?q=";//origin
 char *api_2="&from=en&to=zh&appid=";//appid
 char *api_3="&salt=";//salt
 char *api_4="&sign=";//sign
 char api_5[50]=" HTTP/1.1\r\nHost:api.fanyi.baidu.com\r\n\r\n";
 int strLen=strlen(api_1)+strlen(api_2)+strlen(api_3)+strlen(api_4)+strlen(api_5)+strlen(origin)+strlen(appid)+strlen(salt)+strlen(sign);
 char *message=(char*)malloc(sizeof(char)*(strLen+1));
 for(int i=0;i<strLen+1;i++){
  *(message+i)='\0';
 }
 strcat(message,api_1);
 strcat(message,origin);
 strcat(message,api_2);
 strcat(message,appid);
 strcat(message,api_3);
 strcat(message,salt);
 strcat(message,api_4);
 strcat(message,sign);
 strcat(message,api_5);
 message[strLen]='\0';
 return message;
 
}
