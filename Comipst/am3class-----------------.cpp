/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int r,g,b;
    bool operator<(const A&o)const{
        return r<o.r;
    }
};
map<A,int>mp;
int main()
{
    int n,m,i,j,a,b,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=100;i++){
        for(j=1;j<=100;j++){
            scanf("%d %d %d",&a,&b,&c);
            mp[{a,b,c}]++;
        }
    }
    printf("%d\n",mp.size());
//    for(auto x:mp)printf("%d")
    return 0;
}
