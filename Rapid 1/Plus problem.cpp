/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long q,num;
	scanf("%lld",&q);
	while(q--){
        scanf("%lld",&num);
        printf("%lld\n",((((num%1000000007)*((num+1)%1000000007)))/2)%1000000007);
	}
    return 0;
}
