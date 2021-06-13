/*
    TASK:
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int d,c;
    bool operator < (const A& o) const{
        return c <o.c; //Only swap c if c is less than the previous data
    }
};
A arr[100100];
int main()
{
    int n,i;
    double Max=0,sum=0,elec=0,ans1,ans2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&arr[i].d,&arr[i].c); //d will gets swap along with c
    sort(arr,arr+n); //Useful for tagging along a data
    sum = arr[0].d, elec = arr[0].c;
    Max = sum/elec,ans1=sum,ans2=elec;
    for(i=1;i<n;i++){
            sum+=arr[i].d;
            if(arr[i].c > elec) elec=arr[i].c;
            if(sum/elec > Max)
                Max = sum/elec,ans1=sum,ans2=elec;

    }
    printf("%.0lf %.0lf\n",ans1,ans2);

    return 0;
}

