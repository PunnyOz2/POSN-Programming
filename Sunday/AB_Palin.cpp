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
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        if((i/2)%2==0)printf("a");
        else printf("b");
    }
    return 0;
}
