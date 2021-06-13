/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
long long cou;
void mergesort(int l,int r){
    int mid=(l+r)/2;
    if(l==r)return ;
    mergesort(l,mid);
    mergesort(mid+1,r);
    int i=l,idx=i,j=mid+1;
    while(i<=mid && j<=r){
        if(a[i]>a[j]){
            b[idx++]=a[j++],cou+=mid-i+1;
        }
        else b[idx++]=a[i++];
    }
    while(i<=mid)b[idx++]=a[i++];
    while(j<=r)b[idx++]=a[j++];
    for(i=l;i<=r;i++)a[i]=b[i];
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(1,n);
    printf("%lld\n",cou);
    return 0;
}
/*

*/
