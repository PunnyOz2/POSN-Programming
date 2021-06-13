/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
    bool operator<(const A&o)const{
        if(en!=o.en) return en<o.en;
        return st>o.st;
    }
};
A a[100100];
stack<A> st;
int main()
{
	int m,n,i,u,v,cou,tempst,tempen,sta,en;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++){
        scanf("%d %d",&a[i].st,&a[i].en);
	}
	sort(a,a+m);
	i=0;
	while(i<m){
        sta=a[i].st,en=a[i].en;
        while(!st.empty()){
            tempst=st.top().st;
            tempen=st.top().en;
            st.pop();
            if(!st.empty() && sta<=st.top().en);
            else if(!st.empty() && sta==st.top().en+1);
            else if(sta<=tempst);
            else {st.push({tempst,tempen});break;}
        }
        st.push({sta,en});
        i++;
	}
	//while(!st.empty())printf("%d %d\n",st.top().st,st.top().en),st.pop();
	printf("%d\n",st.size());
    return 0;
}
/*
4 7
1 2
3 4
5 6
2 7
*/
