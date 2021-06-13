/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[7010][7010];
int t[7010][7010],cou[7010];
struct A{
    int i,j;
};
queue<A> q;
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(j=1;j<=m;j++){
            t[i][j]=1<<30;
            if(a[i][j]=='0')t[i][j]=0;
        }
    }
    for(i=n;i>=1;i--){
        for(j=m;j>=1;j--){
            t[i][j]=min(t[i][j],t[i+1][j+1]+1);
            t[i][j]=min(t[i][j],t[i][j+1]+1);
            t[i][j]=min(t[i][j],t[i+1][j]+1);
        }

    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cou[t[i][j]]++;
        }
    }
    for(i=min(n,m);i>=1;i--){
        cou[i]+=cou[i+1];
    }
    for(i=1;i<=min(n,m);i++){
        printf("%d\n",cou[i]);
    }
    return 0;
}
/*

*/
