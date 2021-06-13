/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[101000],temp[101000],ans[100100];
stack<pair<int,int>> q;
int main()
{
    int n,k,i,cou;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        cou=0;
        scanf("%d",&a[i]);
        while(!q.empty()&&q.top().first>=a[i]){
            cou+=q.top().second+1;
            q.pop();
        }
        temp[i]=cou;
        q.push({a[i],cou});
    }
    while(!q.empty())q.pop();
    for(i=n;i>=1;i--){
        cou=0;
        while(!q.empty()&&q.top().first>=a[i]){
            cou+=q.top().second+1;
            q.pop();
        }
        temp[i]+=cou;
        q.push({a[i],cou});
    }
//    for(i=1;i<=n;i++)printf("%d ",temp[i]);
    for(i=1;i<=n;i++){
        //if(a[i-1]==a[i])dp[i]=dp[i-1];
        if(ans[temp[i]]<a[i])ans[temp[i]]=a[i];
    }
    if(k>0){
        if(ans[k]!=0)printf("%d ",ans[k]);
        else printf("-1 ");
    }
    else{
        for(i=1;i<=n;i++){
            if(ans[i]!=0)printf("%d ",ans[i]);
            else printf("-1 ");
        }
    }
    return 0;
}
/*
7 -10
4 5 7 5 2 4 5
*/
