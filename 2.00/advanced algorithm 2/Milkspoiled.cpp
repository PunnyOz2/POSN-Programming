/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII> v;
int main()
{
	int q,n,x,y,z,i,st,en,Max=-10000000,old,cold,mid,hot,anscou2;
	scanf("%d",&q);
	while(q--){
        Max=-1000000000;
        scanf("%d %d %d %d",&n,&x,&y,&z);
        for(i=0;i<n;i++){
            scanf("%d %d",&st,&en);
            v.push_back({st,1});
            v.push_back({en+1,-1});
        }
        old=0;
        v.push_back({100000005,0});
        cold=n,mid=0,hot=0;
        sort(v.begin(),v.end());
        for(i=0;i<v.size();i++){
            if(v[i].second>0) cold--,mid++;
            if(v[i].second<0) mid--,hot++;
            while(v[i].first==v[i+1].first){
                i++;
                if(v[i].second>0) cold--,mid++;
                if(v[i].second<0) mid--,hot++;
            }
            Max=max(cold*x+mid*y+hot*z,Max);
        }
        printf("%d",Max);
        v.clear();
	}
    return 0;
}
/*
4
4
3 5 4
4 8
2 4
3 5
5 8

4 7 9 6
5 8
3 4
13 20
7 10
*/
