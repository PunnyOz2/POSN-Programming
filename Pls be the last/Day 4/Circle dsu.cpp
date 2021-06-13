/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
    bool operator<(const A&o)const{
        if(x!=o.x)return x<o.x;
        return y>o.y;
    }
};
vector<A> g;
stack<A> st;
int main()
{
    int n,i,cou=0,Min=1<<30,Max=-1<<30,x,r,y;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        g.push_back({x-y,x+y});
    }
    cou++;
    sort(g.begin(),g.end());
    Max=-1<<30;
    for(i=0;i<n;i++){
        while(!st.empty() && g[i].x>st.top().y)st.pop(),Max=-1<<30;
        if(g[i].y==Max)cou++;
        Max=max(Max,g[i].y);
        st.push({g[i].x,g[i].y});
        cou++;
    }
    printf("%d\n",cou);
    return 0;
}
/*
4
-9 11
0 20
7 5
11 9

3
1 1
2 2
3 1
*/
