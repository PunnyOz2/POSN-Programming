/*
    TASK: Peatt Markets
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue< int > h;
int main()
{
    int q,n,m,k,num,opr,sum;
    long long ans;
	scanf("%d",&q);
	while(q--){
        scanf("%d %d %d",&n,&m,&k);
        sum=ans=0;
        while(n--){
            scanf("%d",&num);
            h.push(-num);
        }
        while(m--){
            scanf("%d",&opr);
            if(opr==1){
                scanf("%d",&num);
                h.push(-(num-sum));
            }
            else if(opr==2)
                sum+=k;
            else if(opr==3){
                if(!h.empty())
                    h.pop();
            }
        }
        printf("%d ",h.size());
        while(!h.empty()){
            ans+= -h.top()+sum;
            h.pop();
        }
        printf("%lld\n",ans);
	}
    return 0;
}
/*
1
5 6 20
100 150 130 200 1000
3
3
1 160
2
1 158
3
*/
