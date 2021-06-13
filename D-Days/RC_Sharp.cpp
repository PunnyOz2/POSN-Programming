/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[510],b[510][30];
long long ans[510];
int main()
{
    long long n,k,l,idx,i,j;
    scanf("%lld %lld %lld %lld",&n,&k,&l,&idx);
    scanf(" %s",a);
    idx--;
    i=0;
    while(idx>0){
        ans[i++]=idx%l;
        idx/=l;
    }
    reverse(ans,ans+k);
    for(i=0;i<k;i++){
        scanf(" %s",b[i]);
        sort(b[i],b[i]+l);
    }
    long long len=strlen(a);
    idx=0;
    for(i=0;i<len;i++){
        if(a[i]=='#'){
            printf("%c",b[idx][ans[idx++]]);
        }
        else printf("%c",a[i]);
    }
    return 0;
}
/*
9 2 3 7
peat#hi#y
sol
nuz
*/
