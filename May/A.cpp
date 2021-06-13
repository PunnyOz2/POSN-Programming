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
    int n,m;
    scanf("%d %d",&n,&m);
    if(m==0)printf("1\n");
    else if(m==n)printf("0\n");
    else {
        if(m>n/2){
            printf("%d\n",n-m);
        }
        else{
            printf("%d\n",m);
        }
    }
    return 0;
}
