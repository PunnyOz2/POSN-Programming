/*
    TASK: Fairy_Land
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int p[10100];
int lan;
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,learn,i,j,t,num=0,told;
    scanf("%d %d",&n,&lan);
    for(i=1;i<=lan;i++) p[i]=i;
    for(i=1;i<=n;i++){
        scanf("%d",&learn);
        if(learn==0){ num++;continue;}
        for(j=0;j<learn;j++){
            scanf("%d",&t);
            if(j==0)told=t;
            p[fin(t)]=fin(told);
            p[fin(told)]=fin(t);
            told=t;

        }
    }
    for(i=1;i<n;i++) printf("%d ",p[i]);
    sort(p,p+n);
    for(i=1;i<n;i++) printf("%d ",p[i]);
    for(i=1;i<n;i++){
        if(p[i]!=p[i+1]&&p[i+1]!=0) num++;
    }
    printf("%d",num);
    return 0;
}
/*
2 2
1 2
0

8 7
0
3 1 2 3
1 1
2 5 4
2 6 7
1 3
2 7 4
1 1
*/
