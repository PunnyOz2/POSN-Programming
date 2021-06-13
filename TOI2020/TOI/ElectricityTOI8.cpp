#include <bits/stdc++.h>
using namespace std;
int num[500100];
int qs[500100];
struct A{
    int num,id;
    bool operator<(const A&o)const{
        return num>o.num;
    }
};
priority_queue<A> q;
int main(){
    int n,k,i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    q.push({num[1],1});
    qs[1]=num[1];
    for(i=2;i<=n;i++){
        while(!q.empty() && i-q.top().id>k){
            q.pop();
        }
        qs[i]=qs[q.top().id]+num[i];
        q.push({qs[i],i});
        //printf("%d %d %d %d\n",i,qs[i],q.top().num,qs[q.top().id]);
    }
    printf("%d\n",qs[n]);
}
/*
7
3
1 4 2 6 2 4 2
*/
