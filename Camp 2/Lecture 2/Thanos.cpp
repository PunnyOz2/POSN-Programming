#include <bits/stdc++.h>
using namespace std;
char a[3010][3010];
int main(){
    int n,m,i,j,Min=4000,now,ch,cou,Maxj=0,Minj=4000;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
        for(j=1;j<=m;j++){
            if(a[i][j]=='X'){
                Maxj=max(Maxj,j);
                Minj=min(Minj,j);
            }
        }
    }
    for(j=Minj;j<=Maxj;j++){
        now=0;
        ch=0;
        cou=0;
        for(i=n;i>=1;i--){
            if(a[i][j]=='X'){
                Min=min(Min,cou);
                break;
            }
            if(ch==1 && a[i][j]=='#'){
                cou=0;
                ch=0;
            }
            else if(ch==1){
                cou++;
            }
            else if(a[i][j]=='.'){
                ch=1;
                cou++;
            }
        }
    }
    for(i=n;i>=1;i--){
        for(j=Minj;j<=Maxj;j++){
            if(a[i][j]=='X'){
                a[i][j]='.';
                a[i+Min][j]='X';
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
/*
5 6
XXXXX.
..XX..
..X.#.
#..###
######

6 6
######
#..XX#
#....#
#..###
#.....
######
*/
