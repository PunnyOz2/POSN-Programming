/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<stdio.h>

int a[2000];
int main()
{
    int i,n,k,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=n-1;i>=0;i--)
        printf("%d ",a[i]);
    printf("\n");
    scanf("%d",&k);
    for(i=0;i<n;i++)
        if(a[i]==k)
            ans++;
    printf("%d\n",ans);

    return 0;
}
