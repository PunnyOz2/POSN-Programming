/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int seg[400100];
void update(int l,int r,int a,int c,int now){
    if(r<a || l>a)return;
    if(l==r){
        seg[now]=c;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,a,c,now*2);
    update(mid+1,r,a,c,now*2+1);
    seg[now]=max(seg[now*2],seg[now*2+1]);
}
int query(int l,int r,int a,int b,int now){
    if(r<a||l>b)return -1e9;
    if(l>=a && r<=b)return seg[now];
    int mid=(l+r)/2;
    return max(query(l,mid,a,b,now*2),query(mid+1,r,a,b,now*2+1));
}
int main()
{
    int n,q,a,b;
    char com;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf(" %c %d %d",&com,&a,&b);
        if(com=='U'){
            update(1,n,a,b,1);
        }
        if(com=='P'){
            printf("%d\n",query(1,n,a,b,1));
        }
    }
    return 0;
}
