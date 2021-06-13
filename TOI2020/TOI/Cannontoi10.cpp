#include <bits/stdc++.h>
using namespace std;
struct A{
    int l,r;
};
stack<A> st;
int a[1000100];
int b[1010];
A ch[1010];
int main(){
    int n,m,k,l,i,temp,Max,cou,r,ll,sum,pos,pos2;
    scanf("%d %d %d %d",&n,&m,&k,&ll);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]++;
    }
    while(k--){
        for(i=0;i<m;i++){
            scanf("%d",&b[i]);
            b[i]++;
        }
        for(i=m-1;i>=0;i--){
            st.push({max(0,b[i]-ll),b[i]+ll});
        }
        temp=-1<<30;
        Max=-1;
        cou=0;
        sum=0;
        while(!st.empty()){
            l=st.top().l;
            r=st.top().r;
            st.pop();
            if(Max<l){
                cou++;
                ch[cou]={l,r};
                Max=r;
            }
            else{
                ch[cou].r=r;
                Max=r;
            }
        }
//        printf("%d\n",k);
//        for(i=1;i<=cou;i++){
//            printf("%d %d\n",ch[i].l,ch[i].r);
//        }
        for(i=1;i<=cou;i++){
            pos=upper_bound(a,a+n,ch[i].l-1)-a;
            pos2=upper_bound(a,a+n,ch[i].r)-a;
            sum+=pos2-pos;
        }
        printf("%d\n",sum);
    }
}
/*
3 2 4 100
100 300 500
200 1000
199 1000
200 600
1000 1001
*/
