/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long stfreed[2200][2200],stfule[2200][2200];
long long stfree(long long a,long long b){
    if(a<0 || b<0)return 0;
    if(a==1 && b==0)return 1;
    if(stfreed[a][b]!=-1)return stfreed[a][b];
    if(b>=a)return stfreed[a][b]=0;
    return stfreed[a][b]=(stfree(a-1,b)%1000000007 +stfree(a,b-1)%1000000007)%1000000007;
}
long long stful(long long a,long long b){
    if(a<0 || b<0)return 0;
    if(a==0 && b==0)return 1;
    if(stfule[a][b]!=-1)return stfule[a][b];
    if(b<a)return stfule[a][b]=0;
    return stfule[a][b]=(stful(a-1,b)%1000000007+stful(a,b-1)%1000000007)%1000000007;
}
int main()
{
    long long q,a,b;
    scanf("%lld",&q);
    memset(stfreed,-1,sizeof stfreed);
    memset(stfule,-1,sizeof stfule);
    stfreed[0][0]=0;
    stfule[0][0]=1;
    while(q--){
        scanf("%lld-%lld",&a,&b);
        printf("%lld %lld\n",stfree(a,b),stful(b,b));
    }
    return 0;
}
/*
5
2-1
3-1
3-2
10-5
1000-500

*/
