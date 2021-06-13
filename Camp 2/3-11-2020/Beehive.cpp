/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int cc[1010][1010];
int main()
{
    int n,m,i,j,w,Max=0,cou=1,temp;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=m;i++){
        cc[1][i]=1;
    }
    for(i=2;i<=n;i++){
        for(j=1;j<=m;j++){
            cou=0;
            temp=0;
            if(i%2==1){
                if(temp<a[i-1][j-1]){
                    temp=a[i-1][j-1];
                    cou+=cc[i-1][j-1];
                }
                if(temp<a[i-1][j]){
                    temp=a[i-1][j];
                    cou=cc[i-1][j];
                }
                else if(temp==a[i-1][j]){
                    cou+=cc[i-1][j];
                }
            }
            if(i%2==0){
                if(temp<a[i-1][j+1]){
                    temp=a[i-1][j+1];
                    cou+=cc[i-1][j+1];
                }
                if(temp<a[i-1][j]){
                    temp=a[i-1][j];
                    cou=cc[i-1][j];
                }
                else if(temp==a[i-1][j]){
                    cou+=cc[i-1][j];
                }
            }
            cc[i][j]=cou;
            a[i][j]+=temp;
        }
    }
    Max=0;
    cou=0;
    for(i=1;i<=m;i++){
        if(Max<a[n][i]){
            Max=a[n][i];
            cou=cc[n][i];
        }
        else if(Max==a[n][i]){
            cou+=cc[n][i];
        }
    }
    printf("%d %d\n",Max,cou);
    return 0;
}
/*
7 5
10 8 25 13 16
4 23 12 1 14
14 17 0 11 26
6 3 3 8 10
4 5 16 5 14
8 4 4 1 7
8 3 1 4 5
*/
