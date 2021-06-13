#include <bits/stdc++.h>
using namespace std;
int a[2010][2010],b[2010][2010];
int qsd[2010][2010],qss[2010][2010];
int main(){
    int n,m,k,i,j,temp,temp2,Max=-1<<30,temp3;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            b[i][m-j+1]=a[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            temp=max(0,i-k);
            temp2=max(0,j-k);
            temp3=min(m+1,j+k);
            qsd[i][j]=qsd[i-1][j]+a[i][j]-a[temp][j];
            qss[i][j]=qss[i-1][j-1]+a[i][j]-a[temp][temp2];
        }
    }
    for(i=k;i<=n;i++){
        temp=0;
        for(j=1;j<k;j++){
            temp+=qss[i][j];
        }
        for(j=k;j<=m;j++){
            temp+=qss[i][j];
            temp-=qsd[i][j-k];
            Max=max(Max,temp);
        }
    }
    //printf("%d\n",Max);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            temp=max(0,i-k);
            temp2=max(0,j-k);
            temp3=min(m+1,j+k);
            qsd[i][j]=qsd[i-1][j]+b[i][j]-b[temp][j];
            qss[i][j]=qss[i-1][j-1]+b[i][j]-b[temp][temp2];
        }
    }
    for(i=k;i<=n;i++){
        temp=0;
        for(j=1;j<k;j++){
            temp+=qss[i][j];
        }
        for(j=k;j<=m;j++){
            temp+=qss[i][j];
            temp-=qsd[i][j-k];
            Max=max(Max,temp);
        }
    }
    printf("%d\n",Max);
}
/*
4 5 3
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

6 6 3
1 1 1 1 1 1
1 1 1 1 1 100
1 1 1 1 1 100
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
*/
