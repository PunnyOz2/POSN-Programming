/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> h;
unordered_map<long long,long long> mp;
int main()
{
	long long q,n,k,i,num,j;
	scanf("%lld",&q);
	for(j=1;j<=q;j++){
        scanf("%lld %lld",&n,&k);
        h.push(n);
        mp[n]++;
        i=0;
        while(!h.empty()){
            num=h.top();
            i+=mp[num];
            h.pop();
            if(i>=k){
                printf("Case #%lld: %lld %lld\n",j,max(num/2,(num-1)/2),min(num/2,(num-1)/2));
                break;
            }
            if(num%2==0){
                if(mp[num/2]==0)h.push(num/2);
                if(mp[(num-1)/2]==0)h.push((num-1)/2);
            }
            else
                if(mp[num/2]==0)h.push(num/2);
            mp[num/2]+=mp[num],mp[(num-1)/2]+=mp[num];
        }
        while(!h.empty())h.pop();
        mp.clear();
	}
    return 0;
}
