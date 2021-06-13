/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mark;
int level(int u){
    return log2(u);
}
int main()
{
    int q,u,v,w,a,b,ans;
    char opr;
    scanf("%d",&q);
    while(q--){
        scanf(" %c",&opr);
        if(opr=='U'){
            scanf("%d %d %d",&a,&b,&w);
            while(level(a)>level(b))
                mark[a]+=w,a/=2;
            while(level(b)>level(a))
                mark[b]+=w,b/=2;
            while(a!=b)
                mark[a]+=w,mark[b]+=w,a/=2,b/=2;
        }
        else{
            scanf("%d %d",&a,&b);
            ans=0;
            while(level(a)>level(b))
                ans+=mark[a],a/=2;
            while(level(b)>level(a))
                ans+=mark[b],b/=2;
            while(a!=b)
                ans+=mark[a],ans+=mark[b],a/=2,b/=2;
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
7
U 3 4 30
U 4 1 2
U 3 6 8
Q 4 3
U 6 1 40
Q 3 7
Q 2 4
*/
