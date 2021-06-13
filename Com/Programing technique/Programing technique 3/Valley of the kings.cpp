/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010];
int main()
{
    int q,i,n,j,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=0,j=0,ans=0;i<n; ){
            if(a[i]==a[i+1])
                ans++,i+=2;
            else
                b[j++]=a[i],i++;
        }
        printf("%d\n",ans);
        for(i=0;i<j;i++)
            printf("%d ",b[i]);
        if(j==0) printf("Empty");

    }

    return 0;
}
/*
2 15 3 5 3 2 3 6 3 4 7 2 4 3 5 3 4
*/
