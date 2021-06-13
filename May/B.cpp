/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[100003][13];
int main()
{
    int n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",num);
        a[i][num]+=a[i-1][num]+1;
    }
    for(i=1;i<=n;i++){
        for(i=2;i<=10;i++){
            if(a[i][num]==0)continue;
            else {

            }
        }
    }
    return 0;
}
