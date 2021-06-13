/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[20],b[20];
int main()
{
    int n,i,m,aa,bb,mi=1<<30,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i],&b[i]);
    m=1<<n;
    for(i=1;i<m;i++){
        aa=1,bb=0;
        for(j=0;j<n;j++){
            if(i&(1<<j))
                aa*=a[j],bb+=b[j];
        }
        mi=min(mi,abs(aa-bb));
    }
    printf("%d\n",mi);
    return 0;
}
/*
4
1 7
2 6
3 8
4 9
*/
