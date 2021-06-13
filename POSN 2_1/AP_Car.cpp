/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long st,en;
    bool operator<(const A&o)const{
        if(st!=o.st) return st<o.st;
        return en>o.en;
    }
};
A a[100100];
int main()
{
    long long q,n,t,i,v,ans,st,last;
	scanf("%lld",&q);
	while(q--){
        scanf("%lld %lld",&n,&t);
        for(i=0;i<n;i++){
            scanf("%lld %lld",&a[i].st,&a[i].en);
            a[i].en*=t;
            a[i].en+=a[i].st;
        }
        sort(a,a+n);
        ans=1,st=a[0].st,last=a[0].en;
        for(i=1;i<n;i++){
            if(a[i].en<last || a[i].en==last&&a[i].st>st) continue;
            ans++;
            st=a[i].st,last=a[i].en;
        }
        printf("%d\n",ans);
	}
    return 0;
}
/*
1
5 2
0 10
0 5
10 5
8 8
9 7
*/
