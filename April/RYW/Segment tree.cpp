/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100100
int Seg[4*N];
void update(int l,int r,int a,int b,int now){
    if(l>a || r<a)return;
    if(l==r){
        Seg[now]=b;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,a,b,now*2),update(mid+1,r,a,b,now*2+1);
    Seg[now]=max(Seg[now*2],Seg[now*2+1]);
}
int query(int l,int r,int a,int b,int now){
    if(r<a||l>b)return -1e9 ;
    if(l>=a&&r<=b) return Seg[now];
    int mid=(l+r)/2;
    return max(query(l,mid,a,b,now*2),query(mid+1,r,a,b,now*2+1));
}
int main()
{
	int n,q,a,b;
	char opr;
	scanf("%d %d",&n,&q);
	while(q--){
        scanf(" %c %d %d",&opr,&a,&b);
        if(opr=='U')
            update(1,n,a,b,1);
        else{
            printf("%d\n",query(1,n,a,b,1));
        }
	}
    return 0;
}
/*
6 7
U 5 280
U 1 7
P 1 2
P 3 5
U 4 -873760809
U 2 -392
P 1 1
*/
