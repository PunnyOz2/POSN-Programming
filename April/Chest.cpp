/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
long long tim,st,en,i,m;
struct A{
    long long pos,f[10];
    bool operator<(const A&o)const{
        return pos<o.pos;
    }
};
A a[500000];
void check(long long time){
    if(time==2)a[i].f[2]+=1;
    if(time==3)a[i].f[3]+=1;
    if(time==4)a[i].f[2]+=2;
    if(time==5)a[i].f[5]+=1;
    if(time==6)a[i].f[2]+=1,a[i].f[3]+=1;
    if(time==7)a[i].f[7]+=1;
    if(time==8)a[i].f[2]+=3;
    if(time==9)a[i].f[3]+=2;
    if(time==10)a[i].f[2]+=1,a[i].f[5]+=1;
}
void de(long long time){
    if(time==2)a[i+m].f[2]-=1;
    if(time==3)a[i+m].f[3]-=1;
    if(time==4)a[i+m].f[2]-=2;
    if(time==5)a[i+m].f[5]-=1;
    if(time==6)a[i+m].f[2]-=1,a[i+m].f[3]-=1;
    if(time==7)a[i+m].f[7]-=1;
    if(time==8)a[i+m].f[2]-=3;
    if(time==9)a[i+m].f[3]-=2;
    if(time==10)a[i+m].f[2]-=1,a[i+m].f[5]-=1;
}
map<long long,long long> mp;
long long f[10];
int main()
{
	long long n;
	scanf("%lld %lld",&m,&n);
	for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&tim,&st,&en);
        a[i].pos=st;
        a[i+m].pos=en+1;
        check(tim);
        de(tim);
	}
	a[m+m+1].pos=n+1;
	long long cou;
	sort(a+1,a+1+m+m);
	for(i=1;i<=m+m;i++){
        f[2]+=a[i].f[2];
        f[3]+=a[i].f[3];
        f[5]+=a[i].f[5];
        f[7]+=a[i].f[7];
        while(a[i].pos==a[i+1].pos){
            i++;
            f[2]+=a[i].f[2];
            f[3]+=a[i].f[3];
            f[5]+=a[i].f[5];
            f[7]+=a[i].f[7];
        }
        cou=((f[2]+1)*(f[3]+1)*(f[5]+1)*(f[7]+1));
        mp[cou]+=a[i+1].pos-a[i].pos;
        //printf("%lld %lld\n",cou,mp[cou]);
	}
    long long ans,ans2;
	//printf("%lld %lld\n",mp.end().first,mp.end().second);
	//ans=mp.end().first,ans2=mp.end().second;
	for(auto x:mp){
        ans=x.first;
        ans2=x.second;
	}
	printf("%lld %lld\n",ans,ans2);
    return 0;
}
/*
5 10
3 0 4
2 2 3
5 4 7
6 7 9
2 3 3
*/
