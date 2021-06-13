#include <bits/stdc++.h>
using namespace std;
char a[260];
int mark[260][260];
int play(int l,int r){
    int temp=0,u;
    if(mark[l][r]!=0)return mark[l][r];
    if(l==r){
        u=a[l]-'0';
        if(u==0)temp|=4;
        if(u==1)temp|=2;
        if(u==2)temp|=1;
        return mark[l][r]=temp;
    }
    int i,v;
    for(i=l;i<r;i++){
        u=play(l,i);
        v=play(i+1,r);
        if((u&4)==4 && (v&4)==4)temp|=1;//2
        if((u&4)==4 && (v&2)==2)temp|=2;//1
        if((u&4)==4 && (v&1)==1)temp|=4;//0
        if((u&2)==2 && (v&4)==4)temp|=1;//2
        if((u&2)==2 && (v&2)==2)temp|=2;//1
        if((u&2)==2 && (v&1)==1)temp|=2;//1
        if((u&1)==1 && (v&4)==4)temp|=2;//1
        if((u&1)==1 && (v&2)==2)temp|=1;//2
        if((u&1)==1 && (v&1)==1)temp|=2;//1
    }
    return mark[l][r]=temp;
}
int main(){
    int q=20,n,now;
    while(q--){
        scanf("%d",&n);
        scanf(" %s",a+1);
        now=play(1,n);
        if((now&4)==4)printf("yes\n");
        else printf("no\n");
        memset(mark,0,sizeof mark);
    }
}
/*
4 0201
5 10212
*/
