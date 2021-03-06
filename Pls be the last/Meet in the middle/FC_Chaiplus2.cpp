/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> m[3];
int a[2],v[35],w[35],W,val[1<<16],wei[1<<16];
void play(int type,int i,int we,int va){
    if(we>W)return ;
    if(i==a[type]){
            m[type][we]=max(m[type][we],va);
        return;
    }
    play(type,i+1,we+w[i],va+v[i]);//choose
    play(type,i+1,we,va);//not
}
int main()
{
    int q,ans,n,i,idx;
    scanf("%d",&q);
    while(q--){
        m[0].clear(),m[1].clear(),ans=0;
        scanf("%d %d",&n,&W);
        a[0]=n/2,a[1]=n;
        for(i=0;i<n;i++){
            scanf("%d %d",&w[i],&v[i]);
        }
        play(0,0,0,0);
        play(1,n/2,0,0);
        i=0;
        for(auto it=m[0].begin();it!=m[0].end();it++,i++){
            wei[i] = it->first;
            val[i] = it->second;
            if(i>0)val[i]=max(val[i],val[i-1]);
        }
        for(auto it=m[1].begin();it!=m[1].end();it++){
            idx=upper_bound(wei,wei+i,W-it->first)-wei;
            idx--;
            if(idx!=-1)
                ans=max(ans,it->second+val[idx]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
1
4 100
33 15
35 30
34 25
33 20
*/
