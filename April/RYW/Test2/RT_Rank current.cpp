/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
set<int> N;
set<int> ::iterator it;
int main()
{
	int q,opr,num;
	scanf("%d",&q);
	while(q--){
        scanf("%d %d",&opr,&num);
        if(opr==1){
            N.insert(num);
        }
        else{
            it=N.upper_bound(num);
            printf("%d\n",it);
        }
	}
    return 0;
}
