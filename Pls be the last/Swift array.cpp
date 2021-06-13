/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int se[400100];
void update(int l,int r,int a,int b,int now){
    if(l>a || a>r)return;
    if(l==r){
        se[now]=b;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,a,b,2*now);
    update(mid+1,r,a,b,2*now+1);
    se[now]=max(se[now*2],se[now*2+1]);
}
int query(int l,int r,int a,int b,int now){
    if(r<a||b<l)return 0;
    if(l>=a&&r<=b){
        return se[now];
    }
    int mid=(l+r)/2;
    return max(query(l,mid,a,b,2*now),query(mid+1,r,a,b,2*now+1));
}
int main()
{
    int n,q,a,b;
    char opr;
    scanf("%d %d",&n,&q);
    while(q--){
        scanf(" %c %d %d",&opr,&a,&b);
        if(opr=='U'){
            update(1,n,a,b,1);
        }
        else{
            printf("%d\n",query(1,n,a,b,1));
        }
    }
    return 0;
}
/*
10 6
U 2 3
Q 4 6
U 7 5
Q 2 6
U 5 10
Q 1 10
*/
