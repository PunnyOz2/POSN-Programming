#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    int n,q,i,l,r;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]^=a[i-1];
    }
    while(q--){
        scanf("%d %d",&l,&r);
        printf("%d\n",a[r]^a[l-1]);
    }
    return 0;
}
/*
5 5
2 6 2 9 1
5 5 1 5 2 3 4 5 2 4
*/
