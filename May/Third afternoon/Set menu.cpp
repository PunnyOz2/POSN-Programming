/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int cost[25],have[8],want[25],sum;
int main()
{
    int n,setco,i,need;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&cost[i]);
    }
    scanf("%d",&setco);
    for(i=1;i<=4;i++){
        scanf("%d",&have[i]);
    }
    scanf("%d",&need);
    int num;
    for(i=1;i<=need;i++){
        scanf("%d",&num);
        want[num]++;
    }
    int bonus;
    while(1){
        bonus=0;
        if(want[have[1]]>0){
            bonus+=cost[have[1]];
        }
        if(want[have[2]]>0){
            bonus+=cost[have[2]];
        }
        if(want[have[3]]>0){
            bonus+=cost[have[3]];
        }
        if(want[have[4]]>0){
            bonus+=cost[have[4]];
        }
        if(bonus>setco){
            sum+=setco;
            want[have[1]]--;
            want[have[2]]--;
            want[have[3]]--;
            want[have[4]]--;
        }
        else break;
    }
    for(i=1;i<=n;i++){
        if(want[i]>0)sum+=want[i]*cost[i];
    }
    printf("%d\n",sum);
    return 0;
}
/*
6
12 5 7 8 9 3
14
4 3 1 2
5
1 2 1 6 6
*/
