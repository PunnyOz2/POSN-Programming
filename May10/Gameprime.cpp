/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[500100],primech[500100],cou,prime[500100],check[500100],sum[500100];
vector<int> g[500100];
int play(int a){// state 0 is you 1 is Peatt
    if(a<=0)return 1;
    if(dp[a]!=-1)return dp[a];
    int ch=0,j=0,i;
//    for(i=0;i<cou;i++){
//        if(prime[i]>a)break;
//        if(a%prime[i]==0)sum+=prime[i],check[j++]=prime[i];
//    }
    //printf("%d \n",a);
    for(auto x:g[a]){
        if(play(sum[a]-x)==0){ch=1;break;}
    }
    return dp[a]=ch;
}
int main()
{
    int q,i,j,n;
    scanf("%d",&q);
    memset(dp,-1,sizeof dp);
    for(i=2;i<=500000;i++){
        if(primech[i]==0){
            sum[i]+=i;
            g[i].push_back(i);
            for(j=i*2;j<=500000;j+=i){
                sum[j]+=i;
                g[j].push_back(i);
                primech[j]=1;
            }
        }
    }
    while(q--){
        scanf("%d",&n);
        //printf("%d\n",sum[n]);
        if(play(n)==1)printf("1\n");
        else printf("2\n");
    }
    return 0;
}
/*
2
20
2
*/
