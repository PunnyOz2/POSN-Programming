/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,w;
    bool operator<(const A&o)const{
        return idx<o.idx;
    }
};
vector<A> g;
int main()
{
    int n,i,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        g.push_back({a,1});
        g.push_back({b+1,-1});
    }
    g.push_back({2000000002,0});
    sort(g.begin(),g.end());
    int sum=0;
    int Max=-1;
    for(i=0;i<g.size();i++){
        sum+=g[i].w;
        while(g[i].idx==g[i+1].idx){
            i++;
            sum+=g[i].w;
        }
        //printf("%d ",sum);
        Max=max(Max,sum);
    }
    printf("%d\n",Max);
    return 0;
}
/*
7
0 2
3 6
7 10
0 4
5 7
8 10
6 8
*/
