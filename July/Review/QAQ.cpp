/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[120];
long long cou[120];
int main()
{
    long long acou=0,ans=0,lena,i,qcou=0;
    scanf(" %s",a+1);
    lena=strlen(a+1);
    for(i=1;i<=lena;i++){
        cou[i]+=cou[i-1];
        if(a[i]=='Q'){
            qcou++;
            ans+=cou[i];
        }
        if(a[i]=='A'){
            cou[i]+=qcou;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
