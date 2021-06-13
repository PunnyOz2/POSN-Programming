/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,a,b,n,sum,u;
    scanf("%d %d %d",&a,&b,&n);
    for(i=a;i<=b;i++){
        sum=0;
            sum+=(i%10);
            sum+=(i%100)/10;
            sum+=(i%1000)/100;
            sum+=(i%10000)/1000;
        if(sum==n){
            printf("%d\n",i);
            break;
        }
    }
    for(i=b;i>=a;i--){
        sum=0;
            sum+=(i%10);
            sum+=(i%100)/10;
            sum+=(i%1000)/100;
            sum+=(i%10000)/1000;
        if(sum==n){
            printf("%d\n",i);
            break;
        }
    }

    return 0;
}
