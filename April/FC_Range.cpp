/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long num,idx;
    bool operator<(const A&o)const{
        return num<o.num;
    }
};
A a[300100];
set<long long>now;
set<long long>::iterator idx,idx2;
int main()
{
	long long n,ans=0,i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
        scanf("%lld",&a[i].num);
        a[i].idx=i;
	}
	sort(a+1,a+n+1);
	now.insert(0);
	now.insert(n+1);
	for(i=n;i>0;i--){
        now.insert(a[i].idx);
        idx=now.lower_bound(a[i].idx);
        idx2=idx;
        idx--;
        idx2++;
        ans+=a[i].num*(a[i].idx-*idx)*(*idx2-a[i].idx);
	}
	now.clear();
	now.insert(0);
	now.insert(n+1);
	for(i=1;i<=n;i++){
        now.insert(a[i].idx);
        idx=now.lower_bound(a[i].idx);
        idx2=idx;
        idx--;
        idx2++;
        ans-=a[i].num*(a[i].idx-*idx)*(*idx2-a[i].idx);
	}
	printf("%lld\n",ans);
    return 0;
}
