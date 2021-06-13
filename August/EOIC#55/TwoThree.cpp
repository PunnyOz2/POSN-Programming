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
    int q,d,a,b,ans=0;
    scanf("%d %d",&q,&d);
    while(q--){
        scanf("%d %d",&a,&b);
        if(abs(a-b)<=d){
            if(a<b)ans+=b;
            else ans+=a;
        }
        else{
            scanf("%d",&a);
            ans+=a;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
5 10
3 11
14 4
1 100
13
12 9
13 2
7
*/
