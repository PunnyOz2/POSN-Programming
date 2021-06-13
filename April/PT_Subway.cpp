/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int>> q;
int mic[12000];
int main()
{
	int Q;
	int n,k,Min,i,num;
	scanf("%d",&Q);
	while(Q--){
        scanf("%d %d",&n,&k);
        q.push_back({0,0});
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            while(!q.empty() && q.front().first ==0 && i-k>1)q.pop_front();
            while(!q.empty() && i-q.front().second-2*k>1)q.pop_front();
            while(!q.empty() && q.back().first>=q.front().first+num )q.pop_back();
            mic[i]=q.front().first+num;
            q.push_back({mic[i],i});
        }
        Min=1<<30;
        //for(i=1;i<=n;i++){printf("%d ",mic[i]);}
        for(i=n;i>=n-k && i>0;i--){
            Min=min(Min,mic[i]);
        }
        printf("%d\n",Min);
        while(!q.empty())q.pop_back();
	}
    return 0;
}
/*
3
5 1
1 99 2 99 1
5 1
99 3 99 2 99
7 3
1 2 3 4 3 2 1
*/
