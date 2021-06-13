/*
    TASK:Oh my god
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[300003],b[100009];
queue<int>num[30];
long long fw[1000100];
void update(long long a){
    while(a<300010){
        fw[a]++;
        a+=a&-a;
    }
}
long long query(long long a){
    long long sum=0;
    while(a>0){
        sum+=fw[a];
        a-=a&-a;
    }
    return sum;
}
int main()
{
    long long opr,i,sum=0;
    scanf("%lld",&opr);
    scanf(" %s",a+1);
    scanf(" %s",b+1);
    long long lena=strlen(a+1);
    long long lenb=strlen(b+1);
    for(i=1;i<=lena;i++){
        num[a[i]-'a'].push(i);
    }
    //printf("%d\n",num[0].size());
    if(opr==0){
        for(i=1;i<=lenb;i++){
            if(!num[b[i]-'a'].empty()){
                sum+=num[b[i]-'a'].front();
                num[b[i]-'a'].pop();
            }
            else{
                printf("-1\n");
                return 0;
            }
        }
        printf("%lld\n",sum);
    }
    else{
        for(i=1;i<=lenb;i++){
            if(!num[b[i]-'a'].empty()){
                sum+=num[b[i]-'a'].front()-query(num[b[i]-'a'].front());
                update(num[b[i]-'a'].front());
                num[b[i]-'a'].pop();
            }
            else{
                printf("-1\n");
                return 0;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
/*
1
aabceddectfghaat
catbat
*/
