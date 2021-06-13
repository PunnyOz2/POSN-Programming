/*
    TASK: House
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[310][310];
int main()
{
    int r,c,k,i,j,sum,s,t,Max=-100000;
    scanf("%d %d %d",&r,&c,&k);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            sum=a[i][j];
            for(s=i-1,t=0;s>=0&&t<k;s--,t++){
                if(t%2==0) sum-=a[s][j];
                else sum+=a[s][j];
            }
            for(s=i+1,t=0;s<r&&t<k;s++,t++){
                if(t%2==0) sum-=a[s][j];
                else sum+=a[s][j];
            }
            for(s=j-1,t=0;s>=0&&t<k;s--,t++){
                if(t%2==0) sum-=a[i][s];
                else sum+=a[i][s];
            }
            for(s=j+1,t=0;s<c&&t<k;s++,t++){
                if(t%2==0) sum-=a[i][s];
                else sum+=a[i][s];
            }
            if(sum>Max) Max=sum;
        }
    }
    printf("%d\n",Max);
    return 0;
}
/*
5 4 2
2 2 3 5
3 2 4 0
5 3 1 2
0 2 0 1
3 2 1 5
*/
