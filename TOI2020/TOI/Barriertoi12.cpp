#include <bits/stdc++.h>
using namespace std;
struct A{
    int val,pos;
    bool operator<(const A&o)const{
        if(val!=o.val) return val>o.val;
        return pos<o.pos;
    }
};
int a[6000100];
priority_queue<A> q;
int main(){
    int n,w,Max=0,ans=0,i,now,siz;
    scanf("%d %d",&n,&w);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    q.push({0,0});
    for(i=1;i<=n;i++){
        while(!q.empty() && q.top().pos<i-w)q.pop();
        now=a[i]-q.top().val;
        siz=i-q.top().pos;
        if(now>Max){
            Max=now;
            ans=siz;
        }
        else if(now==Max && siz<ans){
            ans=siz;
        }
        q.push({a[i],i});
    }
    printf("%d\n%d\n",Max,ans);
}
/*
7 4
3 2 5 1 4 -7 10
*/
