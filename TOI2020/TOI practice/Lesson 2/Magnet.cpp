#include<bits/stdc++.h>
using namespace std;
pair<int,int> qq[100100];
int ev[200100],a[100100];
int main(){
    int n,m,q,cou,i,x,y,pos,old,temp,now,j,num,k,c;
    scanf("%d %d %d",&n,&m,&q);
    cou=0;
    for(i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        ev[cou++]=x,ev[cou++]=x+y;
    }
    sort(ev,ev+cou);
    for(i=0,j=0;i<cou;i=k){
        k=i+1;
        c=0;
        c++;
        while(ev[i]==ev[k])c++,k++;
        if(c%2==1)a[j++]=ev[i];
    }
    while(q--){
        scanf("%d",&num);
        if(num<a[0])printf("%d\n",a[0]-1);
        else if(num>=a[j-1])printf("%d\n",n-a[j-1]+1);
        else{
            i=upper_bound(a,a+j,num)-a;
            printf("%d\n",a[i]-a[i-1]);
        }
    }
    return 0;
}
/*
10 3 2
2 4
4 5
3 7
7
5

10 4 10
3 7
3 7
3 7
3 7
1
2
3
4
5
6
7
8
9
10
*/
