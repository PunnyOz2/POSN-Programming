/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char name[25];
    int i;
    printf("Input words : ");
    gets(name);
    printf("String length = %d\n",strlen(name));
    printf("Without strrev = ");
    for(i=strlen(name);i>=0;i--){
        printf("%c",name[i]);
    }
    printf("\nWith strrev = %s",strrev(name));
    return 0;
}
