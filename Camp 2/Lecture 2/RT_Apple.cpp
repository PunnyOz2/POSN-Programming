#include <bits/stdc++.h>
using namespace std;
int spacey[550][550];
char a[550][550];
int main(){
    int n,m,i,j,jj,q,Min;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            spacey[i][j]=1<<30;
        }
    }
    for(j=1;j<=m;j++){
        for(i=1;i<=n;i++){
            if(spacey[i-1][j]!=1<<30 &&i!=1)spacey[i][j]=spacey[i-1][j]+1;
            if(a[i][j]=='x')spacey[i][j]=0;
        }
        for(i=n;i>=1;i--){
            if(spacey[i+1][j]!=1<<30 &&i!=n)spacey[i][j]=min(spacey[i][j],spacey[i+1][j]+1);
        }
    }
//    for(i=1;i<=n;i++){
//        for(j=1;j<=m;j++){
//            printf("%d ",spacey[i][j]);
//        }
//        printf("\n");
//    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&i,&j);
        Min=1<<30;
        for(jj=1;jj<=m;jj++){
            if(spacey[i][jj]==1<<30)continue;
            Min=min(Min,(spacey[i][jj]*spacey[i][jj])+(abs(jj-j)*abs(jj-j)));
        }
        printf("%d\n",Min);
        a[i][j]='x';
        for(i=1;i<=n;i++){
            if(spacey[i-1][j]!=1<<30 &&i!=1)spacey[i][j]=spacey[i-1][j]+1;
            if(a[i][j]=='x')spacey[i][j]=0;
        }
        for(i=n;i>=1;i--){
            if(spacey[i+1][j]!=1<<30 &&i!=n)spacey[i][j]=min(spacey[i][j],spacey[i+1][j]+1);
        }
    }
}
/*
5 5
..x..
....x
.....
.....
.....
4
3 1
5 3
2 5
4 5

*/
