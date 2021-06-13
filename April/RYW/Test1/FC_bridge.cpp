/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100],ans;
void mergesort(int l,int r){
    if(l==r)return;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    int id=mid+1,cou=0,i,st=l;
    while(l<=mid && id<=r){
        if(a[l]>a[id]){b[cou]=a[id],ans+=mid-l+1,id++,cou++;}
        if(a[l]<=a[id])b[cou]=a[l],l++,cou++;
    }
    while(l<=mid){
        b[cou++]=a[l];
        l++;
    }
    while(id<=r){
        b[cou++]=a[id];
        id++;
    }
    for(i=st;i<=r;i++){
        a[i]=b[i-st];
    }
}
int main()
{
	int q,n,i,c;
	scanf("%d",&q);
	while(q--){
        scanf("%d",&n);
        ans=0;
        for(i=1;i<=n;i++)scanf("%d",&c),a[c]=i;
        //for(i=1;i<=n;i++)printf("%d ",a[i]);
        mergesort(1,n);
        //for(i=1;i<=n;i++)printf("%d ",a[i]);
        printf("%lld\n",ans);
	}
    return 0;
}
/*
2
8
4 8 1 2 3 5 7 6
*/
