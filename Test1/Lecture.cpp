#include<bits/stdc++.h>
using namespace std;
long long table[100100],take[100100],a[350][350];
int main()
{
    long long c,n,m,i,u,v,w,k,j,l,r,mid,old,ch,now;
    scanf("%lld %lld %lld",&c,&n,&m);
    for(i=1;i<=c;i++){
        scanf("%lld",&table[i]);
    }
    for(i=1;i<=c;i++){
        scanf("%lld",&take[i]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j)continue;
            a[i][j]=1<<30;
        }
    }
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        a[u][v]=w;
        a[v][u]=w;
    }
    if(m==n-1){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                for(k=1;k<=n;k++){
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            }
        }
    }
    else{
        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            }
        }
    }
    l=1;
    r=1000000000;
    while(l<r){
        mid=(l+r+1)/2;
        old=0;
        ch=1;
        for(i=1;i<c;i++){
            if(take[i]-old<0){ch=0;break;}
            now=take[i]-old-mid*a[table[i]][table[i+1]];
            if(now<0)old=-now;
            else old=0;
        }
        if(take[c]-old<0)ch=0;
        if(ch==1)l=mid;
        else r=mid-1;
    }
    printf("%lld\n",l);
    return 0;
}
/*
5 5 4
3 1 4 1 5
92 65 35 89 79
1 2 3
2 3 4
3 4 5
4 5 6
*/
