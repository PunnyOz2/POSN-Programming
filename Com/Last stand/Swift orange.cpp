/*
    TASK: Swift wood cut
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int c[1000100];
int main()
{
    int l,r,mid,n,p,ch=0,i,sum;
    scanf("%d %d",&n,&p);
    for(i=0;i<n;i++)
        scanf("%d",&c[i]);
    l=0,r=200000000;
    while(l<r){
        mid = (l+r+1)/2;
        for(i=0,sum=0;i<n;i++)
            sum+= c[i]/mid;
        if(sum==p) ch=1;
        if(sum>=p) l=mid;
        else r=mid-1;
    }
    printf((ch)?"YES\n%d\n":"NO\n%d\n",l);
    return 0;
}
/*
3 2
15
7
12
*/
