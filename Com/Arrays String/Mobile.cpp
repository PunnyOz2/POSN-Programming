/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
#include<stdlib.h>
int a[50][50];
int main()
{
    int H,W,q,Max,ansi,ansj,i,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&H,&W);
        for(i=1;i<=H;i++){
            for(j=1;j<=W;j++){
                scanf("%d",&a[i][j]);
            }
        }
        Max=-1000,ansi=ansj=1;
        for(i=1;i<=H;i++){
            for(j=1;j<=W;j++){
                if(i+1<=H&&abs(a[i][j]-a[i+1][j])<=10&&a[i][j]+a[i+1][j]>Max){
                    Max=a[i][j]+a[i+1][j];ansi=i;ansj=j;}
                if(j+1<=W&&abs(a[i][j]-a[i][j+1])<=10&&a[i][j]+a[i][j+1]>Max){
                    Max=a[i][j]+a[i][j+1];ansi=i;ansj=j;}
                }
            }
            printf("%d %d\n",ansi,ansj);

        }



    return 0;
}
