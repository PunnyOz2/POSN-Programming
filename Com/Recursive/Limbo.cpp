/*
    TASK: Limbo
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
char a[1500][300];
int r,c,cou,Max;
void play(int i,int j){
    a[i][j]='.',cou++;
    if(i-1>=0 && a[i-1][j]=='*')play(i-1,j);
    if(j-1>=0 && a[i][j-1]=='*')play(i,j-1);
    if(i+1<r && a[i+1][j]=='*')play(i+1,j);
    if(j+1<c && a[i][j+1]=='*')play(i,j+1);
}
int main()
{
    int i,j;
    scanf("%d %d",&c,&r);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf(" %c",&a[i][j]);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]=='*'){
                cou = 0;
                play(i,j);
                if(cou>Max)
                    Max=cou;
            }
        }
    }
    printf("%d",Max);
    return 0;
}
