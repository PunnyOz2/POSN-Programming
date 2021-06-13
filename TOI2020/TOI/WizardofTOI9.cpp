#include <stdio.h>
#define dadhash 5000011
long long x[1600][1600];
long long y[1600][1600];
long long hasht[dadhash];
long long mark[3][dadhash];
int main(){
    long long xa,ya,n,i,j,r,s,t;
    scanf("%lld %lld",&xa,&ya);
    scanf("%lld",&n);
    for(i=0;i<4;i++){
        for(j=0;j<n;j++)scanf("%lld %lld",&x[i][j],&y[i][j]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            r=x[0][i]+x[1][j], s=y[0][i]+y[1][j];
            t=((r+s*3)%dadhash+dadhash)%dadhash;
            while(hasht[t]!=0){
                t++;
                t%dadhash;
            }
            hasht[t]=i*1500+j+1;
            mark[0][t]=r,mark[1][t]=s;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            r=xa-x[2][i]-x[3][j], s=ya-y[2][i]-y[3][j];
            t=((r+s*3)%dadhash+dadhash)%dadhash;
            while(hasht[t]!=0){
                if(mark[0][t]==r && mark[1][t]==s){
                    long long a=hasht[t]-1;
                    printf("%lld %lld\n",x[0][a/1500],y[0][a/1500]);
                    printf("%lld %lld\n",x[1][a%1500],y[1][a%1500]);
                    printf("%lld %lld\n",x[2][i],y[2][i]);
                    printf("%lld %lld\n",x[3][j],y[3][j]);
                    break;
                }
                t++;
                t%dadhash;
            }
        }
    }
}
/*
-2 2
2
1 2 -2 10
-6 -6 -1 3
-1 -2 -6 -5
5 -4 7 0
*/
