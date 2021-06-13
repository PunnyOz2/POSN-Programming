/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[300100];
int main()
{
    int n,k,l,r,i,sum,mid;
    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++){
        scanf("%d",&a[i]);
    }
    l=1;
    r=(1e9)+1;
    while(l<r){
        mid=(l+r+1)/2;
        sum=0;
        for(i=0;i<k;i++){
            sum+=a[i]/mid;
            if(a[i]%mid!=0)sum++;
        }
        if(sum>n)l=mid;
        else r=mid-1;
    }
    printf("%d\n",l+1);
    return 0;
}
