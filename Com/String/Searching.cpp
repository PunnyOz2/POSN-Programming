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
    char s;
    int no;
    printf("Input words : ");
    gets(name);
    printf("Input char : ");
    scanf("%c",&s);
    for(i=0;i<strlen(name);i++){
        if(name[i]==s){
            no=1;
            break;
        };
    }
    if(no==1){
        printf("contain");
    }
    else if(no==0){
        printf("notcontain");
    }

    else{
        printf("notcontain");
    }
    return 0;
}
