/*
    TASK: impose minnum
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
string ar[100100];
bool cmp(string a,string b){
    if(a+b < b+a) return true;
    return false;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>ar[i];
    sort(ar,ar+n,cmp);
    for(i=0;i<n;i++){
        cout<<ar[i];
    }
    return 0;
}

