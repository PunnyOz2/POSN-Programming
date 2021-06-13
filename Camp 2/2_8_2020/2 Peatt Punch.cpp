#include <bits/stdc++.h>
using namespace std;
long long i,j,n,m,Q,h,power,Max;
stack<pair<long long,long long>> q;
long long a[100100];
int main(){
    scanf("%lld %lld",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%lld",&h);
        while(!q.empty() && h<q.top().first)q.pop();
        if(q.empty())power = 0;
        else power=max(q.top().second , h-q.top().first);
        a[i]=power;
        q.push({h,power});
    }
    sort(a+1,a+n+1);
    while(Q--){
        scanf("%lld",&h);
        printf("%lld\n",n-(upper_bound(a+1,a+n+1,h)-a-1));
    }
}
