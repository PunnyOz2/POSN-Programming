/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    //Q1
    /*int n,num,k,i,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++) a[i]=1000000000;
    for(i=0;i<n;i++){
        scanf("%d",&num);
        for(j=num;j<=k;j++){
            a[j]=min(a[j-num]+1,a[j]);
        }
    }
    printf("%d",a[k]);
    */

    //Q2
    int n,i,sti,ansi,ansj,Max=-1000000,num,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        sum+=num;
        if(sum<0){sum=0,sti=i+1;continue;}
        if(sum>Max){
            Max=sum;
            ansi=sti;
            ansj=i;
        }
    }
    printf("%d %d %d",ansi,ansj,Max);
    return 0;
}
