/*
    TASK: Van booking
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,day;
    bool operator< (const A& o)const{
        if(day!=o.day) return day > o.day;
        return id > o.id;
    }
};
priority_queue< A > he;
int main()
{
    int n,k,i;
    A temp;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++)
        he.push({i,0});
    while(n--){
        scanf("%d",&i);
        temp = he.top();
        printf("%d\n",temp.id);
        temp.day += i;
        he.pop();
        he.push(temp);
    }

    return 0;
}
/*
6 3
3
1
2
2
2
1
*/
