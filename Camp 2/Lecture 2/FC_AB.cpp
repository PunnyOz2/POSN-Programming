#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    int n,num,old,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]*=i;
    }
    for(i=1;i<=n;i++){
        printf("%d ",a[i]-a[i-1]);
    }
}
