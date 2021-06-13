/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[2000100],nn[1000100];
int main()
{
    long long q,num,i,temp,ans,n;
    scanf("%lld",&q);
    while(q--){
        temp=ans=0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&num);
            if(num==2)num=1;
            if(num==-2)num=-1;
            nn[i]=num+nn[i-1];
            a[nn[i]+250000]++;
        }
        ans+=a[250000];
        //printf("%d\n",ans);
        for(i=1;i<=n;i++){
            temp+=nn[i]-nn[i-1];
            a[250000+nn[i]]--;
            ans+=a[250000+temp];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2
4
2 -2 -2 2
5
2 2 -2 -2 2
*/
