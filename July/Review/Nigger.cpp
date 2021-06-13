/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int seg[400100],lazy[400100];
void update(int l,int r,int a,int b,int now){
    if(lazy[now]){
        seg[now]=(r-l+1)-seg[now];
        lazy[now]=0;
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
    }
    if(r<a || l>b)return;
    if(l>=a && r<=b){
        seg[now]=(r-l+1)-seg[now];
        lazy[now*2]^=1;
        lazy[now*2+1]^=1;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,a,b,now*2);
    update(mid+1,r,a,b,now*2+1);
    seg[now]=seg[now*2]+seg[now*2+1];
}
int query(int l,int r,int a,int b,int now){
    if(lazy[now]){
        seg[now]=(r-l+1)-seg[now];
        lazy[now]=0;
        if(l!=r){
            lazy[now*2]^=1;
            lazy[now*2+1]^=1;
        }
    }
    if(r<a||l>b)return 0;
    if(l>=a && r<=b)return seg[now];
    int mid=(l+r)/2;
    return query(l,mid,a,b,now*2)+query(mid+1,r,a,b,now*2+1);
}
int main()
{
    int n,q,a,b;
    int com;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf("%d %d %d",&com,&a,&b);
        if(com==0){
            update(1,n,a,b,1);
        }
        if(com==1){
            printf("%d\n",query(1,n,a,b,1));
        }
    }
    return 0;
}
/*
4 5
0 1 2
0 2 4
1 2 3
0 2 4
1 1 3
*/
