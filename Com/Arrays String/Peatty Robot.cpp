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
    int x=0,y=0;
    char N,S,E,W,Z,i;
    char a[200];
    scanf("%s",a);
    int len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='N'){
            y++;
        }
        else if(a[i]=='S'){
            y--;
        }
        else if(a[i]=='W'){
            x--;
        }
        else if(a[i]=='E'){
            x++;
        }
        else if(a[i]=='Z'){
            x=0;
            y=0;
        }
    }
    printf("%d %d",x,y);
    return 0;
}
