/*
    TASK: MaximumSubsequenceSum
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[20200];
int main()
{
    int q,i,sum=0,ansst=1,ansen,st=1,num,Max=-10000000000;
    int ch=1,ans2=-10000000,st2;
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d",&num);
        if(num>=0) ch=0;
        if(num>ans2) ans2=num,st2=i;
        sum+= num;
        if(sum>=0){
            if(sum>Max)
                Max=sum,ansst=st,ansen=i;
        }
        else
            sum=0,st=i+1;
    }
    if(ch)
        printf("%d %d\n%d\n",st2,st2,ans2);
    else
        printf("%d %d\n%d\n",ansst,ansen,Max);

    return 0;
}

