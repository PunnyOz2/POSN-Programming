#include<bits/stdc++.h>
using namespace std;
long long lift[12],nun[12],st[12];
long long wi[10000100];
long long tim[12];
long long n,m,q,ch;
long long cap[12],mark[12],permu[12];
long long check;//tim
long long chh;
void play(long long state){
    long long i,pos,ed,cou,idx;
    if(n+1==state){
        for(i=1;i<=n;i++){
            cap[i]=lift[i]-nun[permu[i]];
            if(cap[i]<0)return;
        }
        for(i=1;i<=n;i++){
            pos=st[i];
            ed=st[i+1]-1;
            if(i==n)ed=m;
            cou=0;
            while(pos<ed+1){
                idx=upper_bound(wi+pos,wi+ed+1,cap[i]+wi[pos-1])-wi;
                if(wi[pos]-wi[pos-1]>cap[i])return;
                cou++;
                if(cou>check)return;
                pos=idx;
            }
        }
        ch=1;
        return;
    }
    if(chh==0){
        for(i=1;i<=n;i++)permu[i]=i;
        play(n+1);
        return;
    }
    for(i=1;i<=n;i++){
        if(mark[i]==1)continue;
        mark[i]=1;
        permu[state]=i;
        play(state+1);
        mark[i]=0;
        if(ch==1)return;
    }
}
int main(){
    long long i,j;
    scanf("%lld %lld %lld",&n,&m,&q);
    for(i=1;i<=n;i++){
        scanf("%lld",&lift[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&nun[i]);
        if(i!=1 && nun[i]!=nun[i-1])chh=1;
    }
    for(i=1;i<=m;i++){
        scanf("%lld",&wi[i]);
        wi[i]+=wi[i-1];
    }
    for(i=1;i<=q;i++){
        scanf("%lld",&tim[i]);
    }
    for(i=1;i<=q;i++){
        ch=0;
        for(j=1;j<=n;j++){
            scanf("%lld",&st[j]);
        }
        check=tim[i];
        play(1);
        if(ch==1)printf("P\n");
        else printf("F\n");
    }
    return 0;
}
/*
2 10 3
230 300
56 65
160 120 35 80 42 87 72 45 55 63
2 2 1
1 4
1 3
1 6

3 8 1
150 100 200
45 60 55
1 1 1 1 1 1 1 1
2
1 3 5

3 8 1
150 100 200
45 60 55
80 45 50 62 48 40 68 55
2
1 3 5
*/
