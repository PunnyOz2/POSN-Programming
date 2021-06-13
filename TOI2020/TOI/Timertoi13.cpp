/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int p[5000100];
char a[10000100];
int main(){
    int n,i,j;
    scanf("%d",&n);
    scanf(" %s",a+1);
    for(i=n+1;i<=n*2;i++){
        a[i]=a[i-n];
    }
    j=0;
    for(i=2;i<=n*2;i++){
        while(j>0 && a[i]!=a[j+1])j=p[j];
        if(a[i]==a[j+1])j++;
        p[i]=j;
        if(j==n){printf("%d\n",i-n);break;}
    }
    return 0;
}
/*
10
1010101010

8
10001000
*/
