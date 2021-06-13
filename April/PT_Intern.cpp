/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[50100];
deque<pair<int,int>> q;
unordered_map<int,int> mp;
int main()
{
	int Q,n,country,cou,ch,i,temp,temp2,Min;
	scanf("%d",&Q);
	while(Q--){
        cou=0;
        Min=1<<30;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&a[i].first,&a[i].second);
            mp[a[i].second]=1;
        }
        country=mp.size();
        mp.clear();
        sort(a,a+n);
        for(i=0;i<n;i++){
            if(q.size()==1 && q.front().second==a[i].second){q.pop_front(),q.push_back({a[i].first,a[i].second});continue;}
            else if(!q.empty() && q.back().second==a[i].second)continue;
            while(q.size()>1 && q.front().second==a[i].second){
                q.pop_front();
            }
            q.push_back({a[i].first,a[i].second});
            if(mp[a[i].second]==0)cou++,mp[a[i].second]=1;
            if(cou==country){
                Min=min(Min,q.back().first-q.front().first);
            }
        }
        printf("%d\n",Min+1);
        while(!q.empty())q.pop_back();
        mp.clear();
	}
    return 0;
}
