/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1200];
struct A{
    long long val,tim;
    bool operator<(const A&o)const{
        return tim<o.tim;
    }
};
vector<A> g;
int main()
{
    long long n,m,i,j,prodnow,tim,all,check,ans,l,r,mid;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    l=1;
    r=1000000000;
    for(i=2;i<=n;i++){
        g.push_back({((a[i]-a[i-1])%2==1)? 1:0 ,((a[i]-a[i-1])%2==1)? ((a[i]-a[i-1]+1)/2+1):((a[i]-a[i-1])/2+1)});
    }
    sort(g.begin(),g.end());
    while(l<r){
        mid=(l+r)/2;
        all=(mid*mid)*n;
        for(auto x:g){
            if(x.tim>mid)break;
            if(x.val==0){
                all-=(mid-x.tim+1)*(mid-x.tim+1);
            }
            else{
                all-=(mid-x.tim+1)*(mid-x.tim+1)+mid-x.tim+1;
            }
        }
        if(all>=m){
            r=mid;
        }
        else
            l=mid+1;
    }
    printf("%lld\n",l-1);
    return 0;
}
/*
2 15
5 3
*/
