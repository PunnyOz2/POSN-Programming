/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);

    }
    sort(a+1,a+n+1);
    int left=n%5;
    int time=n/5;
    for(i=1;i<=time*3;i++){
        sum+=a[i];//printf("%d\n",a[i]);
    }
    for(i=time*3+1;i<=time*3+left;i++){

        sum+=a[i];
    }
    for(i=n;i>n-time*2;i-=2){
        sum+=a[i];
    }
    printf("%d\n",sum);
//    for(i=1;i<=n;i++){
//        printf("%d ",a[i]);
//    }
    return 0;
}
/*
12
3
14
15
9
26
31
53
58
9
79
32
38
*/
