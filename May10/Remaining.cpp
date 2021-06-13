/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,ch=0;
    scanf("%d %d",&n,&a);
    if(a%(n-1)==0)ch=1;
    printf("%d %d\n",a+a/(n-1)-ch,a+a/(n-1));
    return 0;
}
