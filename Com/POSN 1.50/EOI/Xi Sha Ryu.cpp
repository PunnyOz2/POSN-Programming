/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[100100];
int main()
{
    int len,i,sum=0;
    scanf(" %s",a);
    len = strlen(a);
    sort(a,a+len,greater<int>());
    for(i=0;i<len;i++)
        sum+=a[i]-'0';
    if(sum%3==0 && a[len-1]=='0')
        printf("%s\n",a);
    else printf("-1\n");
    return 0;
}
