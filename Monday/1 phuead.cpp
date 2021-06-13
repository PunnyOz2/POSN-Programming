/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],lis[100100],dp[100100],se[400100];
int query(int l,int r,int a,int b,int now){
    if(l>b || r<a)return 0;
    if(l>=a&&r<=b)return se[now];
    int mid=(l+r)/2;
    return max(query(l,mid,a,b,now*2),query(mid+1,r,a,b,now*2+1));
}
void update(int l,int r,int a,int b,int now){
    //printf("%d %d\n",l,r);
    if(l>a || r<a)return;
    if(l==r){se[now]=max(se[now],b);return;}
    int mid=(l+r)/2;
    update(l,mid,a,b,now*2),update(mid+1,r,a,b,now*2+1);
    se[now]=max(se[now*2],se[now*2+1]);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        //temp[i]=a[i];
    }
    for(i=1;i<=n;i++){
        if(a[i-1]<=a[i])lis[i]+=lis[i-1]+1;
        else lis[i]=1;
    }
    int Max=-1;
    for(i=1;i<=n;i++){
        //idx=upper_bound(temp+1,temp+n+1)
        dp[i]=lis[i]+lis[query(1,n,1,cou,1)+1];
        update(1,n,a[i],lis[i],1);
        Max=max(Max,dp[i]);
    }
    for(i=1;i<=n;i++)printf("%d ",dp[i]);
    printf("%d\n",Max);
    //for(i=1;i<=n;i++)printf("%d ",dp[i]);
    return 0;
}
/*
10
9 2 3 4 9 8 7 5 6 1
*/
