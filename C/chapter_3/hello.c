#include <stdio.h>
#include <string.h>

int main(){

    char s1[20]= {"firtreeformat"};
	char s2[20]={"dile.txt"};
    char s3[30],*p;
    int result;
    result = strcmp(s1,s2);

    // printf("length of s2 is %d\n", strlen(s1));
    printf("s1 and s2 is %d\n",result );
    strcat(s3, "/");
    printf("%s",strcat(s3,s2));  


}