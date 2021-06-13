/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define N 200100
int MA[4*N],MI[4*N],h[N],pos[N];
void create(int l,int r,int now){
    if(l==r){ MA[now]=MI[now]=h[l];return;}
    int mid=(l+r)/2;
    create(l,mid,now*2),create(mid+1,r,now*2+1);
    MA[now]=max(MA[now*2],MA[now*2+1]);
    MI[now]=min(MI[now*2],MI[now*2+1]);
}
void update(int l,int r,int now,int idx,int w){
    if(l>idx||r<idx)return;
    if(l==r ){
        MA[now]=MI[now]=w;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,now*2,idx,w),update(mid+1,r,now*2+1,idx,w);
    MA[now]=max(MA[now*2],MA[now*2+1]);
    MI[now]=min(MI[now*2],MI[now*2+1]);
}
int queryMA(int l,int r,int a,int b,int now){
    if(l>b||r<a)return -1<<30;
    if(l>=a&&r<=b)return MA[now];
    int mid=(l+r)/2;
    return max(queryMA(l,mid,a,b,now*2),queryMA(mid+1,r,a,b,now*2+1));
}
int queryMI(int l,int r,int a,int b,int now){
    if(l>b||r<a)return 1<<30;
    if(l>=a&&r<=b)return MI[now];
    int mid=(l+r)/2;
    return max(queryMI(l,mid,a,b,now*2),queryMI(mid+1,r,a,b,now*2+1));
}
int main()
{
	int n,m,i,opr,a,b;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&h[i]),update(1,n,1,h[i],i),pos[h[i]]=i;
	//create(1,n,1);
	while(m--){
        scanf("%d %d %d",&opr,&a,&b);
        if(opr==1){
            update(1,n,1,h[a],b),update(1,n,1,h[b],a);
            swap(h[a],h[b]);
        }
        else{
            if(a>b)swap(a,b);
            if(pos[queryMA(1,n,a,b,1)]-pos[queryMI(1,n,a,b,1)]==b-a)printf("YES\n");
            else printf("NO\n");
        }
	}
    return 0;
}
/*
7 7
4 7 3 5 1 2 6
2 1 7
1 3 7
2 4 6
2 4 7
2 1 4
1 1 4
2 1 4
*/
