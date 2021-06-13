/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int tree[760000],ans;
string a;
int main()
{
    int n,m,c,d;
    scanf("%d %d",&n,&m);
    while(m--){
        cin>>a;
        if(a=="Bury"){
            scanf("%d %d",&c,&d);
            while(d<=n)
                tree[d]+=c,d+=(d&-d);
        }
        else if(a=="Find"){
            scanf("%d %d",&c,&d);
            for(ans=0;d>0;d-=(d&-d))
                ans+=tree[d];
            for(c--;c>0;c-=(c&-c))
                ans-=tree[c];
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
10 5
Bury 5 5
Bury 10 7
Find 3 7
Bury 20 8
Find 6 10
*/
