/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long qs[1000100],fw[1000100];
long long temp[1000100];
long long com[1000100];
long long query(long long a){
    long long sum=0;
    while(a>0){
        sum+=fw[a];
        a-=(a&-a);
    }
    return sum;
}
void update(long long a){
    while(a<1000003){
        fw[a]+=1;
        a+=(a&-a);
    }
}
int main()
{
    long long n,i,j,k,idx;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&qs[i]);
    }
    scanf("%lld",&k);
    for(i=1;i<=n;i++){
        qs[i]-=k;
        qs[i]+=qs[i-1];
        temp[i]=qs[i];
    }
    temp[0]=0;
    sort(temp,temp+1+n);
    idx=1;
    com[idx++]=temp[0];
    for(i=1;i<=n;i++){
        if(temp[i-1]==temp[i])continue;
        com[idx++]=temp[i];
    }
    long long cou=0,sum=0,idx2;
    idx2=lower_bound(com+1,com+idx,0)-com;
    update(idx2);
    for(i=1;i<=n;i++){
        idx2=lower_bound(com+1,com+idx,qs[i])-com;
        sum+=query(idx2);
        update(idx2);
    }
    printf("%lld\n",sum);
    return 0;
}
