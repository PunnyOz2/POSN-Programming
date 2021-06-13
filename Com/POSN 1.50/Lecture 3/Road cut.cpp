/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],b[1010][1010];
int rowa[1010],rowb[1010],cola[1010],colb[1010];
int main()
{
    int r,c,i,j,sum=0,ma=-1;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            sum+=a[i][j];
            rowa[i]+=a[i][j];
            cola[j]+=a[i][j];
        }
    }
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                scanf("%d",&b[i][j]);
                rowb[i]+=b[i][j];
                colb[j]+=b[i][j];
            }
        }
        for(i=1;i<=r;i++)
            if(sum-rowa[i]+rowb[i-1]+rowb[i+1]>ma)
                ma=sum-rowa[i]+rowb[i-1]+rowb[i+1];
        for(i=1;i<=c;i++)
            if(sum-cola[i]+colb[i-1]+colb[i+1]>ma)
                ma=sum-cola[i]+colb[i-1]+colb[i+1];
        printf("%d\n",ma);


    return 0;
}
/*
5 4
2 3 2 1
4 5 8 4
2 5 3 2
1 4 0 2
2 1 8 1
1 2 3 2
2 2 2 1
2 1 1 2
1 2 1 0
1 1 1 0
*/
