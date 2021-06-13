/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
    double a[260][260];
};
A temp;
A mul(A a,A b){
    int i,j,k;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            temp.a[i][j]=0;
            for(k=1;k<=n;k++){
                temp.a[i][j]+= a.a[i][k] * b.a[k][j];
            }
        }
    }
    return temp;
}
A m[25],ans;
int main()
{
    int d,i,j;
    scanf("%d %d",&n,&d);
    for(i=1;i<=n;i++){
        scanf("%lf",&ans.a[i][1]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%lf",&m[0].a[j][i]);
        }
    }
    for(i=1;i<=20;i++){
        m[i]=mul(m[i-1],m[i-1]);
    }
    for(i=0;i<=20;i++){
        if(d&(1<<i))ans=mul(m[i],ans);
    }
    for(i=1;i<=n;i++){
        printf("%.2lf\n",ans.a[i][1]);
    }
    return 0;
}
/*
3 1
30 40 50
0.5 0.2 0.3
0.1 0.4 0.5
0.3 0.3 0.4
*/
