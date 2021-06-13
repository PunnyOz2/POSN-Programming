/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int Left[1010][1010];
int Right[1010][1010];
int downlev[1010][1010];
int uplev[1010][1010];
int main()
{
	int n,m,i,j,ansi,ansj,Max=-1;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)scanf(" %c",&a[i][j]);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            if(a[i][j]=='.')Left[i][j]=Left[i][j-1]+1;
        for(j=m;j>=1;j--)
            if(a[i][j]=='.')Right[i][j]=Right[i][j+1]+1;
    }
    for(j=1;j<=m;j++){
        for(i=2;i<=n;i++){
            if(a[i][j]=='.'){
                if(a[i-1][j]!='#'){
                    if(min(Left[i][j]-1,Right[i][j]-1)>downlev[i-1][j])downlev[i][j]=downlev[i-1][j]+1;
                    else downlev[i][j]=min(Left[i][j]-1,Right[i][j]-1);
                }
            }
        }
        for(i=n-1;i>=1;i--){
            if(a[i][j]=='.'){
                if(a[i+1][j]!='#'){
                    if(min(Left[i][j]-1,Right[i][j]-1)>uplev[i+1][j])uplev[i][j]=uplev[i+1][j]+1;
                    else uplev[i][j]=min(Left[i][j]-1,Right[i][j]-1);
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j]=='.'){
                if(min(downlev[i][j],uplev[i][j])>Max)Max=min(downlev[i][j],uplev[i][j]),ansi=i,ansj=j;
            }
        }
    }
    int now=0;
    for(i=ansi-Max;i<=ansi;i++,now++){
        for(j=ansj-now;j<=ansj+now;j++)a[i][j]='x';
    }
    now--;
    for(i=ansi;i<=ansi+Max;i++,now--){
        for(j=ansj-now;j<=ansj+now;j++)a[i][j]='x';
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
10 10
..#....#..
..........
.#....#...
..........
..........
.........#
..........
..#..#....
..........
.......#..

2 2
#.
..

4 4
#...
##..
....
....
*/
