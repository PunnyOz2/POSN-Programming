/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
vector<int> g[100010],ans;
int main()
{
    int idx=0,n,cou=0,i,num,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        idx=lower_bound(a,a+cou,num)-a;
        if(idx==cou){
            cou++;
        }
        a[idx]=num;
        g[idx].push_back(num);
    }
    printf("%d\n",cou);
    num=g[cou-1][0],ans.push_back(num);
    for(i=cou-2;i>=0;i--){
        for(auto x:g[i]){
            if(x<num){num=x,ans.push_back(num);break;}
        }
    }
    for(i=cou-1;i>=0;i--){
        printf("%d ",ans[i]);
    }
    return 0;
}
/*
8
-7 10 9 2 3 8 8 1
10
6 3 4 8 10 5 7 1 9 2
*/
