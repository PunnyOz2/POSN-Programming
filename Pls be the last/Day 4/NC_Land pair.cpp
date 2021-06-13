/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int a[55][55],temp[55][55];
int cnt[5000010];
int main()
{
    int n,i,j,ii,jj,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            temp[i][j]=a[i][j]+temp[i][j-1]+temp[i-1][j]-temp[i-1][j-1];
        }
//            printf("[%d %d %d]\n",i,j,temp[i][j]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(ii=1;ii<=i;ii++){
                for(jj=1;jj<=j;jj++){
                    cnt[ temp[i][j]-temp[ii-1][j]-temp[i][jj-1]+temp[ii-1][jj-1] + 2500000 ]++;
//                    if(i==1&&j==1)  printf("%d %d\n",temp[i][j],temp[i][j]-temp[ii-1][j]-temp[i][jj-1]+temp[ii-1][jj-1]);
                }
            }
            for(ii=i+1;ii<=n;ii++){
                for(jj=j+1;jj<=n;jj++){
                    ans+=cnt[ temp[ii][jj]+temp[i][j]-temp[i][jj]-temp[ii][j] + 2500000];
                }
            }
            for(ii=1;ii<=i;ii++){
                for(jj=1;jj<=j;jj++){
                    cnt[ temp[i][j]-temp[ii-1][j]-temp[i][jj-1]+temp[ii-1][jj-1] + 2500000 ]=0;
                }
            }
//            printf("%d %d %d\n",i,j,ans);
        }
    }
    memset(temp,0,sizeof temp);
//    printf("%d\n",ans);
    for(i=1;i<=n;i++){
        reverse(a[i]+1,a[i]+n+1);
        for(j=1;j<=n;j++)
            temp[i][j]=a[i][j]+temp[i][j-1]+temp[i-1][j]-temp[i-1][j-1];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(ii=1;ii<=i;ii++){
                for(jj=1;jj<=j;jj++){
                    cnt[ temp[i][j]-temp[ii-1][j]-temp[i][jj-1]+temp[ii-1][jj-1] + 2500000 ]++;
                }
            }
            for(ii=i+1;ii<=n;ii++){
                for(jj=j+1;jj<=n;jj++){
                    ans+=cnt[ temp[ii][jj]+temp[i][j]-temp[ii][j]-temp[i][jj]+2500000];
                }
            }
            for(ii=1;ii<=i;ii++){
                for(jj=1;jj<=j;jj++){
                    cnt[ temp[i][j]-temp[ii-1][j]-temp[i][jj-1]+temp[ii-1][jj-1] + 2500000 ]=0;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
3
1 2 3
2 3 4
3 4 8
*/
