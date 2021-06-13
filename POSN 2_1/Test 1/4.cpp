/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int node[100100];
map<int,int> mp;
int main()
{
	int n,q,cou,l,r,i,a;
	scanf("%d %d",&n,&q);
	int last=0;
	for(i=1;i<=n;i++){
        scanf("%d",&node[i]);
	}
	while(q--){
        cou=0;
        scanf("%d %d",&l,&r);
        for(i=l;i<=r;i++)
            mp[node[i]]++;
        for(auto x:mp){
            if(x.second>=x.first)cou++;
        }
        printf("%d\n",cou);
        mp.clear();
	}
    return 0;
}
