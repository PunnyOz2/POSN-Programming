/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[23];
int cnt[23];
deque<pair<int,int>> q;
int main()
{
    int n,k,i,len;
    long long ans=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf(" %s",a);
        len=strlen(a);
        while(!q.empty() && i-k>q.front().first){
            cnt[q.front().second]--;
            q.pop_front();
        }
        ans+=cnt[len];
        q.push_back({i,len});
        cnt[len]++;
    }
    printf("%lld\n",ans);
    return 0;
}
