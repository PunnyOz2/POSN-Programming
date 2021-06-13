/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200],mark[1200];
void play(int n){
    if(mark[n]==1)return;
    mark[n]=1;
    play(a[n]);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
	}
	mark[0]=1;
	int cou=0;
	for(i=1;i<=n;i++){
        if(a[i]!=i && mark[i]!=1)
            mark[i]=1,play(a[i]),cou++;
	}
	if(cou>2)printf("2");
	else printf("%d",cou);
    return 0;
}
/*
5
2 3 1 5 4
*/
