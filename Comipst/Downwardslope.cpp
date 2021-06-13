/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 999999999
int fw[45][120000];
void update(int a,int val,int st){
    while(a<=80003){
        fw[st][a]+=val;
        fw[st][a]%=MOD;
        a+=(a&-a);
    }
}
int query(int a,int st){
    int sum=0;
    while(a>0){
        sum+=fw[st][a];
        sum%=MOD;
        a-=(a&-a);
    }
    return sum;
}
int a[120000];
int main()
{
    int n,k,i,num,now=0,temp,j,allposcan=0,idx=0,ch=0,ans=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=n;i>=1;i--){
        update(a[i],1,1);
        for(j=2;j<=k;j++){
            now=query(a[i]-1,j-1)%MOD;
            update(a[i],now,j);
        }
        ans+=now;
        ans%=MOD;
    }
    printf("%d\n",ans);
    return 0;
}
/*
5 3
5 4 3 2 1

11 4
4 8 11 2 1 10 9 3 5 6 7

*/
