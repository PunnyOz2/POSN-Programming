/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000],kmp[1000];
int main()
{
    int i,j,n,lena,c[1000];
    char b[20]=" UUDDLRLRBAS";
    scanf(" %s",a+1);
    j=0;
    lena=strlen(a+1);
    for(i=2;i<=11;i++){
        while(j>0 && b[i]!=b[j+1])j=kmp[j];
        if(b[i]==b[j+1])j++;
        kmp[i]=j;
    }
    j=0;
    for(i=1;i<=lena;i++){
        while(j>0 && a[i]!=b[j+1])j=kmp[j];
        if(a[i]==b[j+1])j++;
        //c[i]=j;
    }
    for(i=j+1;i<=11;i++)
        printf("%c",b[i]);
    return 0;
}
