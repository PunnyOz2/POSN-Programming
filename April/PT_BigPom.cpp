/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100];
long long n,w,c,s;
long long play(long long l,long long r){
    if(l==r){
        long long cou=0;
        cou=upper_bound(a,a+w,r)-lower_bound(a,a+w,l);
        if(cou==0)return c;
        return cou*s;
    }
    long long mid=(l+r)/2;
    long long cou=0,i;
    cou=upper_bound(a,a+w,r)-lower_bound(a,a+w,l);
    if(cou==0)return c;
    else{
        return min(s*(r-l+1)*cou,play(l,mid)+play(mid+1,r));
    }
}
int main()
{
	long long q,i,idx;
	scanf("%d",&q);
	while(q--){
        scanf("%lld %lld %lld %lld",&n,&w,&c,&s);
        for(i=0;i<w;i++){
            scanf("%lld",&idx);
            a[i]=idx;
        }
        sort(a,a+w);
        printf("%lld\n",play(1,pow(2,n)));
        memset(a,0,sizeof a);
	}
    return 0;
}
/*
6
2 2 1 2
1 3
3 2 1 2
1 7
2 1 10 1
1
2 2 1 2
1 3
3 2 1 2
1 7
2 1 10 1
1
*/
