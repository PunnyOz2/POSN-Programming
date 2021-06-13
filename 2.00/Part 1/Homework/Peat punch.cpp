/*
    TASK: Peat punch
    LANG: CPP
    AUTHOR: pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
stack< PII > st;
int a[100100];
int main()
{
    int i,pow,L,Q,h,power;
    scanf("%d %d",&L,&Q);
	for(i=0;i<L;i++){
        scanf("%d",&h);
        while(!st.empty() && st.top().first>=h)st.pop();
        if(st.empty()) power=0;
        else power=max(st.top().second,h-st.top().first);
        a[i]=power;
        st.push(make_pair(h,power));
	}
	sort(a,a+L);
	while(Q--){
        scanf("%d",&h);
        printf("%d\n",L -(upper_bound(a,a+L,h)-a));
	}


    return 0;
}
/*
5 2
1
3
4
2
3
2
1
*/
