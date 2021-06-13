/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,y1,y2,val;
    bool operator<(const A&o)const{
        if(idx!=o.idx)return idx<o.idx;
        return val<o.val;
    }
};
struct B{
    int x,y,id;
    bool operator<(const B&o)const{
        if(x!=o.x)return x<o.x;
        return y<o.y;
    }
};
vector<A> g;
B q[10010];
int fw[100100];
void update(int a,int b){
    while(a<=100005){
        fw[a]+=b;
        a+=(a&-a);
    }
}
int query(int a){
    int sum=0;
    while(a>0){
        sum+=fw[a];
        a-=(a&-a);
    }
    return sum;
}
int ans[10010];
int main()
{
    int n,m,k,Max=-1,i,a,c,b,d,idx,val,y;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%d %d %d %d",&a,&c,&b,&d);
        g.push_back({a,c+1,d+1,1});
        g.push_back({b+1,c+1,d+1,-1});
        Max=max(Max,b+1);
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        g.push_back({a,b+1,i,4});
    }
    sort(g.begin(),g.end());
    for(i=0;i!=g.size();i++){
        if(g[i].val==4){
            ans[g[i].y2]=query(g[i].y1);
            continue;
        }
        update(g[i].y1,g[i].val);
        update(g[i].y2+1,-g[i].val);
    }
    for(i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
/*
10 5 3
3 0 8 2
1 7 8 9
1 0 8 2
5 2 6 4
5 1 5 4
7 3 7 9
0 0 0 3
6 2 6 4
8 3 9 8
4 4 8 6
7 9
8 5
3 0
6 4
3 4
*/
