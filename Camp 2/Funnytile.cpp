/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int type,i,j;
    bool operator<(const A&o)const{
        if(type!=o.type)return type<o.type;
        if(j!=o.j)return j<o.j;
        return i<o.i;
    }
};
vector<A> ans;
void play(int n,int imid,int jmid,int a,int b){
    int quad;
    if(a<imid && b<jmid) quad=0;
    if(a<imid && b>=jmid)quad=1;
    if(a>=imid && b<jmid) quad=2;
    if(a>=imid && b>=jmid) quad=3;
    ans.push_back({quad,imid-1,jmid-1});
    if(n<=2)return;
    if(quad==0) play(n/2,imid-n/4,jmid-n/4,a,b);
    else        play(n/2,imid-n/4,jmid-n/4,imid-1,jmid-1);
    if(quad==1) play(n/2,imid-n/4,jmid+n/4,a,b);
    else        play(n/2,imid-n/4,jmid+n/4,imid,jmid-1);
    if(quad==2) play(n/2,imid+n/4,jmid-n/4,a,b);
    else        play(n/2,imid+n/4,jmid-n/4,imid-1,jmid);
    if(quad==3) play(n/2,imid+n/4,jmid+n/4,a,b);
    else        play(n/2,imid+n/4,jmid+n/4,imid,jmid);
}
int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    play(n,n/2,n/2,b,a);
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for(auto x:ans)printf("%d %d %d\n",x.type,x.j,x.i);
    return 0;
}
/*

*/
