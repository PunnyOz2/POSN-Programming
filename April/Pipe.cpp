/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
int ans[100000];
int a[400][400];
int main()
{
	int n,m,i,j,st,ii,jj;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
	}
	int cou=0;
	for(j=0;j<m;j++){
        if(a[0][j]==12){
            st=1;
            ii=0,jj=j+1;
            ans[++cou]=1;
            a[i][j]=0;
        }
        if(a[0][j]==21){
            st=0;
            ii=1,jj=j;
            ans[++cou]=1;
            a[i][j]=0;
        }
        if(a[0][j]==31){
            st=0;
            ii=1,jj=j;
            ans[++cou]=1;
            a[i][j]=22;
        }
        if(a[0][j]==11){
            st=3;
            ii=0,jj=j-1;
            ans[++cou]=1;
            a[i][j]=0;
        }
            while(ii<n && jj<m && ii>=0 && jj>=0){
                if(a[ii][jj]==12){
                    a[ii][jj]=0;
                    if(st==0)jj+=1,st=1;
                    else if(st==3)ii-=1,st=2;
                }
                else if(a[ii][jj]==11){
                    a[ii][jj]=0;
                    if(st==1)ii-=1,st=2;
                    else if(st==0)jj-=1,st=3;
                }
                else if(a[ii][jj]==13){
                    a[ii][jj]=0;
                    if(st==1)ii+=1,st=0;
                    else if(st==2)jj-=1,st=3;
                }
                else if(a[ii][jj]==14){
                    a[ii][jj]=0;
                    if(st==3)ii+=1,st=0;
                    else if(st==2)jj+=1,st=1;
                }
                else if(a[ii][jj]==21){
                    a[ii][jj]=0;
                    if(st==0)ii+=1;
                    else if(st==2)ii-=1;
                }
                else if(a[ii][jj]==22){
                    a[ii][jj]=0;
                    if(st==1)jj+=1;
                    else if(st==3)jj-=1;
                }
                else if(a[ii][jj]==31){
                    if(st==0)a[ii][jj]=22,ii++;
                    else if(st==2)a[ii][jj]=22,ii-=1;
                    else if(st==1)a[ii][jj]=21,jj+=1;
                    else if(st==3)a[ii][jj]=21,jj-=1;
                }
                ans[cou]++;
            }
	}
	for(j=0;j<m;j++){
        if(a[n-1][j]==13){
            st=3;
            ii=n-1,jj=j-1;
            ans[++cou]=1;
            a[i][j]=0;
        }
        if(a[n-1][j]==21){
            st=2;
            ii=n-2,jj=j;
            ans[++cou]=1;
            a[i][j]=0;
        }
        if(a[n-1][j]==31){
            st=2;
            ii=n-2,jj=j;
            ans[++cou]=1;
            a[i][j]=22;
        }
        if(a[n-1][j]==14){
            st=3;
            ii=n-1,jj=j+1;
            ans[++cou]=1;
            a[i][j]=0;
        }
            if(a[ii][jj]==12){
                    a[ii][jj]=0;
                    if(st==0)jj+=1,st=1;
                    else if(st==3)ii-=1,st=2;
                }
                else if(a[ii][jj]==11){
                    a[ii][jj]=0;
                    if(st==1)ii-=1,st=2;
                    else if(st==0)jj-=1,st=3;
                }
                else if(a[ii][jj]==13){
                    a[ii][jj]=0;
                    if(st==1)ii+=1,st=0;
                    else if(st==2)jj-=1,st=3;
                }
                else if(a[ii][jj]==14){
                    a[ii][jj]=0;
                    if(st==3)ii+=1,st=0;
                    else if(st==2)jj+=1,st=1;
                }
                else if(a[ii][jj]==21){
                    a[ii][jj]=0;
                    if(st==0)ii+=1;
                    else if(st==2)ii-=1;
                }
                else if(a[ii][jj]==22){
                    a[ii][jj]=0;
                    if(st==1)jj+=1;
                    else if(st==3)jj-=1;
                }
                else if(a[ii][jj]==31){
                    if(st==0)a[ii][jj]=22,ii++;
                    else if(st==2)a[ii][jj]=22,ii-=1;
                    else if(st==1)a[ii][jj]=21,jj+=1;
                    else if(st==3)a[ii][jj]=21,jj-=1;
                }
                ans[cou]++;
            }
	for(i=0;i<n;i++){
            if(a[i][0]==11){
                st=2;
                ii=i-1,jj=0;
                ans[++cou]=1;
                a[i][j]=0;
            }
            if(a[i][0]==13){
                st=0;
                ii=i+1,jj=0;
                ans[++cou]=1;
                a[i][j]=0;
            }
            if(a[i][0]==22){
                st=1;
                ii=i,jj=1;
                ans[++cou]=1;
                a[i][j]=0;
            }
            if(a[i][0]==31){
                st=1;
                ii=i,jj=1;
                ans[++cou]=1;
                a[i][j]=21;
            }
            if(a[ii][jj]==12){
                    a[ii][jj]=0;
                    if(st==0)jj+=1,st=1;
                    else if(st==3)ii-=1,st=2;
                }
                else if(a[ii][jj]==11){
                    a[ii][jj]=0;
                    if(st==1)ii-=1,st=2;
                    else if(st==0)jj-=1,st=3;
                }
                else if(a[ii][jj]==13){
                    a[ii][jj]=0;
                    if(st==1)ii+=1,st=0;
                    else if(st==2)jj-=1,st=3;
                }
                else if(a[ii][jj]==14){
                    a[ii][jj]=0;
                    if(st==3)ii+=1,st=0;
                    else if(st==2)jj+=1,st=1;
                }
                else if(a[ii][jj]==21){
                    a[ii][jj]=0;
                    if(st==0)ii+=1;
                    else if(st==2)ii-=1;
                }
                else if(a[ii][jj]==22){
                    a[ii][jj]=0;
                    if(st==1)jj+=1;
                    else if(st==3)jj-=1;
                }
                else if(a[ii][jj]==31){
                    if(st==0)a[ii][jj]=22,ii++;
                    else if(st==2)a[ii][jj]=22,ii-=1;
                    else if(st==1)a[ii][jj]=21,jj+=1;
                    else if(st==3)a[ii][jj]=21,jj-=1;
                }
                ans[cou]++;
            }

	for(i=0;i<n;i++){
            if(a[i][m-1]==12){
                st=2;
                ii=i-1,jj=m-1;
                ans[++cou]=1;
                a[i][j]=0;
            }
            if(a[i][m-1]==14){
                st=0;
                ii=i+1,jj=m-1;
                ans[++cou]=1;
                a[i][j]=0;
            }
            if(a[i][0]==22){
                st=3;
                ii=i,jj=m-2;
                ans[++cou]=1;
                a[i][j]=0;
            }
            if(a[i][0]==31){
                st=3;
                ii=i,jj=m-2;
                ans[++cou]=1;
                a[i][j]=21;
            }
            if(a[ii][jj]==12){
                    a[ii][jj]=0;
                    if(st==0)jj+=1,st=1;
                    else if(st==3)ii-=1,st=2;
                }
                else if(a[ii][jj]==11){
                    a[ii][jj]=0;
                    if(st==1)ii-=1,st=2;
                    else if(st==0)jj-=1,st=3;
                }
                else if(a[ii][jj]==13){
                    a[ii][jj]=0;
                    if(st==1)ii+=1,st=0;
                    else if(st==2)jj-=1,st=3;
                }
                else if(a[ii][jj]==14){
                    a[ii][jj]=0;
                    if(st==3)ii+=1,st=0;
                    else if(st==2)jj+=1,st=1;
                }
                else if(a[ii][jj]==21){
                    a[ii][jj]=0;
                    if(st==0)ii+=1;
                    else if(st==2)ii-=1;
                }
                else if(a[ii][jj]==22){
                    a[ii][jj]=0;
                    if(st==1)jj+=1;
                    else if(st==3)jj-=1;
                }
                else if(a[ii][jj]==31){
                    if(st==0)a[ii][jj]=22,ii++;
                    else if(st==2)a[ii][jj]=22,ii-=1;
                    else if(st==1)a[ii][jj]=21,jj+=1;
                    else if(st==3)a[ii][jj]=21,jj-=1;
                }
                ans[cou]++;

	}
	printf("%d\n",cou);
	for(i=1;i<=cou;i++)printf("%d ",ans[i]);
    return 0;
}
