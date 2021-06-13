/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
    int q,i,j,k,n,m,ans;
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        printf("Case %d: ",i);
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        ans=0;
        for(j=0;j<n;j++)
            for(k=j+1;k<n;k++)
            if(a[j]>a[k])
                ans++;
        if(ans<=m && (m-ans)%2==0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
/*
3
6 10
6 2 1 4 5 3
3 1
3 2 1
6 5
6 2 1 4 5 3
*/
