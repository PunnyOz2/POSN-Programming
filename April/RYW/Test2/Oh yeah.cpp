/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],add[200100];
int main()
{
	int n,cnt=1,i,opr,x,y;
	long long sum=0;
	scanf("%d",&n);
	while(n--){
        scanf("%d",&opr);
        if(opr==1){
                scanf("%d %d",&x,&y);
            sum+=(x*y);
            add[x-1]+=y;
        }
        else if(opr==2){
            scanf("%d",&a[cnt]);
            add[cnt]=0;
            sum+=a[cnt++];
        }
        else{
            cnt--;
            sum-=(a[cnt]+add[cnt]);
            add[cnt-1]+=add[cnt];
        }
        printf("%lld %d\n",sum,cnt);
	}
    return 0;
}
