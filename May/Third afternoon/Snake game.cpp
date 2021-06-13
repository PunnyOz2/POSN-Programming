/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1003][1003];
int l[1003],r[1003];
int dp[1003];
int main()
{
    int n,m,i,j,sum=0;
    scanf("%d %d",&n,&m);
    l[0]=(1<<30)-1,r[0]=(1<<30)-1;
    for(i=1;i<=n;i++){
        l[i]=1<<30;
        r[i]=-1;
        for(j=1;j<=n;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='J')l[i]=min(l[i],j),r[i]=max(r[i],j);
        }
    }
    for(i=1;i<=n;i++){
        if((n-i)%2==1){
            dp[i]=max(l[i-1],r[i]);
        }
        else{
            dp[i]=min(r[i-1],l[i]);
        }
    }
    int old=1;
    for(i=n;i>0;i--){
        if(l[i-1]==1<<30 || r[i-1]==-1 ||l[i]==1<<30||r[i]==-1)continue;
        if((n-i)%2==1){
            sum+=max(abs(r[i]-old)+abs(r[i]-l[i-1]),abs(r[i-1]-old)+abs(r[i-1]-l[i-1]));
        }
        else{
            sum+=min(abs(l[i]-old)+abs(l[i]-r[i-1]),abs(l[i-1]-old)+abs(l[i]-r[i-1]));
        }
    }
    printf("%d\n",sum);
    return 0;
}
/*
5 5
...J.
.....
J..J.
J....
Z..J.
*/
