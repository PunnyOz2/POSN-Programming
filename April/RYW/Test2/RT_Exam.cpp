/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005],day[100005],mark[100005],coun;
int main()
{
    int n,k,i,lef,l,r,mid;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=k;i++)
        scanf("%d",&day[i]);
    l=1,r=n+1;
    while(l<r){
        mid=(l+r)/2;
        memset(mark,0,sizeof mark);
        for(lef=0,coun=0,i=mid;i>0;i--){
            if(!mark[a[i]] && a[i]!=0){
                mark[a[i]]=1;
                lef+=day[a[i]];
                coun++;
            }
            else if(lef>0)
                lef--;
        }
        if(coun==k&&lef==0){
            r=mid;
        }
        else l=mid+1;
    }
    if(l!=n+1)printf("%d\n",l);
    else printf("-1\n");
    return 0;
}
