/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long w,v;
    bool operator<(const A&o)const{
        return v<o.v;
    }
};
A a[300100];
long long bag[300100];
vector<long long> g[300100];
priority_queue<long long> q;
int main()
{
    long long n,m,i,sum=0,idx;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&a[i].w,&a[i].v);
    }
    for(i=0;i<m;i++){
        scanf("%lld",&bag[i]);
    }
    sort(bag,bag+m);
    for(i=0;i<n;i++){
        idx=lower_bound(bag,bag+m,a[i].w)-bag;
        //printf("%lld %lld\n",a[i].w,idx);
        g[idx].push_back(a[i].v);
    }
    for(i=0;i<m;i++){
        for(auto x:g[i]){
            //printf("%lld %lld\n",i,x);
            q.push(x);
        }
        if(!q.empty()){
            sum+=q.top();
            q.pop();
        }
    }
    printf("%lld\n",sum);
    return 0;
}
/*
5 2
1 3
8 2
2 5
9 5
2 3
8
2

*/
