/*
    TASK: Kanlaland
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long p[10100],fam[10100],a[10100];
long long fin(long long i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    long long n,f,i,r,s,d,pr,ps;
    scanf("%lld %lld",&n,&d);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&r,&s);
        p[i]=i,fam[i]=1;a[i]=r*s;
    }
    for(i=1;i<=d;i++){
        printf("Day: %lld\n",i);
        scanf("%lld %lld",&r,&s);
        pr=fin(r),ps=fin(s);
        if(pr==ps) printf("Family don\'t need to make war\n");
        else if(a[pr]>a[ps]){
            printf("Winner Family %lld\n",pr);
            p[ps]=pr,fam[pr]+=fam[ps],a[pr]+=a[ps];
        }
        else if(a[ps]>a[pr]){
            printf("Winner Family %lld\n",ps);
            p[pr]=ps,fam[ps]+=fam[pr],a[ps]+=a[pr];
        }
        else if(fam[pr]>fam[ps]){
            printf("Winner Family %lld\n",pr);
            p[ps]=pr,fam[pr]+=fam[ps],a[pr]+=a[ps];
        }
        else if(fam[ps]>fam[pr]){
            printf("Winner Family %lld\n",ps);
            p[pr]=ps,fam[ps]+=fam[pr],a[ps]+=a[pr];
        }
        else
            printf("Draw\n");
    }

    return 0;
}
/*
4 7
10 6
2 20
4 10
20 3
2 3
1 2
3 4
2 3
1 3
1 2
1 4
*/
