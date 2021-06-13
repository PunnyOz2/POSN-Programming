/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<ctype.h>
int main()
{
    char a,b,c,d,e;
    scanf("%c %c",&a,&b);
    c=tolower(a);
    d=toupper(b);
    printf("%c %c",c,d);
    e=a+32;
    printf(" %c",e);

    return 0;
}
