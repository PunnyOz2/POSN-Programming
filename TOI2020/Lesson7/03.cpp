#include<bits/stdc++.h>
using namespace std;
char a[120];
int cou[26];
vector<int> couu[26];
int main(){
    int q,n,lena,ans,i,j,temp;
    scanf("%d",&q);
    while(q--){
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf(" %s",a);
            lena=strlen(a);
            temp=0;
            for(j=0;j<lena;j++){
                temp|=1<<(a[j]-'a');
            }
            cou[i]=temp;
            if(temp==((1<<26)-1))ans++;
        }
        for(i=1;i<=n;i++){
            for(j=i;j>=1;j--){
                if(j==1 && i!=n+1)couu[j].push_back(cou[i]);
                else{
                    for(auto x:couu[j-1]){
                        temp=cou[i]|x;
                        if(temp==((1<<26)-1))ans++;
                        couu[j].push_back(temp);
                    }
                }
            }
        }
        printf("%d\n",ans);
        for(i=1;i<=n;i++){
            //for(auto x:couu[i])printf("%d %d\n",i,__builtin_popcount(x));
            couu[i].clear();
        }
    }
    return 0;
}
/*
2
3
abcdefghijklmnopqrstuvwx
abcdefghijklmnopqrstuvwxy
abcdefghijklmnopqrstuvwxyz
9
the
quick
brown
fox
jumps
over
a
lazy
dog
*/
