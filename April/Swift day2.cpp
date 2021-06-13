/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int bitmask[1<<15];
int main()
{
	int m,n,idx,now,i,cou,have;
	scanf("%d %d",&m,&n);
	idx=(1<<n)-1;
	for(i=1;i<=idx;i++)bitmask[i]=(1<<30);
	while(m--){
        scanf("%d",&cou);
        now=0;
        for(i=0;i<cou;i++){
            scanf("%d",&have);
            now|=(1<<(have-1));
        }
        for(i=0;i<=idx;i++){
            bitmask[i|now]=min(bitmask[i|now],bitmask[i]+1);
        }
	}
	printf("%d\n",bitmask[(1<<n)-1]);
    return 0;
}
/*
3 3
2 1 2
2 2 3
2 3 1
*/
