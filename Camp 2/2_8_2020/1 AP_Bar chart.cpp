#include <bits/stdc++.h>
using namespace std;
struct A{
    long long val,pos;
};
stack<A> q;
long long pos[100100],pos2[100100],a[100100];
int main(){
    long long Q,i,ans,n;
    scanf("%lld",&Q);
    while(Q--){
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            pos[i]=1;
            pos2[i]=n;
        }
        for(i=1;i<=n;i++){
            while(!q.empty() && q.top().val>=a[i]){
                q.pop();
            }
            if(!q.empty())pos[i]=q.top().pos+1;
            q.push({a[i],i});
        }
        while(!q.empty())q.pop();
        for(i=n;i>=1;i--){
            while(!q.empty() && q.top().val>=a[i]){
                q.pop();
            }
            if(!q.empty())pos2[i]=q.top().pos-1;
            q.push({a[i],i});
        }
        while(!q.empty())q.pop();
        ans=0;
        for(i=1;i<=n;i++){
            //printf("%lld %lld %lld\n",pos[i],pos2[i],a[i]);
            ans=max(ans,(pos2[i]-pos[i]+1)*a[i]);
        }
        printf("%lld\n",ans);
    }
}
