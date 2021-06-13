/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define hashsize 1<<21
char a[25],b[100100];
int hashh[21][(1<<21)];
int dp[100100];
int main()
{
    int n,sum,i,lena,j,h,now,lenb;
    dp[0]=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s",a);
        lena=strlen(a);
        sum=0;
        for(j=0;j<lena;j++){
            sum*=2;
            sum+=(a[j]-'0');
        }
        h=sum;
        hashh[lena][h]=1;
    }
    scanf(" %s",b+1);
    lenb=strlen(b+1);
    for(i=1;i<=lenb;i++){
        int num=0,cnt=0;
    //    printf("%d\n",i);
        for(j=i;j>=max(1,i-20+1);j--){
            num+=((1<<cnt)*(b[j]-'0'));
            cnt++;
       //     printf("%d %d\n",i-j+1,num);
            if(hashh[i-j+1][num]==1){
                dp[i]+=dp[j-1];
                dp[i]%=1000000007;
            }
        }
    }
    //for(i=0;i<=lenb;i++)printf("%d ",dp[i]);
    printf("%d\n",dp[lenb]);
    return 0;
}
/*
6
101
110
01
1
0
10
1101010000110
*/
