#include <bits/stdc++.h>
using namespace std;
int lis[1000100];
int main(){
    int n,cou=0,i,num,pos;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        pos=upper_bound(lis,lis+cou,num)-lis;
        if(pos==cou)cou++;
        lis[pos]=num;
    }
    printf("%d\n",n-cou);
}
/*
4
5 4 3 6
1 2 3 4
4
4 3 2 1
*/
