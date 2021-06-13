#include<bits/stdc++.h>
using namespace std;
int cou[6],cou2[6];
int main(){
    int q,i,ans,n,num;
    scanf("%d",&q);
    while(q--){
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            cou[num]++;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            cou2[num]++;
        }
        for(i=1;i<=5;i++){
            if(((cou[i]+cou2[i])%2)==0){
                ans+=abs(cou[i]-cou2[i])/2;
            }
            else {printf("-1\n");goto jump;}
        }
        printf("%d\n",ans/2);
        jump:;
        memset(cou,0,sizeof cou);
        memset(cou2,0,sizeof cou2);
    }
    return 0;
}
/*
2
9
1 2 4 1 4 1 4 4 1
2 3 5 2 5 3 2 3 3
5
1 2 3 4 5
1 1 2 3 5
*/
