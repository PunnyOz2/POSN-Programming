/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int> > Maxque,Minque;
int a[1000100];
long long ans;
int main()
{
    int n,p,q,in,i,j,low=0;
	scanf("%d %d %d",&n,&p,&q);
	for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        while(!Maxque.empty() && Maxque.front().second<=low)Maxque.pop_front();
        while(!Minque.empty() && Minque.front().second<=low)Minque.pop_front();
        while(!Maxque.empty() && Maxque.back().first<a[i])Maxque.pop_back();
        while(!Minque.empty() && Minque.back().first>a[i])Minque.pop_back();
        Maxque.push_back({a[i],i});
        Minque.push_back({a[i],i});
        while(Maxque.front().first-Minque.front().first>q){
            low++;
            while(!Maxque.empty() && Maxque.front().second<=low)Maxque.pop_front();
            while(!Minque.empty() && Minque.front().second<=low)Minque.pop_front();
        }
        ans+=i-low;
	}
	while(!Maxque.empty())Maxque.pop_back();
	while(!Minque.empty())Minque.pop_back();
	low=0;
	if(p==0){printf("%lld",ans);return 0;}
	for(i=1;i<=n;i++){
        while(!Maxque.empty() && Maxque.front().second<=low)Maxque.pop_front();
        while(!Minque.empty() && Minque.front().second<=low)Minque.pop_front();
        while(!Maxque.empty() && Maxque.back().first<a[i])Maxque.pop_back();
        while(!Minque.empty() && Minque.back().first>a[i])Minque.pop_back();
        Maxque.push_back({a[i],i});
        Minque.push_back({a[i],i});
        while(Maxque.front().first-Minque.front().first>p-1){
            low++;
            while(!Maxque.empty() && Maxque.front().second<=low)Maxque.pop_front();
            while(!Minque.empty() && Minque.front().second<=low)Minque.pop_front();
        }
        ans-=i-low;
	}
	printf("%lld\n",ans);
    return 0;
}
/*
7 4 6
1 7 4 3 9 6 8
*/
