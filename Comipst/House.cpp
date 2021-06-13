/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int se,le,re,sum;
};
A seg[800010];
void update(int l,int r,int a,int val,int now){
    if(a<l||a>r)return;
    if(l==r){
        seg[now].se=val;
        seg[now].le=val;
        seg[now].re=val;
        seg[now].sum=val;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,a,val,now*2);
    update(mid+1,r,a,val,now*2+1);
    seg[now].sum=seg[now*2].sum+seg[now*2+1].sum;
    seg[now].re=max(seg[now*2+1].re,seg[now*2].re+seg[now*2+1].sum);
    seg[now].le=max(seg[now*2].le,seg[now*2+1].le+seg[now*2].sum);
    seg[now].se=max(seg[now*2].se,max(seg[now*2+1].se,seg[now*2].re+seg[now*2+1].le));
}
A query(int l,int r,int a,int b,int now){
    if(b<l||a>r)return {0,0,0,0};
    if(a<=l&&r<=b)return seg[now];
    int mid=(l+r)/2;
    A ll,rr,ans;
    ll=query(l,mid,a,b,now*2),rr=query(mid+1,r,a,b,now*2+1);
    ans.sum=ll.sum+rr.sum;
    ans.re=max(rr.re,ll.re+rr.sum);
    ans.le=max(ll.le,rr.le+ll.sum);
    ans.se=max(ll.se,max(rr.se,ll.re+rr.le));
    return ans;
}
int main()
{
    int n,m,i,x,y;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        update(0,n-1,i,x,1);
    }
    printf("%d\n",query(0,n-1,0,n-1,1));
    while(m--){
        scanf("%d %d",&x,&y);
        update(0,n-1,x,y,1);
        printf("%d\n",query(0,n-1,0,n-1,1));
    }
    return 0;
}
