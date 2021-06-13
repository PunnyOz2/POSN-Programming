#include<bits/stdc++.h>
using namespace std;
char res[50];
int main(){
    int t,a,b,mid,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&a,&b,&n);
        while(a<=b){
            mid=(a+b)/2;
            printf("%d\n",mid);
            fflush(stdout);
            scanf(" %s",res);
            if(res[0]=='C'){
                break;
            }
            if(res[4]=='S'){
                a=mid+1;
            }
            if(res[4]=='B'){
                b=mid-1;
            }
        }
    }
}
