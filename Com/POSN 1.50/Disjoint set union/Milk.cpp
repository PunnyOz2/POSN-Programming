/*
    TASK: Milk
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int findroot(int i){
    if(p[i]==i) return i;
    return p[i]=findroot(p[i]);
}
int main()
{
    int n,q,i,x,y;
    char a;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++) p[i]=i;
    while(q--){
        scanf(" %c %d %d",&a,&x,&y);
        if(a=='q'){
            if(findroot(x)==findroot(y))
                printf("yes\n");
            else printf("no\n");
        }
        else
            p[findroot(x)]=findroot(y);
    }
    return 0;
}
/*
5 10
q 1 2
c 1 3
q 3 2
c 3 2
q 1 2
q 4 5
c 4 2
q 4 1
c 1 4
q 5 1
*/
