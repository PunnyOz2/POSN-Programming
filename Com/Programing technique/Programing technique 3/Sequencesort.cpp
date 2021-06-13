/*
    TASK: AncientPeatt
    LANG: CPP
    AUTHOR: Pun
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > a;
vector<int > b;
int main()
{
    int n,m,i,j,num;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&num);
            b.push_back(num);
        }
        a.push_back(b);
        b.clear();
    }
    sort(a.begin(),a.end());
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

