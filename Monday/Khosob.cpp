/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> idx,mp;
int fw[2000100];
void update(int a,int b){
    while(a<2000100){
        fw[a]+=b;
        a+=(a&-a);
    }
}
int query(int a){
    int sum=0;
    while(a>0){
        sum+=fw[a];
        a-=(a&-a);
    }
    return sum;
}
int main()
{
    char opr;
    int n,q,num,i,now,id,l,r,mid,temp;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        idx[num]=i;
        mp[idx[num]]=num;
        update(idx[num],1);
    }
    now=n+1;
    while(q--){
        scanf(" %c %d",&opr,&num);
        if(opr=='B'){
            mp[idx[num]]=0;
            update(idx[num],-1);
            idx[num]=now++;
            mp[idx[num]]=num;
            update(idx[num],1);
        }
        if(opr=='I'){
            l=0,r=1000001;
            while(l<r){
                mid=(l+r)/2;
                if(query(mid)>=num){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            printf("%d\n",mp[l]);
        }
        if(opr=='K'){
            temp=idx[num];
            printf("%d\n",query(temp));
        }
        if(opr=='P'){
            idx[num]=now++;
            mp[idx[num]]=num;
            update(idx[num],1);
        }
    }
    return 0;
}
/*
6 4
234 6 13 12 34 62
B 13
I 5
K 6
P 393
*/
