/*
    TASK:Oh my god
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int q[1100],dp[100100],sum,Q;
char a[100100],b[14];
int main()
{
    int n,lenb,lena,ans,i,j,fl,Pow,jj,ans2;
    scanf("%d %d %d",&n,&lenb,&lena);
    Pow=pow(2,lenb);
    for(i=1;i<=lena;i++){
        scanf(" %c",&a[i]);
        if(i>=lenb+1)dp[i]=(a[i]-'0')+dp[i-1]*2-((a[i-lenb]-'0')*Pow);
        else dp[i]=(a[i]-'0')+dp[i-1]*2;
    }
    for(j=0;j<n;j++){
        sum=0;
        scanf(" %s",b);
        for(i=lenb-1;i>=0;i--){
            sum+=(b[i]-'0')*(1<<(lenb-1-i));
        }
        q[j]=sum;
    }
    scanf("%d",&Q);
    ans=0;
    for(i=1;i<=lena;i++){
        for(j=0;j<n;j++){
            if(q[j]==dp[i])ans++;
        }
    }
    while(Q--){
        scanf(" %s",b);
        if(b[0]=='F'&&b[1]=='i'){
            printf("%d\n",ans);
        }
        if(b[0]=='F'&&b[1]=='l'){
            scanf("%d",&fl);
            if(a[fl+1]=='1'){
                for(i=fl+1;i<fl+1+lenb;i++){
                    if(i>=lena)continue;
                    for(j=0;j<n;j++){
                        if(q[j]==dp[i])ans--;
                    }
                    dp[i]-=(1<<(i-fl-1));
                    for(j=0;j<n;j++){
                        if(q[j]==dp[i])ans++;
                    }
                }
                a[i+1]='0';
            }
            else if(a[i+1]=='0'){
                for(i=fl+1;i<fl+1+lenb;i++){
                    if(i>=lena)continue;
                    for(j=0;j<n;j++){
                        if(q[j]==dp[i])ans--;
                    }
                    dp[i]+=(1<<(i-fl-1));
                    for(j=0;j<n;j++){
                        if(q[j]==dp[i])ans++;
                    }
                }
                a[i+1]='1';
            }
        }
    }
    return 0;
}
/*
3 5 30
010100101010111101010101110100
11010
10101
00100
8
Find
Flip 10
Find
Flip 22
Find
Flip 6
Flip 5
Find
*/
