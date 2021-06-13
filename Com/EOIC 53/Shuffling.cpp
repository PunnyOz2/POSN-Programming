/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
    int i,m,k,len,st;
    int a[1100100];
    char b[100100];
int main()
{
    scanf("%d %d %s",&m,&k,b);
    len = strlen(b);
    for(i=0;i<m;i++)a[i]=i;
    for(i=0,st=0;i<len-1;i++)
        if(b[i]=='A'){
            st++;
            a[m-1+st]=a[st-1];
        }
        else if(b[i]=='B'){
            st++;
            a[m-1+st]=a[st];
            a[st]=a[st-1];
        }
    printf("%d %d %d",a[k-1+st],a[k+st],a[k+1+st]);

    return 0;
}/*
6 3
ABBABA.
*/
