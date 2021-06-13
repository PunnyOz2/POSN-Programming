/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,num;
};
stack<A> q;
long long n,a[100100],ans[100100];
int main()
{
    long long Q,Max,i;
    scanf("%lld",&Q);
    while(Q--){
        Max=0;
        scanf("%lld ",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            ans[i]=a[i];
        }
        q.push({0,-1});
        for(i=1;i<=n;i++){
            while(!q.empty() && q.top().num>=a[i])q.pop();
            ans[i]+=(i-q.top().i-1)*a[i];
            q.push({i,a[i]});
        }
        while(!q.empty())q.pop();
        q.push({n+1,-1});
        for(i=n;i>=1;i--){
            while(!q.empty() && q.top().num>=a[i])q.pop();
            ans[i]+=(q.top().i-i-1)*a[i];
            Max=max(Max,ans[i]);
            q.push({i,a[i]});
        }
        printf("%lld\n",Max);
    }
    return 0;
}
/*
2 6 2 1 5 6 2 3 3 100 100 100
*/
