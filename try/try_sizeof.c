#include<stdio.h>
#include<stdlib.h>
int main(){
 int *a=(int*)malloc(23*sizeof(int));
 printf(">>>>a=%d,*a=%d",sizeof(a),sizeof(*a));
 return 0;
}
