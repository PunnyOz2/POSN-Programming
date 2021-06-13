#include<bits/stdc++.h>
using namespace std;
vector<int>pos[100100];
unordered_map<int,int>mp;
int main(){
    int n,q,i,l,r,num,ll,rr,cou=1;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        if(mp[num]==0)mp[num]=cou++;
        pos[mp[num]].push_back(i);
    }
    while(q--){
        scanf("%d %d %d",&l,&r,&num);
        ll=upper_bound(pos[mp[num]].begin(),pos[mp[num]].end(),l-1)-pos[mp[num]].begin();
        rr=upper_bound(pos[mp[num]].begin(),pos[mp[num]].end(),r)-pos[mp[num]].begin();
        printf("%d\n",rr-ll);
    }
    return 0;
}
/*
10 8
1 2 1 2 1 2 3 2 3 3
1 2 1
1 3 1
1 4 2
1 5 2
2 5 4
2 6 3
6 9 0
7 10 3
*/
