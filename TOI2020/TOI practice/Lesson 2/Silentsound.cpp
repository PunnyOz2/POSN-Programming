#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,val;
};
deque<A>maxq,minq;
int main(){
    int n,m,c,i,temp,ch=1,num;
    scanf("%d %d %d",&n,&m,&c);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        while(!maxq.empty() && maxq.back().val<=num)maxq.pop_back();
        while(!minq.empty() && minq.back().val>=num)minq.pop_back();
        while(!maxq.empty() && maxq.front().idx<=i-m)maxq.pop_front();
        while(!minq.empty() && minq.front().idx<=i-m)minq.pop_front();
        maxq.push_back({i,num});
        minq.push_back({i,num});
        temp=maxq.front().val-minq.front().val;
        if(i-m>=0 && temp<=c){
            printf("%d\n",i-m+1);
            ch=0;
        }
    }
    if(ch)printf("NONE\n");
    return 0;
}
/*
7 2 0
0 1 1 2 3 2 2
*/
