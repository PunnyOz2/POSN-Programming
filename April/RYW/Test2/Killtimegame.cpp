/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int Q,i,n,t,cou=0,old;
	scanf("%d",&Q);
	while(Q--){
        scanf("%d",&n);
        cou=0;
        old=n+2;
        for(i=1;i<=n;i++){
            scanf("%d",&t);
            if(t<old)old=t,cou++,cou%=8;
        }
        if(cou==0)printf("Dr.Peartt\n");
        else if(cou==1)printf("Porn\n");
        else if(cou==2)printf("Born\n");
        else if(cou==3)printf("Nornt\n");
        else if(cou==4)printf("Borss\n");
        else if(cou==5)printf("Norn\n");
        else if(cou==6)printf("Girg\n");
        else if(cou==7)printf("Asira\n");
	}
    return 0;
}
/*
2
5
2 1 5 3 4
4
1 2 3 4
*/
