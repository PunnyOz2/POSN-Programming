#include<bits/stdc++.h>
using namespace std;
int ans[100000];
int a[400][400];
struct A{
    int i,j,id;
};
queue<A> q;
int main()
{
	int n,m,i,j,st,ii,jj,id;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
	}
	int cou=0;
	for(j=0;j<m;j++){
        if(a[0][j]==11 || a[0][j]==12 || a[0][j]==21 || a[0][j]==31){
            q.push({0,j,0});
            cou++;
        }
	    while(!q.empty()){
            ii=q.front().i,jj=q.front().j,st=q.front().id,q.pop();
            if(ii<0 || jj<0 || ii>=n || jj>=m)continue;
            ans[cou]++;
            if(a[ii][jj]==11){
                if(st==0)a[ii][jj]=0,q.push({ii,jj-1,3});
                if(st==1)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==12){
                if(st==0)a[ii][jj]=0,q.push({ii,jj+1,1});
                if(st==3)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==13){
                if(st==1)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii,jj-1,3});
            }
            else if(a[ii][jj]==14){
                if(st==3)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii,jj+1,1});
            }
            else if(a[ii][jj]==21){
                if(st==0)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==22){
                if(st==1)a[ii][jj]=0,q.push({ii,jj+1,1});
                if(st==3)a[ii][jj]=0,q.push({ii,jj-1,3});
            }
            else if(a[ii][jj]==31){
                if(st==0)a[ii][jj]=22,q.push({ii+1,jj,0});
                if(st==1)a[ii][jj]=21,q.push({ii,jj+1,1});
                if(st==2)a[ii][jj]=22,q.push({ii-1,jj,2});
                if(st==3)a[ii][jj]=21,q.push({ii,jj-1,3});
            }
	    }
	}
	for(j=0;j<m;j++){
        if(a[n-1][j]==13 || a[n-1][j]==14 || a[n-1][j]==21 || a[n-1][j]==31){
            q.push({n-1,j,2});
            cou++;
        }
	    while(!q.empty()){
            ii=q.front().i,jj=q.front().j,st=q.front().id,q.pop();
            if(ii<0 || jj<0 || ii>=n || jj>=m)continue;
            ans[cou]++;
            if(a[ii][jj]==11){
                if(st==0)a[ii][jj]=0,q.push({ii,jj-1,3});
                if(st==1)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==12){
                if(st==0)a[ii][jj]=0,q.push({ii,jj+1,1});
                if(st==3)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==13){
                if(st==1)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii,jj-1,3});
            }
            else if(a[ii][jj]==14){
                if(st==3)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii,jj+1,1});
            }
            else if(a[ii][jj]==21){
                if(st==0)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==22){
                if(st==1)a[ii][jj]=0,q.push({ii,jj+1,1});
                if(st==3)a[ii][jj]=0,q.push({ii,jj-1,3});
            }
            else if(a[ii][jj]==31){
                if(st==0)a[ii][jj]=22,q.push({ii+1,jj,0});
                if(st==1)a[ii][jj]=21,q.push({ii,jj+1,1});
                if(st==2)a[ii][jj]=22,q.push({ii-1,jj,2});
                if(st==3)a[ii][jj]=21,q.push({ii,jj-1,3});
            }
	    }
	}
	for(i=0;i<n;i++){
        if(a[i][0]==11 || a[i][0]==13 || a[i][0]==22 || a[i][0]==31){
            q.push({i,0,1});
            cou++;
        }
	    while(!q.empty()){
            ii=q.front().i,jj=q.front().j,st=q.front().id,q.pop();
            if(ii<0 || jj<0 || ii>=n || jj>=m)continue;
            ans[cou]++;
            if(a[ii][jj]==11){
                if(st==0)a[ii][jj]=0,q.push({ii,jj-1,3});
                if(st==1)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==12){
                if(st==0)a[ii][jj]=0,q.push({ii,jj+1,1});
                if(st==3)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==13){
                if(st==1)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii,jj-1,3});
            }
            else if(a[ii][jj]==14){
                if(st==3)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii,jj+1,1});
            }
            else if(a[ii][jj]==21){
                if(st==0)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==22){
                if(st==1)a[ii][jj]=0,q.push({ii,jj+1,1});
                if(st==3)a[ii][jj]=0,q.push({ii,jj-1,3});
            }
            else if(a[ii][jj]==31){
                if(st==0)a[ii][jj]=22,q.push({ii+1,jj,0});
                if(st==1)a[ii][jj]=21,q.push({ii,jj+1,1});
                if(st==2)a[ii][jj]=22,q.push({ii-1,jj,2});
                if(st==3)a[ii][jj]=21,q.push({ii,jj-1,3});
            }
	    }
	}
	for(i=0;i<n;i++){
        if(a[i][m-1]==12 || a[i][m-1]==14 || a[i][m-1]==22 || a[i][m-1]==31){
            q.push({i,m-1,3});
            cou++;
        }
	    while(!q.empty()){
            ii=q.front().i,jj=q.front().j,st=q.front().id,q.pop();
            if(ii<0 || jj<0 || ii>=n || jj>=m)continue;
            ans[cou]++;
            if(a[ii][jj]==11){
                if(st==0)a[ii][jj]=0,q.push({ii,jj-1,3});
                if(st==1)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==12){
                if(st==0)a[ii][jj]=0,q.push({ii,jj+1,1});
                if(st==3)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==13){
                if(st==1)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii,jj-1,3});
            }
            else if(a[ii][jj]==14){
                if(st==3)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii,jj+1,1});
            }
            else if(a[ii][jj]==21){
                if(st==0)a[ii][jj]=0,q.push({ii+1,jj,0});
                if(st==2)a[ii][jj]=0,q.push({ii-1,jj,2});
            }
            else if(a[ii][jj]==22){
                if(st==1)a[ii][jj]=0,q.push({ii,jj+1,1});
                if(st==3)a[ii][jj]=0,q.push({ii,jj-1,3});
            }
            else if(a[ii][jj]==31){
                if(st==0)a[ii][jj]=22,q.push({ii+1,jj,0});
                if(st==1)a[ii][jj]=21,q.push({ii,jj+1,1});
                if(st==2)a[ii][jj]=22,q.push({ii-1,jj,2});
                if(st==3)a[ii][jj]=21,q.push({ii,jj-1,3});
            }
	    }
	}
	printf("%d\n",cou);
	sort(ans+1,ans+cou+1);
	for(i=1;i<=cou;i++)printf("%d ",ans[i]);
    return 0;
}
