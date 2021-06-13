/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int Min[210][210],Max[210][210],a[210][210];
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=m;i++)Min[n+1][i]=1<<30;
    for(i=1;i<=n;i++)Min[i][0]=1<<30;
    for(i=n;i>=1;i--){
        for(j=1;j<=m;j++){
            Max[i][j]=max(Max[i+1][j],Max[i][j-1])+a[i][j];
            if(i==n && j==1)Min[i][j]=a[i][j];
            else Min[i][j]=min(Min[i+1][j],Min[i][j-1])+a[i][j];
        }
    }
//    for(i=1;i<=n;i++){
//        for(j=1;j<=m;j++)printf("%d ",Min[i][j]);
//        printf("\n");
//    }
    printf("%d\n",Max[1][m]-Min[1][m]);
    return 0;
}
/*

*/
