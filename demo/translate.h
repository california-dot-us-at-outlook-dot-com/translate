#ifndef translate_h
#define translate_h

#include "md5/md5.h"
#include<stdio.h>
#include<gtk/gtk.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

#define Domain "api.fanyi.baidu.com"
#define Port "80"

char* connect_and_return_json(char*,struct addrinfo*);
char* json_to_unicode(char*);
char* unicode_to_chinese(char*);
char* json_to_origin(char*);
char* origin_to_message(char*,char*,char*,char*);
char* unicode_to_chinese(char*);
char* json_to_english(char*);
char* E2C(char*,char*,char*,char*,struct addrinfo*);
char* C2E(char*,char*,char*,char*,struct addrinfo*);
#endif
