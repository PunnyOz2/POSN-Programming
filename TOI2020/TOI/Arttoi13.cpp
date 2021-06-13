#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,h,o;
    bool operator<(const A&o)const{
        return i<o.i;
    }
};
vector<A> g;
long long fw[1000100];
void update(long long i,long long val){
    while(i<=1000003){
        fw[i]+=val;
        i+=(i&-i);
    }
}
long long query(long long i){
    long long sum=0;
    while(i>0){
        sum+=fw[i];
        i-=(i&-i);
    }
    return sum;
}
int main(){
    long long n,t,i,s,h,w,o,j,l,r,mid,temp,ans=0;
    scanf("%lld %lld",&n,&t);
    for(i=1;i<=n;i++){
        scanf("%lld %lld %lld %lld",&s,&h,&w,&o);
        g.push_back({s,h,o});
        g.push_back({s+w,h,-o});
    }
    sort(g.begin(),g.end());
    g.push_back({4000001,0,0});
    for(j=0;j<g.size()-1;j++){
        i=g[j].i;
        h=g[j].h;
        o=g[j].o;
        update(1,o);
        update(h+1,-o);
        while(i==g[j+1].i){
            j++;
            i=g[j].i;
            h=g[j].h;
            o=g[j].o;
            update(1,o);
            update(h+1,-o);
        }
        l=1;
        r=1000002;
        while(l<r){
            mid=(l+r)/2;
            if(query(mid)>=t){
                l=mid+1;
            }
            else r=mid;
        }
        temp=l;
        l=1;
        r=1000002;
        while(l<r){
            mid=(l+r)/2;
            if(query(mid)>t){
                l=mid+1;
            }
            else r=mid;
        }
        ans+=(temp-l)*(g[j+1].i-g[j].i);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
3 3
1 1 4 1
2 2 2 2
3 3 1 3
*/
