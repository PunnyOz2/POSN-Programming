#include<bits/stdc++.h>
using namespace std;
struct A{
    long long num;
    bool operator<(const A&o)const{
        return num<o.num;
    }
};
priority_queue<A> q;
long long mark[100100];
vector<long long> a[100100];
vector<long long> g;
int main(){
    long long n,i,id,num,sum=0,cou=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&id,&num);
        a[id].push_back(num);
    }
    for(i=100000;i>=1;i--){
        for(auto x:a[i]){
            q.push({x});
        }
        if(!q.empty()){
            sum+=q.top().num;
            cou++;
            q.pop();
        }
    }
    printf("%lld\n%lld",sum,cou);
    return 0;
}
/*
4
1 17
5 15
2 10
2 11
*/
