/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char ans[5000],anss[5000],a[2100][2100];
int n,m,i,j;
void play(int i,int j){
    printf("%d %d\n",i,j);
    if(i>=n || j>=m)return;
    printf("    %d %c %d %c\n",a[i+1][j],a[i+1][j],ans[i+j+1],ans[i+j+1]);
    printf("    %d %c %d %c\n",a[i][j+1],a[i][j+1],ans[i+j+1],ans[i+j+1]);
    if(i+1<n && (a[i][j+1]==0||a[i][j+1]>=a[i+1][j]) && a[i+1][j]<=ans[i+j+1]){
        ans[i+j+1]=a[i+1][j];
        play(i+1,j);
    }
    if(j+1<m && (a[i+1][j]==0||a[i][j+1]<=a[i+1][j]) && a[i][j+1]<=ans[i+j+1]){
        ans[i+j+1]=a[i][j+1];
        play(i,j+1);
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=0;i<=4200;i++){
        ans[i]=127;
    }
    play(0,0);
    ans[0]=a[0][0];
    for(i=0;i<n+m-1;i++)
        printf("%c",ans[i]);
    return 0;
}
/*
2 3
abe
bff

2 3
abe
bff
*/
