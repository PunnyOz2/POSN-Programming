/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long num,cou,ans,i;
stack<pair<long long,long long>> q;
int main()
{
    long long n;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&num);

        while(!q.empty() && q.top().first<num){
            ans+=q.top().second;
            q.pop();
        }
        cou=0;
        if(!q.empty() && q.top().first==num){
            ans+=q.top().second;
            cou+=q.top().second;
            cou++;
            q.pop();
        }
        else cou=1;
        if(!q.empty())ans++;
        q.push({num,cou});
        //printf("%d %d\n",num,cou);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
7 2 4 1 2 2 5 1
*/
