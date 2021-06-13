/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int>> Maxque,Minque;
int ans[1000100];
int main()
{
    int n,m,c,in,i,cou=0;
	scanf("%d %d %d",&n,&m,&c);
	for(i=1;i<=n;i++){
        scanf("%d",&in);
        while(!Maxque.empty() && Maxque.back().second<in)Maxque.pop_back();
        while(!Minque.empty() && Minque.back().second>in)Minque.pop_back();
        while(!Maxque.empty() && i-Maxque.front().first>=m)Maxque.pop_front();
        while(!Minque.empty() && i-Minque.front().first>=m)Minque.pop_front();
        Maxque.push_back({i,in});
        Minque.push_back({i,in});
        if(i>m-1 && Maxque.front().second-Minque.front().second<=c)ans[cou++]=i-m+1;
	}
	if(cou==0){printf("NONE\n");return 0;}
	for(i=0;i<cou;i++)
        printf("%d\n",ans[i]);
    return 0;
}
/*
7 2 0
0 1 1 2 3 2 2
*/
