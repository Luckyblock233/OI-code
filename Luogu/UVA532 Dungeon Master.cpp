#include<bits/stdc++.h>
using namespace std;
const int N=110;
char a[N][N][N];
bool b[N][N][N];
int step[N][N][N];
int dx[6]= {0,0,0,0,1,-1};
int dy[6]= {0,0,1,-1,0,0};
int dz[6]= {1,-1,0,0,0,0};
struct node
{
	int x,y,z,t;
};
int h,n,m,nx,ny,nz;
queue<node> q;
node fa,son,S,E;
void bfs()
{
	while(!q.empty())
		{
			fa=q.front();
			q.pop();
			for(int i=0; i<6; i++)
				{
					nx=fa.x+dx[i];
					ny=fa.y+dy[i];
					nz=fa.z+dz[i];
					if(nx>=1&&nx<=h&&ny>=1&&ny<=n&&nz>=1&&nz<=m&&!b[nx][ny][nz]&&a[nx][ny][nz]!='#')
						{
							b[nx][ny][nz]=1;
							son.x=nx;
							son.y=ny;
							son.z=nz;
							son.t=fa.t+1;
							step[nx][ny][nz]=son.t;
							if(step[E.x][E.y][E.z])
								{
									while(!q.empty())q.pop();
								}
							q.push(son);
						}
				}
		}
}
int main()
{
	while(1)
		{
			cin>>h>>n>>m;
			if(h==0&&n==0&&m==0)return 0;
			for(int i=1; i<=h; i++)
				for(int j=1; j<=n; j++)
					for(int k=1; k<=m; k++)
						{
							cin>>a[i][j][k];
							b[i][j][k]=0;
							step[i][j][k]=0;
							if(a[i][j][k]=='S')
								{
									S.x=i;
									S.y=j;
									S.z=k;
									q.push(S);
									b[S.x][S.y][S.z]=1;
								}
							if(a[i][j][k]=='E')
								{
									E.x=i;
									E.y=j;
									E.z=k;
								}
						}
			bfs();
			if(step[E.x][E.y][E.z]>0)
			  printf("Escaped in %d minute(s).\n",step[E.x][E.y][E.z]);
			else 
			  printf("Trapped!\n") ;
		}
}
