#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
int main(){
 char str[6];
 int sa[2]={12,23};
 char *sth="\u82f9";
// printf("dddddd%s",sth);
// str[0]='\\';
// printf(">>>%c\n",str[0]);
 int a=0x82f9;
 wchar_t wstr[]={a};
 setlocale(LC_ALL,"");
 wcstombs(str,wstr,sizeof(str)/sizeof(char));
 printf("%s\n",str);
// printf(">>>>>str_size:%d\n",sizeof(str));
// printf(">>>>>cahr_ize:%d\n",sizeof(char));

 return 0;
}
