//Tawatwee
#include<bits/stdc++.h>
using namespace std;
vector<long long> g[120100],g2[120100];
long long a[120100],customer[120100];
int main()
{
    long long n,m,q,i,cou,j,num,opr,u,sum,val,Max=0,cus=0,lastopr=10;
    scanf("%lld %lld %lld",&n,&m,&q);
    for(i=1;i<=m;i++){
        scanf("%lld",&cou);
        for(j=0;j<cou;j++){
            scanf("%lld",&num);
            g[i].push_back(num);
            g2[num].push_back(i);
        }
        Max=max(Max,cou);
    }
    if(Max<=5){
        while(q--){
            scanf("%lld",&opr);
            if(opr==1){
                scanf("%lld %lld",&u,&val);
                for(auto x:g[u]){
                    customer[x]-=a[u];
                    customer[x]+=val;
                }
                a[u]=val;
            }
            else{
                scanf("%lld",&u);
                printf("%lld\n",customer[u]);
            }
        }
    }
    else{
        while(q--){
            scanf("%lld",&opr);
            if(opr==1){
                scanf("%lld %lld",&u,&val);
                a[u]=val;
            }
            else{
                sum=0;
                scanf("%lld",&u);
                if(lastopr==1){
                    for(auto x:g2[u]){
                        sum+=a[x];
                    }
                    printf("%lld\n",sum);
                    customer[u]=sum;
                }
                else{
                    printf("%lld\n",customer[u]);
                }
            }
            lastopr=opr;
        }
    }
    return 0;
}
/*
3 2 6
2 1 2
2 2 3
1 1 5
2 1
1 2 15
2 2
1 1 2
2 2
*/
