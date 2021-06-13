/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[6000100];
deque<long long> q;
int main()
{
	long long n,k,Maxsum=0,ansi=0,i;
	scanf("%lld %lld",&n,&k);
	int ch=0;
	for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>0)ch=1;
        a[i]+=a[i-1];
	}
	if(ch==0){printf("0\n0\n");return 0;}
	q.push_back(0);
	for(i=1;i<=n;i++){
        while(!q.empty() && i-q.front()>k)q.pop_front();
        if(a[i]-a[q.front()]>Maxsum){
            Maxsum=a[i]-a[q.front()];
            ansi=i-q.front();
        }
        while(!q.empty() && a[i]<=a[q.back()])q.pop_back();
        q.push_back(i);
	}
	printf("%lld\n%lld\n",Maxsum,ansi);
    return 0;
}
/*
7
4
3
2
5
1
4
-7
10
*/
