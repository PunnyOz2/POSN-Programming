#include <bits/stdc++.h>
using namespace std;
int monstate[200100];
vector<int> stick[100100];//height
int polesum[200100];
int pos[200100],pos2[200100];
int current[200100];
int current2[200100];
int main(){
    int h,n,m,i,u,v,num,hh,st,tempmon,Max,Max2;
    scanf("%d %d %d",&h,&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&polesum[i]);
        pos[i]=i;
        current[i]=i;
        current2[i]=i;
        pos2[i]=i;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&num,&hh);
        stick[hh].push_back(num);
    }
    scanf("%d",&st);
    for(i=1;i<=h;i++){
        for(auto x:stick[i]){
            u=pos[x];
            v=pos[x+1];
            swap(current[u],current[v]);
            swap(pos[x],pos[x+1]);
        }
    }
    tempmon=st;
    Max=polesum[current[st]];
    Max2=Max;
    for(i=1;i<=h;i++){
        for(auto x:stick[i]){
            u=x;
            v=x+1;
            swap(current[u],current[v]);
            u=pos2[x];
            v=pos2[x+1];
            swap(current2[u],current2[v]);
            swap(pos2[x],pos2[x+1]);
        }
        tempmon=current2[st];
        Max=max(Max,polesum[current[tempmon+1]]);
        Max=max(Max,polesum[current[tempmon-1]]);
    }
    printf("%d\n",Max);
    if(Max!=Max2)printf("USE\n");
    else printf("NO\n");
}
/*
20 5 6
7 5 3 9 4
1 5
1 6
2 10
1 12
3 6
3 13
1
*/
