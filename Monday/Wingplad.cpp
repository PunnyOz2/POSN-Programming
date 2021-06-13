/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,k,i,gcd,num;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++){
            if(i==0){
                scanf("%d",&gcd);
            }
            else{
                scanf("%d",&num);
                gcd=__gcd(gcd,num);
            }
        }
        k--;
        printf("%d\n",(k/gcd) *gcd);
    }
    return 0;
}
/*
1
2 11
2 3
*/
