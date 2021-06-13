/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int Max,ans,l,r;
};
A se[800010];
int lazy[800010];
void update(int l,int r,int a,int b,int val,int now){
    if(lazy[now]){
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        se[now].l+=lazy[now];
        se[now].r+=lazy[now];
        se[now].Max+=lazy[now];
        lazy[now]=0;
    }
    if(r<a||l>b)return;
    if(a<=l&&r<=b){
        if(l!=r){
            lazy[now*2]+=val;
            lazy[now*2+1]+=val;
        }
        if(l==r)se[now].ans=1;
        se[now].l+=val;
        se[now].r+=val;
        se[now].Max+=val;
        //ans unchanged
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,a,b,val,now*2);
    update(mid+1,r,a,b,val,now*2+1);
    se[now].Max=max(se[now*2].Max,se[now*2+1].Max);
    se[now].ans=0;
    if(se[now*2].Max==se[now].Max)                                                  se[now].ans+=se[now*2].ans;
    if(se[now*2+1].Max==se[now].Max)                                                se[now].ans+=se[now*2+1].ans;
    if(se[now].ans>=2 && se[now*2].r==se[now].Max && se[now*2].r==se[now*2+1].l)    se[now].ans--;
    se[now].l=se[now*2].l;
    se[now].r=se[now*2+1].r;
}
int Max;
A query(int l,int r,int a,int b,int now){
    if(lazy[now]){
        if(l!=r){
            lazy[now*2]+=lazy[now];
            lazy[now*2+1]+=lazy[now];
        }
        se[now].l+=lazy[now];
        se[now].r+=lazy[now];
        se[now].Max+=lazy[now];
        lazy[now]=0;
    }
    if(r<a||l>b)return {0,0,-1,-1};
    A ll,rr;
    if(a<=l&&r<=b){
        return se[now];
    }
    int mid=(l+r)/2,left,right;
    ll=query(l,mid,a,b,now*2);
    rr=query(mid+1,r,a,b,now*2+1);
    //Find left
    if(ll.l==-1){
        left=rr.l;
        right=rr.r;
    }
    else if(rr.l==-1){
        left=ll.l;
        right=ll.r;
    }
    else{
        left=ll.l;
        right=rr.r;
    }
    int ans=0;
    if(ll.Max==Max)                         ans+=ll.ans;
    if(rr.Max==Max)                         ans+=rr.ans;
    if(ans>=2 && ll.r==Max && ll.r==rr.l)   ans--;
    return {Max,ans,left,right};
}
int main()
{
    A ans;
    int n,q,a,b,c;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n*4+5;i++)se[i].ans=1;
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        update(1,n,a,b,c,1);
        Max=se[1].Max;
        ans=query(1,n,1,n,1);
        printf("%d %d\n",ans.Max,ans.ans);
//        printf("%d %d\n",se[1].l,se[1].r);
//        printf("%d\n",se[1].Max);
    }
    return 0;
}
/*
6 5 2 3 4 4 6 1 5 5 3 1 4 1 2 3 -1

6 5
2 3 4
4 6 1
5 5 3
1 4 1
2 3 -1
*/
