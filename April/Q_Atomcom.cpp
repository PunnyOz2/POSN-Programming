/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int dp[25][1200000];
int main()
{
	int q,cou,num,bit,i,j;
	scanf("%d",&q);
	dp[1][1] = 1;
	for(i=1;i<=20;i++){
	    for(j=1;j<1<<20;j++){
            if((j*2+1)<(1<<20)){
                dp[i+1][j*2+1] += dp[i][j];
            }
            if((j*2)<(1<<20)){
                dp[i+1][j*2] +=dp[i][j];
            }
            if((j*2-1)<(1<<20)){
                dp[i+1][j*2-1] += dp[i][j];
            }
	    }
	}
	while(q--){
        cou=0;
        scanf("%d %d",&num,&bit);
        num=abs(num);
        if(num>=(1<<20)){printf("0\n");continue;}
        if(num==0){printf("1\n");continue;}
        int cou=0;
        for(i=1;i<=bit;i++){
            cou+=dp[i][num];
        }
        printf("%d\n",cou);
	}
    return 0;
}
