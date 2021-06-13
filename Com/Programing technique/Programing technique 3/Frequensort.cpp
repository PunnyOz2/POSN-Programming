/*
    TASK: AncientPeatt
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200];
int main()
{
    int n,c,i,b,j,freq;
    scanf("%d %d",&n,&c);
   for(i=0;i<n;i++){
        scanf("%d",&b);
        a[b]++;
   }
        sort(a,a+n);
        for(i=n-1;i>=0;i++){
            if(a[i]!=0){
                freq = a[i];
                for(j=0;j<freq;j++)
                    printf("%d",a[i]);}
            else continue;

        }


    return 0;
}

