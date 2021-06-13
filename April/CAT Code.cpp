#include<bits/stdc++.h>
using namespace std;
#define hashsize 1000003
long long hashh[1000003];
char num[1000100];
long long ans[1000100];
long long mark[1000100];
long long num2[1000100];
long long n,len,i,strnum,sum,j,h,now,q;
int main()
{
	scanf("%lld %lld",&n,&len);
	for(i=1;i<=n;i++){
        scanf(" %s",num);
        sum=0;
        for(j=0;j<len;j++){
            sum*=2;
            sum+=(num[j]-'0');
        }
        h=sum;
        h%=hashsize;
        now=1;
        while(hashh[h]!=0){
            h+=now;
            now<<=1;
            h%=hashsize;
        }
        hashh[h]=i;
        num2[h]=sum;
	}
	scanf("%lld",&q);
	while(q--){
        long long cou=0;
        scanf(" %lld %s",&strnum,num);
        if(strnum<len){printf("OK\n");continue;}
        long long ch=0;
        sum=0;
        for(j=0;j<len;j++){
            sum*=2;
            sum+=(num[j]-'0');
        }
        int Minus=pow(2,len);
        for(i=len;i<=strnum;i++){
            h=sum;
            h%=hashsize;
            now=1;
            while(hashh[h]!=0){
                if(num2[h]==sum){
                    mark[hashh[h]]=i;
                    ans[cou++]=hashh[h];
                    ch=1;
                    break;
                }
                h+=now;
                now<<=1;
                h%=hashsize;
            }
            sum*=2;
            sum+=(num[i]-'0');
            sum-=((num[i-len]-'0')*Minus);
        }
        if(ch==0)printf("OK");
        else {
            sort(ans,ans+cou);
            for(i=0;i<cou;i++)if(ans[i]!=ans[i-1])printf("%lld ",ans[i]);
        }
        printf("\n");
	}
    return 0;
}
/*
5 5
01001
10110
11100
10100
11111
2
15
101010101010101
20
11110110011111000010
*/
