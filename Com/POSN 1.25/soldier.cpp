/*
    TASK: Soldier
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,ran,tim;
    bool operator< (const A& o)const{
        if(ran!=o.ran) return ran < o.ran;
        return tim > o.tim;
    }
};
priority_queue< A > h;
int main()
{
    int n,r,i,num,id,ran;
    scanf("%d %d",&n,&r);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(num==1){
            scanf("%d %d",&id,&ran);
            h.push({id,ran,i});
        }
        else{
            if(h.empty()) printf("-1\n");
            else{
                printf("%d\n",h.top().id);
                h.pop();
            }
        }
    }

    return 0;
}
/*
6 5
2
1 20 4
1 11 4
2
1 3 5
2
*/
