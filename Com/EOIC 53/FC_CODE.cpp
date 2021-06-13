/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[4][15];
char b[4];
int n,ans;
int main()
{
    scanf("%d",&n);
    while(n--){
        scanf(" %s",b);
         if(a[0][b[0]]!=0) ans+=a[0][b[0]];
         if(a[1][b[1]]!=0) ans+=a[1][b[1]];
         if(a[2][b[2]]!=0) ans+=a[2][b[2]];
        a[0][b[0]]++;
        a[1][b[1]]++;
        a[2][b[2]]++;
    }
    printf("%d",ans);
    return 0;
}
/*
5
235
236
136
004
174

*/
