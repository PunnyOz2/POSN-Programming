/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int type,w,v,d,x;
    bool operator< (const A&o) const{
        if(w!=o.w) return w>o.w;
    }
};
priority_queue< A > h1;
priority_queue< A > h2;
int main()
{
    int n,m;
    scanf("%d %d"&n,&m);
    for(i=0;i<n+m;i++){

    }

    return 0;
}
