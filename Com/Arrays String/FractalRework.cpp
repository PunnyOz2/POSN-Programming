/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<math.h>
char pic[1048][1048];
int main()
{
    int n,a,u,i,j;
    scanf("%d",&n);
    a = pow(2,n-1);
    for(i=0;i<2*a-1;i++){
        for(j=0;j<a;j++){
            pic[i][j]='-';
            }
        }
    u=0;
    for(i=0;i<2*a-1;i++){
        if(i%2==0){
            pic[i][u]='*';
            u++;
            }
    }
    for(i=0;i<2*a-1;i++){
        for(j=0;j<a;j++){
        if(i==a-1){
            pic[i][j]='*';
            u++;
            }
        }
    }
    u=0;
    for(i=0;i<2*a-1;i++){
        if(i%2==0){
            pic[i+1][u]='*';
            pic[i+1][u+1]='*';
            u++;
            }
    }
    u=0;
    for(i=0;i<2*a-1;i++){
        if(i%4==0){
            pic[i+3][u]='*';
            pic[i+3][u+1]='*';
            pic[i+3][u+2]='*';
            pic[i+3][u+3]='*';
            }
        if(i%2==0){
            u++;
        }
    }
    for(i=0,u=0;i<2*a-1;i++){
        if(i+1%8==0){
            pic[i][u]='*';
            pic[i][u+1]='*';
            pic[i][u+2]='*';
            pic[i][u+4]='*';
            pic[i][u+5]='*';
            pic[i][u+6]='*';
            pic[i][u+7]='*';
            pic[i][u+8]='*';
            }
        if(i%4==0){
            u++;
        }
    }
    for(i=0;i<2*a-1;i++){
        for(j=0;j<a;j++){
            printf("%c",pic[i][j]);
        }
        printf("\n");
    }
    return 0;
}
