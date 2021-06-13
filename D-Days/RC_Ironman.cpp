/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1003];
int main()
{
    int n,m,i,ch,j,cou,Max=-1,sum;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        sum=0;
        cou=0;
        for(j=i;j<=n;j++){
            if(sum+a[j]>m)continue;
            sum+=a[j];
            cou++;
        }
        Max=max(Max,cou);
    }
    printf("%d\n",Max);
//    int l=1,r=n,mid;
//    while(l<r){
//        mid=(l+r+1)/2;
//        ch=1;
//        for(i=mid;i<=n;i++){
//            if(a[i]-a[i-mid]<=m){ch=0;goto jump;}
//            else{
//                for(j=mid+1;j<=n;j++){
//                    if(a[j]-a[j-1]+a[i-1]-a[i-mid]<=m){ch=0;goto jump;}
//                }
//            }
//        }
//        jump:;
//        if(ch==0)l=mid;
//        else r=mid-1;
//    }
//    printf("%d\n",l);
    return 0;
}
/*
7 6
2 6 4 3 2 3 1
*/
