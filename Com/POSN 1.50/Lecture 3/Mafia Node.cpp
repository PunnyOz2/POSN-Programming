/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int score,num;
    bool operator<(const A & o)const{
        if(score!=o.score) return score <o.score;
        else return num<o.num;
    }
};
priority_queue< A > he;
int a[1000100],mark[1000100];
int main()
{
    int i,n,l,r,x,y;
    char c;
    scanf("%d %d %d",&n,&l,&r);
    for(i=1;i<=n;i++)
        he.push({0,i});
    for(i=0;i<l+r;i++){
        scanf(" %c",&c);
        if(c=='L'){
            scanf("%d %d",&x,&y);
            a[y]++;
            he.push({a[y],y});
        }
        else if(c=='C'){
            scanf("%d %d",&x,&y);
            a[y]+=3; he.push({a[y],y});
        }
        else if(c=='R'){
            while(!he.empty() && mark[he.top().num])
                he.pop();
            printf("%d\n",he.top().num);
        }
        else if(c=='D'){
            while(!he.empty() && mark[he.top().num])
                he.pop();
            mark[he.top().num]=1;
            he.pop();
        }
    }

    return 0;
}
/*

*/
