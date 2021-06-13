/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
#include "sockslib.h"
using namespace std;
vector<int> g;
void matchs(int a, int b) {
    match(a, b);
}
int asks(vector<int> &a){
    int num = ask(a);
    return num;
}
vector<int> temp;
int main()
{
    int n=num(),i,l,r,mid,ask1,ask2,j;
    for(i=1;i<=2*n;i++)g.push_back(i);
    for(i=0;i<n;i++){
        l=1,r=g.size()-1;
        while(l<r){
            temp.clear();
            mid=(l+r)/2;
            for(j=l;j<=mid;j++){
                temp.push_back(g[j]);
            }
            ask1=asks(temp);
            temp.push_back(g[0]);
            ask2=asks(temp);
            if(ask1==ask2)r=mid;
            else l=mid+1;
        }
        matchs(g[0],g[l]);
        g.erase(find(g.begin(), g.end(), g[l]));
        //g.resize(g.size()-1);
        g.erase(find(g.begin(), g.end(), g[0]));
        //g.resize(g.size()-1);
        //mark[g[i]]=mark[g[l]]=1;
    }
    return 0;
}
