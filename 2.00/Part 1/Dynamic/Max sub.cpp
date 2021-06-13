/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,num,ma=-1<<30,st=1,ansst,ansen,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        sum+=num;
        if(sum>ma)ma=sum,ansst=st,ansen=i;
        if(sum<0)
            sum=0,st=i+1;
    }
    printf("%d %d\n%d",ansst,ansen,ma);
    return 0;
}
/*
5
4 -6 3 -2 6
*/
