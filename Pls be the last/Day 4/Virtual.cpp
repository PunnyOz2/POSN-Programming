/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int se[400100],st[100100],lazy[400100];
void update(int l,int r,int a,int b,int now,int c){
    if(r<a||l>b)return;
    if(lazy[now]){
        se[now]+=lazy[now]*(r-l+1);
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        lazy[now]=0;
    }
    if(l>=a && r<=b){
        se[now]+=(c*(r-l+1));
        if(l!=r){
            lazy[now*2]+=c;
            lazy[now*2+1]+=c;
        }
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,a,b,now*2,c);
    update(mid+1,r,a,b,now*2+1,c);
    se[now]=(se[now*2]+se[now*2+1])%99877;
}
int query(int l,int r,int a,int b,int now){
    if(lazy[now]){
        se[now]+=lazy[now]*(r-l+1);
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        lazy[now]=0;
    }
    if(r<a||l>b)return 0;
    if(l>=a && r<=b){
        return se[now];
    }
    int mid=(l+r)/2;
    return (query(l,mid,a,b,now*2)+query(mid+1,r,a,b,now*2+1))%99877;
}
int main()
{
    int n,com,q,i,a,b,c,idx,idx2;
    scanf("%d %d %d",&n,&com,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&st[i]);
    }
    while(com--){
        scanf("%d %d %d",&a,&b,&c);
        idx=upper_bound(st+1,st+1+n,a)-st;
        idx2=upper_bound(st+1,st+1+n,b)-st;
        update(1,n,idx-1,idx2-1,1,c);
    }
    while(q--){
        scanf("%d %d",&a,&b);
        idx=upper_bound(st+1,st+1+n,a)-st;
        idx2=upper_bound(st+1,st+1+n,b)-st;
        printf("%d\n",query(1,n,idx-1,idx2-1,1));
    }
    return 0;
}
/*
8 3 2
1 2 3 6 11 20 25 30
3 11 1
6 20 2
1 6 1
11 20
1 30

5 2 1
1 2 3 4 5
1 3 1
3 5 1
2 4
*/
