/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[120][120],i,a[120],b[120],ch[120];
int play(int l,int r){
    if(l==r)return 1;
    if(l==r-1){
        if(a[l]<a[r]){
            return 2;
        }
        else return 1;
    }
    if(dp[l][r]!=-1)return dp[l][r];
    int Mi=1<<30,root,Ma=0;
    for(i=l;i<=r;i++){
        if(Mi>a[i])Mi=a[i],root=i;
    }
    if(root!=r){
        for(i=root+1;i<r;i++){
            Ma+=play(root+1,i)*play(i+1,r);
            printf("%d\n",Ma);
        }
    }
    if(l!=root){
        Ma*=(play(l,root-1));
    }
    printf("%d %d %d %d\n",l,r,root,Ma);
    return dp[l][r]=Ma;
}
int main()
{
    int n,m,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        b[num]=i;
        ch[i]=num;
    }
    memset(dp,-1,sizeof dp);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=b[a[i]];
        printf("%d ",a[i]);
    }
    printf("%d\n",play(1,n));
    return 0;
}
/*
6
5 4 0 1 2 3
4 5 1 0 2 3
*/
