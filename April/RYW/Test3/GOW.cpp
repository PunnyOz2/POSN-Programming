/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int a[100010],b[100010];
int fw[100100];
void update(int idx,int v){
    while(idx<=100003){
        fw[idx]+=v;
        idx+=idx&-idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=fw[idx];
        idx-=idx&-idx;
    }
    return sum;
}
int main()
{
    int n,m,idx = 1,i,ansreal=1<<30,ans;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),b[i] = a[i];
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++){
        if(b[i] == b[i+1])  continue;
        mp[b[i]] = idx++;
	}
	idx--;
//	for(i=1;i<=n;i++){
//        printf("%d ",mp[a[i]]);
//	}
    int l=0,r=1e9,mid,countt;
    while(l<r){
        mid = (l+r)/2,countt = 0;
        for(int i=1;i<=n;i++){
            if(a[i]<=mid){
                countt+=query(idx)-query(mp[a[i]]-1);
                update(mp[a[i]],1);
            }
        }
        if(countt>=m)   r = mid;
        else            l = mid+1;
        memset(fw,0,sizeof fw);
    }
    printf("%d\n",l);
    return 0;
}
