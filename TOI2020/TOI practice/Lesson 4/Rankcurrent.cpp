#include<bits/stdc++.h>
using namespace std;
int a[300100],b[300100];
int bse[300100],fw[300100];
void update(int i){
    while(i<=300005){
        fw[i]++;
        i+=(i&-i);
    }
}
int query(int i){
    int sum=0;
    while(i>0){
        sum+=fw[i];
        i-=(i&-i);
    }
    return sum;
}
int main(){
    int q,i,idx,A,B,cou;
    scanf("%d",&q);
    cou=0;
    for(i=1;i<=q;i++){
        scanf("%d %d",&a[i],&b[i]);
        bse[cou++]=b[i];
    }
    sort(bse,bse+cou);
    for(i=1;i<=q;i++){
        A=a[i];
        B=b[i];
        idx=upper_bound(bse,bse+cou,B)-bse;
        if(A==1){
            update(idx);
        }
        else{
            printf("%d\n",query(idx));
        }
    }
    return 0;
}
/*
12
1 5
1 6
1 4
2 4
2 5
2 6
1 8
1 1
2 5
2 1
2 4
2 6
*/
