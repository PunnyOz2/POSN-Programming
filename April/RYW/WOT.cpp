/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
#define hs 5000011
int hasht[hs],keep[hs][2],a[4][1510],x[4][1510],y[4][1510];
int main()
{
	int n,i,j,k,l,r,s,xt,yt,xx,yy,t;
	scanf("%d %d %d",&xt,&yt,&n);
	for(i=0;i<4;i++)
        for(j=0;j<n;j++)
            scanf("%d %d",&x[i][j],&y[i][j]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            xx=x[0][i]+x[1][j],yy=y[0][i]+y[1][j];
            t=((xx+(3*yy)%hs)%hs+hs)%hs;
            while(hasht[t]){
                t++,t%=hs;
            }
            hasht[t]=1500*i+j+1;
            keep[t][0]=xx,keep[t][1]=yy;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            xx=xt-(x[2][i]+x[3][j]),yy=yt-(y[2][i]+y[3][j]);
            t=((xx+(3*yy)%hs)%hs+hs)%hs;
            while(hasht[t]){
                if(keep[t][0]==xx && keep[t][1]==yy){
                    r=hasht[t]-1;
                    printf("%d %d\n",x[0][r/1500],y[0][r/1500]);
                    printf("%d %d\n",x[1][r%1500],y[1][r%1500]);
                    printf("%d %d\n",x[2][i],y[2][i]);
                    printf("%d %d\n",x[3][j],y[3][j]);
                    return 0;
                }
                t++,t%=hs;
            }
        }
    }
    return 0;
}
/*
-2 2
2
1 2 -2 10
-6 -6 -1 3
-1 -2 -6 -5
5 -4 7 0
*/
