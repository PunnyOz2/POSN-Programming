/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int se[310][20100],lazy[310][20100];
void update(int row,int l,int r,int a,int b,int val,int now){
    if(lazy[row][now]){
        if(l!=r)lazy[row][now*2]=lazy[row][now*2+1]=lazy[row][now];
        se[row][now]=lazy[row][now];
        lazy[row][now]=0;
    }
    if(r<a||b<l)return;
    if(a<=l&& b>=r){
        if(l!=r)lazy[row][now*2]=lazy[row][now*2+1]=val;
        se[row][now]=val;
        return;
    }
    int mid=(l+r)/2;
    update(row,l,mid,a,b,val,now*2);
    update(row,mid+1,r,a,b,val,now*2+1);
    se[row][now]=min(se[row][now*2],se[row][now*2+1]);
}
int query(int row,int l,int r,int a,int b,int now){
    if(lazy[row][now]){
        if(l!=r)lazy[row][now*2]=lazy[row][now*2+1]=lazy[row][now];
        se[row][now]=lazy[row][now];
        lazy[row][now]=0;
    }
    if(r<a||b<l)return 1e9;
    if(a<=l&& b>=r){
        return se[row][now];
    }
    int mid=(l+r)/2;
    return min(query(row,l,mid,a,b,now*2),query(row,mid+1,r,a,b,now*2+1));
}
int main()
{
    int n,m,q,opr,a,b,Min,c,i;
    scanf("%d %d %d",&n,&m,&q);
    while(q--){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d %d %d",&a,&b,&c);
            update(a,1,m,b,b,c,1);
        }
        if(opr==2){
            scanf("%d %d",&a,&b);
            update(a,1,m,1,m,b,1);
        }
        if(opr==3){
            scanf("%d %d",&a,&b);
            printf("%d\n",query(a,1,m,b,b,1));
        }
        if(opr==4){
            Min=1e9;
            for(i=1;i<=n;i++){
                Min=min(Min,query(i,1,m,1,m,1));
            }
            printf("%d\n",Min);
        }
    }
    return 0;
}
/*
3 3 14
3 1 2 4
2 1 100
2 2 10
2 3 40 4
1 2 1 50
1 2 3 200 4
1 3 3 25
3 3 2 4
1 2 2 60 4
*/
