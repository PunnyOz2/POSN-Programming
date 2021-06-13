#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
unordered_map<long long,int> mp;
char a[2010],b[2010];
long long prime[27];
long long cou[27];
int main(){
    long long l,r,mid,lena,lenb,i,ch,temp,j,sum,ans;
    scanf(" %s %s",a+1,b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    l=1;
    r=min(lena,lenb);
    prime[0]=1;
    for(i=1;i<=25;i++)prime[i]=prime[i-1]*MOD;
    for(long long mid=2;mid<=r;mid++){
        ch=0;
        for(i=1;i<mid;i++){
            cou[a[i]-'A']++;
        }
        for(i=mid;i<=lena;i++){
            cou[a[i]-'A']++;
            if(i!=mid)cou[a[i-mid]-'A']--;
            sum=0;
            for(j=0;j<26;j++){
                sum+=cou[j]*prime[j];
//                printf("%lld ",cou[j]);
            }
//            printf("\n");
//            printf("%lld\n",sum);
            mp[sum]=1;
        }
        memset(cou,0,sizeof cou);
        for(i=1;i<mid;i++){
            cou[b[i]-'A']++;
        }
        for(i=mid;i<=lenb;i++){
            cou[b[i]-'A']++;
            if(i!=mid)cou[b[i-mid]-'A']--;
            sum=0;
            for(j=0;j<26;j++){
                sum+=cou[j]*prime[j];
//                printf("%lld ",cou[j]);
            }
//            printf("\n");
            if(mp[sum]==1){ch=1;break;}
        }
        memset(cou,0,sizeof cou);
        mp.clear();
        if(ch==1)ans=mid;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
DAABABD
CCBAAAB

AABAA
AAAA
*/
