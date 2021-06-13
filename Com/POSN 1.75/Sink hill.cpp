/*
    TASK: Sink hill
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int l[1010][1010],d[1010][1010],u[1010][1010],R[1010][1010];
int a[1010][1010];
int main()
{
    int q,r,c,i,j,ma=-1,ansi,ansj;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                scanf("%d",&a[i][j]);
        for(i=1;i<=r;i++){
            l[i][1]=1;
            for(j=2;j<=c;j++)
                if(a[i][j]>=a[i][j-1])
                    l[i][j]=l[i][j-1]+1;
                else
                    l[i][j]=1;
            R[i][c]=1;
            for(j=c-1;j>=1;j--)
                if(a[i][j]>=a[i][j+1])
                    R[i][j]=R[i][j+1]+1;
                else
                    R[i][j]=1;
        }
        for(j=1;j<=c;j++){
            u[1][j]=1;
            for(i=2;i<=r;i++)
                if(a[i][j]>=a[i-1][j])
                    u[i][j]=u[i-1][j]+1;
                else
                    u[i][j]=1;
            d[r][j]=1;
            for(i=r-1;i>=1;i--)
                if(a[i][j]>=a[i+1][j])
                    d[i][j]=d[i+1][j]+1;
                else
                    d[i][j]=1;
        }
        for(ma=-1,ansi=1,ansj=1,i=1;i<=r;i++){
            for(j=1;j<=c;j++)
                if(l[i][j]+R[i][j]+u[i][j]+d[i][j]-3>ma)
                    ma = l[i][j]+R[i][j]+u[i][j]+d[i][j]-3,
                    ansi=i,ansj=j;
        }

        printf("%d\n%d %d\n",ma,ansi,ansj);
        memset(l,0,sizeof l);
        memset(R,0,sizeof R);
        memset(u,0,sizeof u);
        memset(d,0,sizeof d);
        memset(a,0,sizeof a);
    }
    return 0;
}
/*
2
4 6
7 3 5 7 2 4
1 5 2 6 2 10
8 4 1 2 3 2
10 7 10 7 3 8
*/
