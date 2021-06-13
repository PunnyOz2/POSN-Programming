#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
deque<long long> Mi,Ma;
int main(){
    long long n,l,r,i,temp,pos,sum=0;
    scanf("%lld %lld %lld",&n,&l,&r);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    pos=1;
    for(i=1;i<=n;i++){
        temp=a[i];
        while(!Ma.empty() && Ma.front()<pos)Ma.pop_front();
        while(!Mi.empty() && Mi.front()<pos)Mi.pop_front();
        while(!Ma.empty() && a[Ma.back()]<temp)Ma.pop_back();
        while(!Mi.empty() && a[Mi.back()]>temp)Mi.pop_back();
        Ma.push_back(i);
        Mi.push_back(i);
        while(a[Ma.front()]-a[Mi.front()]>r){
            pos=min(Ma.front(),Mi.front())+1;
            while(!Ma.empty() && Ma.front()<pos)Ma.pop_front();
            while(!Mi.empty() && Mi.front()<pos)Mi.pop_front();
        }
        sum+=i-pos+1;
    }
    while(!Ma.empty())Ma.pop_back();
    while(!Mi.empty())Mi.pop_back();
    pos=1;
    if(l>=1){
    for(i=1;i<=n;i++){
        temp=a[i];
        while(!Ma.empty() && Ma.front()<pos)Ma.pop_front();
        while(!Mi.empty() && Mi.front()<pos)Mi.pop_front();
        while(!Ma.empty() && a[Ma.back()]<temp)Ma.pop_back();
        while(!Mi.empty() && a[Mi.back()]>temp)Mi.pop_back();
        Ma.push_back(i);
        Mi.push_back(i);
        while(a[Ma.front()]-a[Mi.front()]>l-1){
            pos=min(Ma.front(),Mi.front())+1;
            while(!Ma.empty() && Ma.front()<pos)Ma.pop_front();
            while(!Mi.empty() && Mi.front()<pos)Mi.pop_front();
        }
        sum-=i-pos+1;
    }
    }
    printf("%lld\n",sum);
    return 0;
}
/*
7 1 2
1 7 4 3 9 6 8

4 0 10
1 2 3 4
*/
