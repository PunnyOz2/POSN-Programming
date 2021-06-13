/*
    TASK: MTEX
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long a[7][7],b,c,n,i,j,temp[7][7],ans[7][7],k;
void pow(long long b){
    if(b==0){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i==j)ans[i][j]=1;
                return;
    }
    if(b==1){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                ans[i][j]=a[i][j]%c;
                return;
    }
    pow(b/2);
    if(b%2==0){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                temp[i][j]=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    temp[i][j]+=(ans[i][k]*ans[k][j])%c;
                }
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                ans[i][j]=temp[i][j]%c;
    }
    if(b%2==1){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                temp[i][j]=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    temp[i][j]+=(ans[i][k]*ans[k][j])%c;
                }
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                ans[i][j]=temp[i][j]%c,temp[i][j]=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    temp[i][j]+=(ans[i][k]*a[k][j])%c;
                }
            }
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                ans[i][j]=temp[i][j]%c;
    }
}
int main()
{
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%lld",&a[i][j]);
    scanf("%lld %lld",&b,&c);
    pow(b);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)printf("%lld ",ans[i][j]);
        printf("\n");
    }
    return 0;
}
/*
2
5 8
21 6
2 100
*/
