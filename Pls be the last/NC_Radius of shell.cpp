/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[400000];
deque<int> Ma;
int lef[400000],righ[400000];
int main()
{
    int q,n,i,Min;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1+n;i<=n+n;i++){
            scanf("%d",&a[i]);
            a[i+n]=a[i-n]=a[i];
        }
        for(i=1;i<=n+n;i++){
            while(!Ma.empty() && a[Ma.back()]<=a[i])Ma.pop_back();
            if(Ma.empty())lef[i]=1<<30;
            else lef[i]=i-Ma.back()-1;
            Ma.push_back(i);
        }
        while(!Ma.empty())Ma.pop_back();
        for(i=n+n+n;i>0;i--){
            while(!Ma.empty() && a[Ma.back()]<=a[i])Ma.pop_back();
            if(Ma.empty())righ[i]=1<<30;
            else righ[i]=Ma.back()-i-1;
            Ma.push_back(i);
        }
        while(!Ma.empty())Ma.pop_back();
        for(i=n+1;i<=n+n;i++){
            printf("%d ",min((n-1)/2,min(righ[i],lef[i])));
        }
        printf("\n");
    }
    return 0;
}
/*
2
5
3 4 2 5 1
*/
