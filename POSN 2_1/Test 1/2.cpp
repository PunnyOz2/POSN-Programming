/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200][1200];
int main()
{
	int q,Minn,Min,ansn,n,i,j;
	scanf("%d",&q);
	while(q--){
        scanf("%d",&n);
        Minn=1<<30;
        for(i=1;i<=n;i++){
            Min=0;
            for(j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
                Min+=a[i][j];
            }
            if(Min<Minn)Minn=Min,ansn=i;
        }
        Min=1<<30;
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                if(i!=ansn)Min=min(Min,a[i][j]);
            }
        }
        int ch=0,cou=0;
        int k;
        for(j=1;j<=n;j++){
            ch=0;
            for(k=1;k<=n;k++){
                if(k!=ansn && k!=j && a[ansn][j]==a[ansn][k]+a[k][j]) {printf("%d no --> %d\n",ansn,j),ch=1;}
            }
            if(ch==1)cou++;
        }
        printf("%d %d\n",ansn,n-cou-1);
	}
    return 0;
}
/*
4
7
0 13 5 8 12 17 15
13 0 8 11 15 20 18
5 8 0 3 7 12 10
8 11 3 0 10 15 13
12 15 7 10 0 5 3
17 20 12 15 5 0 8
15 18 10 13 3 8 0

4
0 7 12 8
7 0 5 1
12 5 0 6
8 1 6 0

6
0 1 2 3 4 5
1 0 3 4 5 6
2 3 0 5 6 7
3 4 5 0 7 8
4 5 6 7 0 9
5 6 7 8 9 0

4
0 7 12 8
7 0 5 1
12 5 0 6
8 1 6 0
*/
