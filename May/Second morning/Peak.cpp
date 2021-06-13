/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[5000003];
vector<int> g;
int ans[5000003];
int main()
{
    int n,i,k;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int cou=0;
    for(i=1;i<=n;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            g.push_back(a[i]);
        }
    }
    int old=-1;
    sort(g.begin(),g.end());
    for(i=0;i<g.size();i++){
        if(g[i]==old)continue;
        ans[cou++]=g[i];
        old=g[i];
    }
    if(cou==0){printf("-1");return 0;}
    if(cou<k){
        for(i=0;i<cou;i++)printf("%d\n",ans[i]);
    }
    else{
        for(i=cou-1;i>=cou-k;i--)printf("%d\n",ans[i]);
    }
    return 0;
}
/*
10 2
40 10 90 5 45 50 65 90 35 45

10 3
45 20 20 5 45 50 65 90 35 45

7
3
4
6
6
6
8
9
9

*/
