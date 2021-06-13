/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int ans[5000];
map<int,int>mp;
map<int,int> ::const_iterator it;
int main()
{
    int n,k,i,now=0;
    scanf("%d %d",&n,&k);
    memset(ans,-1,sizeof ans);
    for(i=1;i<=n;i++)mp[i]++;
    for(i=n;i>0;i--){
        now+=k;
        now%=i;
        it=now;
        printf("%d\n",mp[it]);
        mp.erase(it);
        now++;
        now%=i;
    }
    return 0;
}
