/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
int main()
{
    int Round;
    int n,i,j,x,a=0;
    scanf("%d",&n);
    while(n--){
    scanf("%d",&Round);
    int y =Round-2;
    for(x=0;x<3;x++){
        for(j=0;j<Round;j++){
            printf("*");
        }
        printf("-");
        }
    printf("*");
    for(j=0;j<y;j++){
        printf("-");
    }
    printf("*\n");
    //////////////////////////////////
    for(i=0;i<(Round-3)/2;i++){
        printf("*");
        for(x=0;x<Round-2;x++)
            printf("-");
        printf("*");
        printf("-");
        printf("*");
        for(x=0;x<Round-2;x++)
            printf("-");
        printf("*");
        printf("-");
        printf("*");
        for(x=0;x<Round-2;x++)
            printf("-");
        printf("-");
        printf("-");
        printf("*");
        for(x=0;x<Round-2;x++){
            if(x==a){
                printf("*");
            }
            else {
                printf("-");
            }
        }
        printf("*");
        a++;
    printf("\n");
    }
    ////////////////////////////////
    for(j=0;j<Round;j++){
        printf("*");
        }
    printf("-*");
        for(j=0;j<Round-2;j++){
            printf("-");
        }
        printf("*");
        printf("-");

        for(j=0;j<Round;j++)
            printf("*");
        printf("-");
        printf("*");

        for(x=0;x<Round-2;x++){
            if(x==a){
                printf("*");
            }
            else {
                printf("-");
            }
        }
        printf("*");
        a++;
        printf("\n");
    ///////////////////////////////////////////////
        for(i=0;i<(Round-3)/2;i++){
            printf("*");
        for(x=0;x<Round-2;x++)
            printf("-");
        printf("-");
        printf("-");
        printf("*");
        for(x=0;x<Round-2;x++)
            printf("-");
        printf("*");
        printf("-");
        for(x=0;x<Round-1;x++)
            printf("-");
        printf("*");
        printf("-");
        printf("*");
        for(x=0;x<Round-2;x++){
            if(x==a){
                printf("*");
            }
            else {
                printf("-");
            }
        }
        printf("*");
        a++;
        printf("\n");
        }
        //////////////////////////////////
        printf("*");
        for(x=0;x<Round;x++)
            printf("-");
        for(x=0;x<2;x++){
        for(j=0;j<Round;j++){
            printf("*");
        }
        printf("-");
        }
    printf("*");
    for(j=0;j<y;j++){
        printf("-");
    }
    printf("*\n");
    a=0;
    }
    return 0;
}
