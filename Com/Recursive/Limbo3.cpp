/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>
char a[1500][300];
int r,c,Max,ans;
void play(int i,int j){
    a[i][j]='.';
    if(j==0 && a[i][c-1]=='*') play(i,c-1);
    if(i==0 && a[r-1][j]=='*') play(r-1,j);
    if(j==c-1 && a[i][0]=='*') play(i,0);//////
    if(i==r-1 && a[0][j]=='*') play(0,j);//////
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
                play(i,j);
                ans++;
            }
        }
    }

    printf("%d",ans);
    return 0;
}
