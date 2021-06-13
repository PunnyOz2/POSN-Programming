/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int tree[5000010];
int countt;
void update(int l,int r,int a,int b,int now){
    if(r<a || l>b)return;
    if(l==r)return;
    if(l==a && r==b){
        if(tree[now]==0)tree[now]=1;
        if(tree[now*2]==1 && tree[now*2+1]==1 && now!=1)tree[now]=1,update(l,r*2-l,a,b,now/2);
        int ch=0;

    }


    int mid=(l+r)/2;

    if(tree[now*2]==1)update(mid+1,r,a,b,now*2+1);
    else if(tree[now*2+1]==1)update(l,mid,a,b,now*2);
}
int main()
{
    int n,k,ans=-1,i,a,b,space;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++){
        scanf("%d %d",&a,&b);
        space=1<<a;
        update(0,n-1,b,b+space-1,1);
        if(countt==1<<n){
            ans=i;
            countt++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
1 3
0 0
1 0
0 1
*/
