/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,sum=0,a,Min=1000;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        Min=min(a,Min);
        sum+=a;
    }
    printf("%d",sum+Min*(n-3));
    return 0;
}
/*
4 4
B R D N
D R B D
R R R D
N N N N
*/
