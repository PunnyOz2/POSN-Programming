/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
string ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(n++;n>1;n/=2)
        ans = ((n&1)?"7":"4")+ans;
    cout<<ans;
    return 0;
}

